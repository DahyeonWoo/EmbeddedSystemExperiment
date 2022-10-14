#include <SparkFunBME280.h> // BME280센서 라이브러리 
//source:\Arduino\hardware\espressif\esp32\libraries\SparkFun_BME280_Arduino_Library-master\src 
#define BME280_ADDR 0x77 // I2C 주소값
 
BME280 myBME280; // BME280 레지스터 함수 선언(BME280 클래스) 
/* BME280 Class 
void setI2CAddress(), bool beginI2C(), void setReferencePressure(), 
float readFloatPressure(), float readFloatAltitudeMeters(), float readFloatHumidity()
float readTempC(), float readTempF(), double dewPointC, double dewPointF */

void setup()
{
  Serial.begin(115200);
  myBME280.setI2CAddress(BME280_ADDR); // BME280 I2C주소값 설정(0x77)
  myBME280.beginI2C(); // BME280 I2C장치 호출
}
void loop()
{
  Serial.println("#BME280 Sensor Data#"); 
  
  // 섭씨온도 
  Serial.print(" Temperature(℃): ");
  Serial.print(myBME280.readTempC()); // 온도를 읽어서 소수점 2자리 까지 출력
  Serial.println(" degrees C");
  
  // 상대습도(%) 
  Serial.print(" Humidity: ");
  Serial.print(myBME280.readFloatHumidity()); // 습도를 읽어서 소수점 2자리 까지 출력
  Serial.println(" %");

  Serial.println();
  delay(2000);
}
