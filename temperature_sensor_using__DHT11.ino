#include<DHT.h>

#define DHT11_Pin A0
DHT dht11(DHT11_Pin, DHT11);

void setup() 
{
  Serial.begin(9600);
  dht11.begin();

}

void loop() 
{
  float humi = dht11.readHumidity();
  float tempC = dht11.readTemperature();
  // read temperature as Fahrenheit
  float tempF = dht11.readTemperature(true);

  // check if any reads failed
  if (isnan(humi) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT11 sensor!");
  } else {
    Serial.print("DHT11# Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  "); 

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C ~ ");
    Serial.print(tempF);
    Serial.println("°F");
  }
  delay(1000);
}
