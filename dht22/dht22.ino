#include <DHT.h>

#define DHTPIN 2        // DATA -> D2
#define DHTTYPE DHT22   // or AM2302

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT22 test starting...");
}

void loop() {
  delay(2000);  // about 0.5 Hz recommended
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT22!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %  Temperature: ");
    Serial.print(t);
    Serial.println(" °C");
  }
}

