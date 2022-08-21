int LED1 = 2;      // Assign LED1 to pin GPIO2
int LED2 = 16;     // Assign LED1 to pin GPIO16

void setup() {
  // initialize GPIO2 and GPIO16 as an output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

// the loop function runs forever

void loop() {
  digitalWrite(LED1, LOW);     // turn the LED off
  digitalWrite(LED2, HIGH);
  delay(1000);                // wait for a second
  digitalWrite(LED1, HIGH);  // turn the LED on
  digitalWrite(LED2, LOW);
  delay(1000);               // wait for a second
}
