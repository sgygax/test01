// Farben-Sensor mit TCS34725 Chip
// https://docs.m5stack.com/en/unit/COLOR
// https://github.com/adafruit/Adafruit_TCS34725

//-------------------------------------------------------------------
#include "Adafruit_TCS34725.h"

//-------------------------------------------------------------------
/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  if (tcs.begin() == false) {
    while (1) {
      Serial.println("Kein Farben-Sensor gefunden...");
    }
  }
}

//-------------------------------------------------------------------
void loop(void)
{
  uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);

  // colorTemp = tcs.calculateColorTemperature(r, g, b);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);

  lux = tcs.calculateLux(r, g, b);

  Serial.print("Color Temp: ");
  Serial.print(colorTemp);
  Serial.print(" K\t");

  Serial.print("Lux: ");
  Serial.print(lux);
  Serial.print("\t");

  Serial.print("R: ");
  Serial.print(r);
  Serial.print("\t");

  Serial.print("G: ");
  Serial.print(g);
  Serial.print("\t");

  Serial.print("B: ");
  Serial.print(b);
  Serial.print("\t");

  Serial.print("C: ");
  Serial.print(c);
  Serial.println("");

  //delay(100);
}
