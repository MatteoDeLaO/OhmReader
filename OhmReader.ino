// Define the pins for measuring voltage
int knownResistor = 10000;  // Value of the known resistor in ohms (10kΩ, for example)

void setup() {
  // Start the Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Read the analog voltage across the unknown resistor
  int sensorValue = analogRead(A0);
  
  // Convert the ADC value to a voltage (0-1023 -> 0-5V)
  float voltageOut = sensorValue * (5.0 / 1023.0);
  
  // Apply the voltage divider formula to calculate the unknown resistor
  float resistanceUnknown = knownResistor * (voltageOut / (5.0 - voltageOut));
  
  // Print the calculated resistance to the Serial Monitor
  Serial.print("Measured Voltage (V_out): ");
  Serial.print(voltageOut, 3);  // Print with 3 decimal places
  Serial.print(" V, Unknown Resistor: ");
  Serial.print(resistanceUnknown, 0);  // Print the resistance value without decimals
  Serial.println(" ohms");
  
  // Delay before taking the next reading
  delay(1000);
}
