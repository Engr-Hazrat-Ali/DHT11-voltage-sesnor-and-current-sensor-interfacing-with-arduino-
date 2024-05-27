
const int volt_read=A1;
const int curr=A0;
#include "dht.h"
#define dht_apin A2 // Analog Pin sensor is connected to Arduino
dht DHT;
void setup() {
  Serial.begin(9600);
  pinMode(volt_read, INPUT);
  pinMode(curr, INPUT);

}

void loop() {
unsigned int x=0;
float read=analogRead(A1);
Serial.print("voltage : ");
Serial.print(read/53.5);
Serial.print("volts");

float AcsValue=0.0,Samples=0.0,AvgAcs=0.0,AcsValueF=0.0;

  for (int x = 0; x < 150; x++){ //Get 150 samples
  AcsValue = analogRead(A1);     //Read current sensor values   
  Samples = Samples + AcsValue;  //Add samples together
  delay (3); // let ADC settle before next sample 3ms
}
AvgAcs=Samples/150.0;//Taking Average of Samples


AcsValueF = (2.5 - (AvgAcs * (5.0 / 1024.0)) )/0.185;
Serial.print("       ");
Serial.print("Current");
Serial.print(AcsValueF);//Print the read current on Serial monitor
Serial.println("mA");
 DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    delay(500);
}