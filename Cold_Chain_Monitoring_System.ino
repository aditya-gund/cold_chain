//                              ****************************************************************** 
//                              |                Cold Chain Monitoring System                    | 
//                              |                               by                               |   
//                              |                                                                |    
//                              |                          ADITYA GUND                           |   
//                              |                                                                |
//                              ****************************************************************** 


#define BLYNK_TEMPLATE_ID ""
#define BLYNK_DEVICE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_PRINT Serial

// Libraries required to install
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

//Define your Wi-Fi name and Password
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "WIFI_NAME";  
char pass[] = "WIFI_PASSWORD";

float t_threshold = 31.5;     // We will send an alert if the temp exceeds this value
bool alert_sent = false;      // Flag to track if an alert has been sent for an over-temp event

//Define the data related to DHT22 Sensor
#define DHTPIN 2          
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);

//Define the data related to Neo 6M GPS tracker
//GPS RX to D1 & GPS TX to D2 and Serial Connection
const int RXPin = 4, TXPin = 5;
const uint32_t GPSBaud = 9600; 
SoftwareSerial gps_module(RXPin, TXPin);
TinyGPSPlus gps; 
WidgetMap myMap(V0); //V0 - virtual pin for Map
BlynkTimer timer;
//Variable  to store the speed, no. of satellites, direction
float gps_speed;
float no_of_satellites;
String satellite_orientation;


//unsigned int move_index;         
unsigned int move_index = 1; 

//Humidity and Temperature Sensor 
void take_DHT_reading()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity    = ");
  Serial.println(h);
  Serial.print("Temperature = ");
  Serial.println(t);
  Serial.println();
  
  // Send the readings to Blynk...
  Blynk.virtualWrite(V6, h);
  Blynk.virtualWrite(V7, t);

  if(t > t_threshold && alert_sent == false)
  {
    // we get here if the temp is above the threshold and no alert has been sent yet for this over-temp situation

    Blynk.logEvent("over_temperature_alert",  String("The temperature is above 30° C\n Temperature is ") + t); // trigger the notification      
    Blynk.email("adityagundg14@gmail.com" , String("Alert! The temperature is above 30° C\n Temperature is ") + t); 
    alert_sent = true; // set the flag to indicate that an alert has been sent for this over-temp situation
    Serial.println("Blynk Alert Notification sent!");
    Serial.println();
  }
  else if(t <= t_threshold && alert_sent == true) 
  {
    
    alert_sent = false; // reset the flag so that a future over-temp situation will trigger an alert
     
    Serial.println("Temperature is now equal to or below the threshold");
    Serial.println("New over-temperature events will trigger a new alert notification");
    Serial.println();                  
  }
}

//GPS Tracking Neo 6M Sensor
void checkGPS(){
  if (gps.charsProcessed() < 10)
  {
    Serial.println(("No GPS detected: check wiring."));
      Blynk.virtualWrite(V4, "GPS ERROR");  
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, take_DHT_reading);
  Serial.println();
  gps_module.begin(GPSBaud);
  timer.setInterval(2500L, checkGPS); 
}
void loop() {
  // put your main code here, to run repeatedly:
    while (gps_module.available() > 0) 
  {
    //displays information every time a new sentence is correctly encoded.
    if (gps.encode(gps_module.read()))
    displayInfo();
  }
  Blynk.run();
  timer.run();

}

void displayInfo()
{
  if (gps.location.isValid()) 
  {
    //Storing the Latitude. and Longitude
    float latitude = (gps.location.lat());
    float longitude = (gps.location.lng()); 
    
    //Send to Serial Monitor for Debugging
    Serial.print("LATITUDE:  ");
    Serial.println(latitude, 6);  // float to x decimal places
    Serial.print("LONGITUDE: ");
    Serial.println(longitude, 6);
    
    Blynk.virtualWrite(V1, String(latitude, 6));   
    Blynk.virtualWrite(V2, String(longitude, 6));  
    myMap.location(move_index, latitude, longitude, "GPS_Location");
    
    //get speed
    gps_speed = gps.speed.kmph();
    Blynk.virtualWrite(V3, gps_speed);
       
    //get number of satellites
    no_of_satellites = gps.satellites.value();
    Blynk.virtualWrite(V4, no_of_satellites);

    // get the satellite orientation/direction
    satellite_orientation = TinyGPSPlus::cardinal(gps.course.value());
    Blynk.virtualWrite(V5, satellite_orientation);
  }
  
  Serial.println();
}
