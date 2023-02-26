/*
 * This code reads acceleration and gyro info from arduino and sends it to serial.
 * LSM6DS3 library: https://www.arduino.cc/en/Reference/ArduinoLSM6DS3
 * Written by (        ) on 11/02/2020
 * Modified by (           ) on 11/02/2020
 */

#include "Arduino_LSM6DS3.h"
#include "MadgwickAHRS.h"

Madgwick filter;

// orientations
float roll = 0.0;
float pitch = 0.0;
float heading = 0.0;

void setup() {

  Serial.begin(9600);

  if (!IMU.begin()) {
    Serial.println("imu failed to initialize");
    while(true);
  }  
  filter.begin(104.00);
}

void loop() {
   // acceleration value
   float xAcc, yAcc, zAcc;

   // gyro value
   float xGyro, yGyro, zGyro;

    if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
      IMU.readAcceleration(xAcc, yAcc, zAcc);
      IMU.readGyroscope(xGyro, yGyro, zGyro);      
    }

    // updating filter with the values:
    filter.updateIMU(xGyro, yGyro, zGyro, xAcc, yAcc, zAcc);

    // roll, pitch, heading:
    roll = filter.getRoll();
    pitch = filter.getPitch();
    heading = filter.getYaw();
    
    if (Serial.available());
    char input = Serial.read();
    Serial.print(heading);
    Serial.print(",");
    Serial.print(pitch);
    Serial.print(",");
    Serial.println(roll);

    delay(100);
    


}
