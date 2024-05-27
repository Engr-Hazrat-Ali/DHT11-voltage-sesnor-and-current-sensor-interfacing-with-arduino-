const int analog_read=A0;

void setup() {
 Serial.begin(115200);
 pinMode(analog_read,INPUT);


}

void loop() {
 float read=analogRead(A1);
Serial.println(read/40.5);


delay(1000);
}
