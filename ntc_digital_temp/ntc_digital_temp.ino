const byte NTCPin = A0;  // Analog input pin connected to the voltage divider

// Thermistor and circuit constants
#define SERIESRESISTOR      10000.0   // Series resistor value (Ohms)
#define NOMINAL_RESISTANCE  10000.0   // Resistance of thermistor at 25 °C (Ohms)
#define NOMINAL_TEMPERATURE 25.0      // Nominal temperature value (°C)
#define BCOEFFICIENT        3950.0    // Beta coefficient of the thermistor

void setup() {
  Serial.begin(9600);
  Serial.println("NTC Thermistor Temperature Measurement");
  delay(500);
}

void loop() {
  int ADCvalue = analogRead(NTCPin);

  Serial.print("Analog reading: ");
  Serial.print(ADCvalue);
  Serial.print(" -> ");

  // Convert ADC value to resistance
  float Resistance = SERIESRESISTOR * (1023.0 / ADCvalue - 1.0);

  Serial.print(Resistance);
  Serial.println(" Ohms");

  // Apply the Steinhart–Hart equation
  float steinhart;
  steinhart = Resistance / NOMINAL_RESISTANCE;          // (R/Ro)
  steinhart = log(steinhart);                           // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                            // 1/B * ln(R/Ro)
  steinhart += 1.0 / (NOMINAL_TEMPERATURE + 273.15);    // + (1/To)
  steinhart = 1.0 / steinhart;                          // Invert
  steinhart -= 273.15;                                  // Convert to °C

  Serial.print("Temperature: ");
  Serial.print(steinhart);
  Serial.println(" °C");

  delay(1000);
}
