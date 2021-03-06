/*  This file is the intellectual property of:
 *  Simon Narang and William Wang, understood to be "Nawang Labs"
 *  Under no legal premise is this file to copied without the full enirety of permission granted by Nawang
 *  Developed under the MIT license
 */

#include <Arduino.h>
#include "XBOXONE.h"
#include "Servo.h"
#include "vexMotor.h"
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif

USB Usb;
XBOXONE Xbox(&Usb);

int statusLEDPort = 13;

vexMotor base;
vexMotor hip;
vexMotor shoulder;
vexMotor claw;
vexMotor pennyHolder;

void setup() {

  base.attach(3);
  hip.attach(5);
  shoulder.attach(6);
  claw.attach(9);
  pennyHolder.attach(10);
  
  Serial.begin(115200);

  while (!Serial);

  if (Usb.Init() == -1) {

    Serial.print(F("\r\n Unable to connect with Xbox controller. Try EEPROM reseting this board and then uploading your code again. Also, make sure the Xbox controller is properly functioning."));

    while (1);

  }

  Serial.print(F("\r\n Yay! XBOX USB Library Started. Give Yourself a Pat on the Back 👏"));

}

void loop() {

  Usb.Task();

  if (Xbox.XboxOneConnected) {

    if (Xbox.getAnalogHat(LeftHatX) > 7500 ||
    Xbox.getAnalogHat(LeftHatX) < -7500 ||
    Xbox.getAnalogHat(LeftHatY) > 7500 ||
    Xbox.getAnalogHat(LeftHatY) < -7500 ||
    Xbox.getAnalogHat(RightHatX) > 7500 ||
    Xbox.getAnalogHat(RightHatX) < -7500 ||
    Xbox.getAnalogHat(RightHatY) > 7500 ||
    Xbox.getAnalogHat(RightHatY) < -7500) {

      if (Xbox.getAnalogHat(LeftHatX) > 7500 || Xbox.getAnalogHat(LeftHatX) < -7500) {

        Serial.print(F("\r\n LeftHatX: "));
        Serial.print(Xbox.getAnalogHat(LeftHatX));
        Serial.print("\t");

      }

      if (Xbox.getAnalogHat(LeftHatY) > 7500 || Xbox.getAnalogHat(LeftHatY) < -7500) {

        Serial.print(F("\r\n LeftHatY: "));
        Serial.print(Xbox.getAnalogHat(LeftHatY));
        Serial.print("\t");

      }

      if (Xbox.getAnalogHat(RightHatX) > 7500 || Xbox.getAnalogHat(RightHatX) < -7500) {

        Serial.print(F("\r\n RightHatX: "));
        Serial.print(Xbox.getAnalogHat(RightHatX));
        Serial.print("\t");

      }

      if (Xbox.getAnalogHat(RightHatY) > 7500 || Xbox.getAnalogHat(RightHatY) < -7500) {

        Serial.print(F("\r\n RightHatY: "));
        Serial.print(Xbox.getAnalogHat(RightHatY));
        Serial.print("\t");
      }

    }

    if (Xbox.getButtonPress(L2) > 0 || Xbox.getButtonPress(R2) > 0) {

      if (Xbox.getButtonPress(L2) > 0) {

        Serial.print(F("L2: "));
        Serial.print(Xbox.getButtonPress(L2));
        Serial.print("\t");

      }

      if (Xbox.getButtonPress(R2) > 0) {

        Serial.print(F("R2: "));
        Serial.print(Xbox.getButtonPress(R2));
        Serial.print("\t");

      }

    }

    if (Xbox.getButtonPress(UP)){

      Serial.println(F("Up"));

      hip.write(-190);
      
    } else {
      
      if (Xbox.getButtonPress(DOWN)) {

      Serial.println(F("Down"));

      hip.write(100);
      
      } else {

      hip.write(0);
            
      }
      
    }
    
    if (Xbox.getButtonClick(LEFT)) {

      Serial.println(F("Left"));

    }

    if (Xbox.getButtonClick(RIGHT)) {

      Serial.println(F("Right"));

    }

    if (Xbox.getButtonClick(START)) {

      Serial.println(F("Start"));

    }

    if (Xbox.getButtonClick(BACK)) {

      Serial.println(F("Back"));

    }

    if (Xbox.getButtonClick(XBOX)) {

      Serial.println(F("Xbox"));

    }

    if (Xbox.getButtonClick(SYNC)) {

      Serial.println(F("Sync"));

    }

    if (Xbox.getButtonClick(L1)) {

      Serial.println(F("L1"));

    }

    if (Xbox.getButtonClick(R1)) {

      Serial.println(F("R1"));

    }

    if (Xbox.getButtonClick(L2)) {

      Serial.println(F("L2"));

    }

    if (Xbox.getButtonClick(R2)) {

      Serial.println(F("R2"));

    }

    if (Xbox.getButtonPress(L3)) {

      Serial.println(F("L3"));

    }

    if (Xbox.getButtonPress(R3)) {

      Serial.println(F("R3"));

    }

    if (Xbox.getButtonPress(A)) {

      Serial.println(F("A"));

    }

    if (Xbox.getButtonClick(B)) {

      Serial.println(F("B"));

    }

    if (Xbox.getButtonClick(X)) {

      Serial.println(F("X"));

    }

    if (Xbox.getButtonPress(Y)) {

      Serial.println(F("Y"));

    }

  }

  delay(1);

}
