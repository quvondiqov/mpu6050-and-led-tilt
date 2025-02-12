#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;

//declaring pins 
int Pin_1= 4; 
int Pin_2= 5;
int Pin_3= 6;
int Pin_4= 7;
int Pin_5= 8;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ }
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  
  mpu.calcOffsets(); 
  Serial.println("Done!\n");

pinMode(Pin_1, OUTPUT); 
pinMode(Pin_2, OUTPUT);
pinMode(Pin_3, OUTPUT);
pinMode(Pin_4, OUTPUT);
pinMode(Pin_5, OUTPUT);
}

void loop() {
  mpu.update();
  
  if((millis()-timer)>10){ 
	Serial.print("X : ");
	Serial.print(mpu.getAngleX());
	Serial.print("\tY : ");
	Serial.print(mpu.getAngleY());
	Serial.print("\tZ : ");
	Serial.println(mpu.getAngleZ());
	timer = millis();  
  }

if (mpu.getAngleY())<3
digitalWrite(Pin_5, HIGH); 


}
