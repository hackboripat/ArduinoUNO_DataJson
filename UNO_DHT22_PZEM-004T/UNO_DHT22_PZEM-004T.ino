#include <PZEM004Tv30.h>
#include "DHT.h"
#include <ArduinoJson.h>

#define dht22_pin 4     // Digital pin connected to the DHT sensor
#define DHT22TYPE DHT22   // DHT 22  (AM2302), AM2321


PZEM004Tv30 pzem(2, 3);

DHT dht(dht22_pin, DHT22TYPE);

DynamicJsonDocument doc(1024);

float temperature = 0; float humidity = 0;

float voltage = 0; float current = 0;


void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {

  pzem_read();
  dht22_read();

  doc["temp"] = temperature;
  doc["rh"]   = humidity;
  doc["voltage"] = voltage;
  doc["current"] = current;

  serializeJson(doc, Serial);
  Serial.println();

  delay(1000);
}

void pzem_read()
{
  float voltage_in = pzem.voltage();    
  if(voltage != NAN){
    voltage = voltage_in;
  } else {
    voltage = 0;
  }

  float current_in = pzem.current();
  if(current != NAN){
    current = current_in;
  } else {
    current = 0;
  }
}

void dht22_read()
{
  float h = dht.readHumidity(); 
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (!isnan(h) || !isnan(t)) {

    temperature = t; humidity  = h;
  }else{

    temperature = 0; humidity  = 0;    
  }

  
}