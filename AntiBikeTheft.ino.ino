#define BLYNK_TEMPLATE_ID "TMPL9po0ga_T" 
#define BLYNK_TEMPLATE_NAME "GMIT BIKETHEFT" 
#define BLYNK_AUTH_TOKEN "flgdL
8VrmKPS7xymAmkqVZxa5WIxQ5G" 
#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h> 
Implementation of Anti Bike Theft IoT using Arduino  
 
#include <BlynkSimpleEsp8266.h> 
#include <SoftwareSerial.h> 
#include <Wire.h> 
 
 
char auth[] = "flgdL-8VrmKPS7xymAmkqVZxa5WIxQ5G"; 
char ssid[] = "GMITBIKE"; 
char pass[] = "DEMO2021"; 
 
int GLED= D5;  
int RLED= D7; 
int BUZ= D2; 
 
const int ANALOG_IN_PIN = A0; 
float adc_voltage = 0.0; 
float in_voltage = 0.0; 
  
// Floats for resistor values in divider (in ohms) 
float R1 = 30000.0; 
float R2 = 7500.0;  
  
// Float for Reference Voltage 
float ref_voltage = 5.0; 
  
// Integer for ADC value 
int adc_value = 0; 
 
  
BlynkTimer timer; 
 
void setup() { 
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, pass); 
  pinMode(GLED, OUTPUT); 
  pinMode(RLED, OUTPUT); 
  pinMode(BUZ, OUTPUT); 
} 
 
void loop()  
{ 
 //////VOLTAGE SENSOR 
adc_value = analogRead(ANALOG_IN_PIN); 
adc_voltage  = (adc_value * ref_voltage) / 1024.0;  
in_voltage = adc_voltage / (R2/(R1+R2)) ;  
Serial.print("Input Voltage = "); 
Serial.println(in_voltage, 2); 
delay(500); 
Blynk.virtualWrite(V0, in_voltage); 
 
    
if(in_voltage>2) 
{ 
Blynk.virtualWrite(V1, "ALERT..!, BIKE IS BEEN STARTED"); 
    digitalWrite(RLED, HIGH); 
    digitalWrite(BUZ, HIGH); 
    digitalWrite(GLED, LOW); 
 
} 
else 
{ 
Blynk.virtualWrite(V1, "BIKE IS OFF"); 
    digitalWrite(RLED, LOW); 
    digitalWrite(BUZ, LOW); 
    digitalWrite(GLED, HIGH); 
} 
 
 
 
if(in_voltage>2) 
{ 
  Blynk.logEvent("alert","Alert...! Bike is Started..");  
  } 
   
} void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
