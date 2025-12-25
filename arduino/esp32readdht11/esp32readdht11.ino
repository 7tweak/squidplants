#include <DHT.h>

#define DHT_PIN 12
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }  // wait for serial on USB CDC
  
  Serial.println("DHT11 Temperature & Humidity Monitor");
  Serial.println("-------------------------------------");
  
  dht.begin();
  delay(2000);  // DHT11 needs ~1-2s to stabilize after power-on
}

void loop() {
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);

  if (isnan(humidity) || isnan(tempC)) {
    Serial.println("Error: Failed to read from DHT11");
  } else {
    Serial.printf("Temp: %.1f°C (%.1f°F)  |  Humidity: %.1f%%\n", tempC, tempF, humidity);
  }

  delay(2000);  // 0.5 Hz = 2 second interval
}