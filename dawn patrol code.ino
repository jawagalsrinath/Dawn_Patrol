#include<SoftwareSerial.h>

/* Create object named bt of the class SoftwareSerial */ 
SoftwareSerial bt(2,3); /* (Rx,Tx) */  
const int buzzer = 8;
const int PIR = 7;
void setup() {
   pinMode(buzzer, OUTPUT);
    pinMode(PIR, INPUT);
  bt.begin(9600); /* Define baud rate for software serial communication */
  Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() {
  
    if (bt.available()) /* If data is available on serial port */
    {
     //Serial.write(bt.read()); /* Print character received on to the serial monitor */
     char xy=bt.read();
     Serial.println(xy);
     if(xy=='A')4
     {
      int xx = digitalRead(PIR);
      Serial.println(xx);
      if(xx==1)
      {
       Serial.write('h');
       delay(10000);
       digitalWrite(buzzer, HIGH);
      delay(10000);
      digitalWrite(buzzer, LOW);
      }
      else
      {
        //Serial.write('h');
       digitalWrite(buzzer, LOW); 
      }

     }
     
     else if(xy=='B')
     {
     int xx = digitalRead(PIR);
      if(xx==1)
      {
     
       delay(20000);
       digitalWrite(buzzer, HIGH);
      delay(10000);
      digitalWrite(buzzer, LOW);
      }
      else
      {
       digitalWrite(buzzer, LOW); 
      }

     }
    }
}
