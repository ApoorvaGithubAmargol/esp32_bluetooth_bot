#include<BluetoothSerial.h>
BluetoothSerial Serial_BT;
char command;
int motor1Pin1=19;
int motor1Pin2=18;
int motor2Pin1=27;
int motor2Pin2=26;
void setup()
{
  Serial.begin(115200);
  Serial_BT.begin("BLUE");
  Serial.println("Bluetooth Turned On");
  pinMode(motor1Pin1,OUTPUT);
  pinMode(motor1Pin2,OUTPUT);
  pinMode(motor2Pin1,OUTPUT);
  pinMode(motor2Pin2,OUTPUT);
  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,LOW);
  digitalWrite(motor2Pin1,LOW);
  digitalWrite(motor2Pin2,LOW);

}
void loop()
{
  if(Serial_BT.available())
  {
    Serial.print("Data received is:");
    command=Serial_BT.read();
  }
  if(command=='F')
  {
    digitalWrite(motor1Pin1,HIGH);
   digitalWrite(motor1Pin2,LOW);
    digitalWrite(motor2Pin1,HIGH);
     digitalWrite(motor2Pin2,LOW);
    
  }
  if(command=='B')
  {
    digitalWrite(motor1Pin1,LOW);
    digitalWrite(motor1Pin2,HIGH);
    digitalWrite(motor2Pin1,LOW);
    digitalWrite(motor2Pin2,HIGH);
  }
  if(command=='R')
  {
    digitalWrite(motor1Pin1,HIGH);
    digitalWrite(motor1Pin2,LOW);
    digitalWrite(motor2Pin1,LOW);
    digitalWrite(motor2Pin2,HIGH);
  }
  if(command=='L')
  {
    digitalWrite(motor1Pin1,LOW);
    digitalWrite(motor1Pin2,HIGH);
    digitalWrite(motor2Pin1,HIGH);
    digitalWrite(motor2Pin2,LOW);
  }
  if(command=='S')
  {
    digitalWrite(motor1Pin1,LOW);
    digitalWrite(motor1Pin2,LOW);
    digitalWrite(motor2Pin1,LOW);
    digitalWrite(motor2Pin2,LOW);
  }

}
