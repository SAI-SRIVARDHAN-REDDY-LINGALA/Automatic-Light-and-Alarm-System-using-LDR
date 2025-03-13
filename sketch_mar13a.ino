const int LDR_PIN = A0;   // LDR connected to Analog Pin A0
const int BUZZER_PIN = 8; // Buzzer connected to Digital Pin 8
const int LED_PIN = 9;    // LED connected to Digital Pin 9

void setup() {
      Serial.begin(9600);          // Start serial communication
    pinMode(BUZZER_PIN, OUTPUT); // Set Buzzer as output
    pinMode(LED_PIN, OUTPUT);    // Set LED as output
    Serial.begin(9600);          // Start serial communication
}


// INSTEAD OF USING SEPARATE FUNCTION FOR BUZZER RING WE USE ITS LIBRARY TO RING AT
// SPECIFIC FREQUECNY 

void loop() {
    int ldrValue = analogRead(LDR_PIN); // Read LDR sensor value
    Serial.println(ldrValue);           // Print value to Serial Monitor

    if (ldrValue < 300) { // If it's dark
        digitalWrite(LED_PIN, HIGH);  // Turn ON LED
    } else {
        digitalWrite(LED_PIN, LOW);   // Turn OFF LED
    }

    if (ldrValue > 700) { // If it's bright
        tone(BUZZER_PIN, 1000); // Turn ON Buzzer at 1000Hz frequency
    } else {
        noTone(BUZZER_PIN); // Turn OFF Buzzer
    }

    delay(1000); // Wait for 1 second
}