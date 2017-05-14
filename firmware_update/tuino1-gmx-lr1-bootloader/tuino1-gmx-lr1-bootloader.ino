/* _____  _____  __  __             _____  _____ 
  / ____||_   _||  \/  |    /\     / ____||_   _|
 | |  __   | |  | \  / |   /  \   | (___    | |  
 | | |_ |  | |  | |\/| |  / /\ \   \___ \   | |  
 | |__| | _| |_ | |  | | / ____ \  ____) | _| |_ 
  \_____||_____||_|  |_|/_/    \_\|_____/ |_____|
  (c) 2017 GIMASI SA                                               

 * tuino1-gmx-lr1-bootloader.ino
 *
 *  Created on: May 14, 2017
 *      Author: Massimo Santoli
 *      Brief: Using Tuino 1 as serial passthrough to GMX-LR1 Module in BootLoader mode
 *      Version: 1.0
 *
 *      License: it's free - do whatever you want! ( provided you leave the credits)
 *
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200,SERIAL_8E1);

  if(Serial1) {
    Serial1.begin(115200,SERIAL_8E1);
  } 
        
 
  // Boot in Bootloader Mode
  pinMode(GMX_GPIO5,OUTPUT);
  digitalWrite(GMX_GPIO5,1);
  pinMode(GMX_GPIO6,OUTPUT);
  digitalWrite(GMX_GPIO6,1);
  
  // Reset 
  pinMode(GMX_RESET,OUTPUT);
  digitalWrite(GMX_RESET,HIGH);
  delay(100);
  digitalWrite(GMX_RESET,LOW);
  delay(100);
  digitalWrite(GMX_RESET,HIGH);
  delay(500);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  byte ch;

  if (Serial1.available()>0) 
  {
    Serial.write(Serial1.read());
  }

  if (Serial.available()>0) 
  {
    ch = Serial.read();
    Serial1.write(ch);
  }
  
}
