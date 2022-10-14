// BME280
#include <SparkFunBME280.h> // BME280센서 라이브러리 
//source:\Arduino\hardware\espressif\esp32\libraries\SparkFun_BME280_Arduino_Library-master\src 
#define BME280_ADDR 0x77 // I2C 주소값
// LED Matrix
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>


#define temp_Threshold 30
#define humm_Threshold 50

// BME280
BME280 myBME280; // BME280 레지스터 함수 선언(BME280 클래스) 
// LED matrix
Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();
static const uint8_t PROGMEM // 플래시 메모리에 저장하기 위한 지시자

smile_bmp[] = // 이모티콘 배열 선언(생성 사이트 참고)
{ 
  B00000000,
  B01000010,
  B10100101,
  B00000000,
  B01000010,
  B00111100,
  B00000000,
  B00000000
};


void setup() {
  
  // 온습도 센서
  Serial.begin(115200);
  myBME280.setI2CAddress(BME280_ADDR); // BME280 I2C주소값 설정(0x77)
  myBME280.beginI2C(); // BME280 I2C장치 호출

  // LED matrix
  matrix.begin(); // I2C주소값 선언(0x74) 

}

void loop() {
  float temp_c = myBME280.readTempC();
  float humm = myBME280.readFloatHumidity();
  matrix.setRotation(0); // 디스플레이 위치 값
  matrix.clear(); // LED Matirx 화면 초기화

  // 시리얼 모니터 출력
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

  // 만약 온도가 temp_Threshold 보다 낮고,
  // 습도가 humm_threshold 보다 낮으면 smile
  // matrix.drawBitmap 함수 사용

  if (temp_c < temp_Threshold && humm < humm_Threshold) {
    matrix.setRotation(0); // 디스플레이 위치 값
    matrix.clear(); // LED Matirx 화면 초기화
    // matrix.drawBitmap(float x(x좌표값), float y(y좌표값), text, int width(가로행), int height(세로열), brightness(밝기))
    matrix.drawBitmap(0,0,smile_bmp,8,8,100);
  }

  delay(1000);
  matrix.clear();
  delay(1000);
}
