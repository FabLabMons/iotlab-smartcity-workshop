static const uint8_t sensorTriggerPin = 3;
static const uint8_t sensorEchoPin = 4;

static uint8_t distanceCm = 255;

const unsigned TX_INTERVAL = 3;

void setup() {
  Serial.begin(115200);
  Serial.println(F("Starting"));

  pinMode(sensorTriggerPin, OUTPUT);
  pinMode(sensorEchoPin, INPUT);

}

void loop() {
  digitalWrite(sensorTriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorTriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorTriggerPin, LOW);

  long duration = pulseIn(sensorEchoPin, HIGH);
  distanceCm = duration * 0.034 / 2;

  Serial.print(F("Distance: "));
  Serial.print(distanceCm);
  Serial.println("cm");

  delay(TX_INTERVAL * 1000);
}
