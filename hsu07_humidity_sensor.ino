
/*
 * Read the humidity value from a HSU-07 humidity sensor.
 * Data interpolated from relative humidity chart in datasheet.
 * (http://www.datasheet.hk/download.php?id=1658014&pdfid=6B4C785A9E706B899B73FB7599952FD7&file=0330\hsu-07_2016208.pdf)
 * 
 * Connect Sensor to +5V/Gnd, data pin to A0
 * 
 */

#include "InterpolationLib.h"

double vOut[] = { 0.5, 0.8, 1.4, 1.75, 2.0, 2.25, 2.4, 2.55, 2.75 };
double   rh[] = { 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0 };
int points = 9;

void setup() {
  Serial.begin(9600);
}

const double voltunits = 0.0049;

double relative_humidity(double v) {
  return Interpolation::CatmullSpline(vOut, rh, points, v, false);   
}

void loop() {
  double volts = analogRead(A0) * voltunits;
  Serial.print("Volts is ");
  Serial.print(volts);
  Serial.print(" relative humidity is ");
  Serial.println(relative_humidity(volts)); 
  delay(1000);  
}
