#include <SoftwareSerial.h>

SoftwareSerial bt(11,12);
byte motor11 = 2 ,motor12 = 3, 
    motor21 = 4, motor22 = 5,
    pwmMotorA = 9, pwmMotorB = 10;
int velocidad = 100;

void setup() {
   Serial.begin(9600); 
  bt.begin(9600);
  pinMode(motor11, OUTPUT);
  pinMode(motor12, OUTPUT);
  pinMode(motor21, OUTPUT);
  pinMode(motor22, OUTPUT);
  pinMode(pwmMotorA, OUTPUT);
  pinMode(pwmMotorB, OUTPUT);  


}

void loop() {
   
   //up = 84
   //right = 82
   //left = 76
  //down = 66
  // stop = 83
  if (bt.available()) {
//      Serial.println(bt.read());
      int data = bt.read();
      if( data == 84){//T
        
       digitalWrite(motor11,LOW); 
       digitalWrite(motor12,HIGH); 
       digitalWrite(motor21,LOW); 
       digitalWrite(motor22,HIGH); 
   
       analogWrite(pwmMotorA, velocidad);
       analogWrite(pwmMotorB, velocidad);
       
    }else if( data == 66){//B
        
       digitalWrite(motor11,HIGH); 
       digitalWrite(motor12,LOW); 
       digitalWrite(motor21,HIGH); 
       digitalWrite(motor22,LOW); 
   
       analogWrite(pwmMotorA, velocidad);
       analogWrite(pwmMotorB, velocidad);
       
    }else if( data == 76){//L
        
       digitalWrite(motor11,LOW); 
       digitalWrite(motor12,HIGH); 
       digitalWrite(motor21,LOW); 
       digitalWrite(motor22,LOW); 
   
       analogWrite(pwmMotorA, velocidad);
       analogWrite(pwmMotorB, velocidad);
       
    }else if( data == 82){//R
        
       digitalWrite(motor11,LOW);
       digitalWrite(motor12,LOW);
       digitalWrite(motor21,LOW);
       digitalWrite(motor22,HIGH);
   
       analogWrite(pwmMotorA, velocidad);
       analogWrite(pwmMotorB, velocidad);
       
    }else if( data == 83){//S
        
       digitalWrite(motor11,LOW); 
       digitalWrite(motor12,LOW); 
       digitalWrite(motor21,LOW); 
       digitalWrite(motor22,LOW); 
   
       analogWrite(pwmMotorA, velocidad);
       analogWrite(pwmMotorB, velocidad);
       
    }
      Serial.println(data); 
    }
   

}
