// Umgebungs-Sensor (Temperatur, Feuchtigkeit, Luftdruck) mit SHT40 und BMP280 Chip
// https://docs.m5stack.com/en/unit/ENV%E2%85%A3%20Unit

//-------------------------------------------------------------------
#include <M5UnitENV.h>

//-------------------------------------------------------------------
SHT4X sht40;
BMP280 bmp280;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  if (sht40.begin(&Wire, SHT40_I2C_ADDR_44, 2, 1) == false) {
    while (1) {
      Serial.println("Couldn't find SHT40...");
    }
  }

  // You can have 3 different precisions, higher precision takes longer
  sht40.setPrecision(SHT4X_HIGH_PRECISION);
  sht40.setHeater(SHT4X_NO_HEATER);

  if (bmp280.begin(&Wire, BMP280_I2C_ADDR, 2, 1) == false) {
    while (1) {
      Serial.println("Couldn't find BMP280...");
    }
  }

  // Default settings from datasheet
  bmp280.setSampling(BMP280::MODE_NORMAL,     /* Operating Mode. */
                     BMP280::SAMPLING_X2,     /* Temp. oversampling */
                     BMP280::SAMPLING_X16,    /* Pressure oversampling */
                     BMP280::FILTER_X16,      /* Filtering. */
                     BMP280::STANDBY_MS_500); /* Standby time. */
}

//-------------------------------------------------------------------
void loop(void)
{
  if (sht40.update()) {
    Serial.println("----- SHT40 -----");
    Serial.print("Temperature: ");
    Serial.print(sht40.cTemp);
    Serial.println(" degrees C");
    //
    Serial.print("Humidity: ");
    Serial.print(sht40.humidity);
    Serial.println("% rH");
  }

  if (bmp280.update()) {
    Serial.println("----- BMP280 -----");
    Serial.print("Temperature: ");
    Serial.print(bmp280.cTemp);
    Serial.println(" degrees C");
    //
    Serial.print("Pressure: ");
    Serial.print(bmp280.pressure);
    Serial.println(" Pa");
    //
    Serial.print("Approx altitude: ");
    Serial.print(bmp280.altitude);
    Serial.println(" m");
  }

  delay(1000);
}
