#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

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
  matrix.begin(); // I2C주소값 선언(0x74) 
}

void loop() {
  matrix.setRotation(0); // 디스플레이 위치 값
  matrix.clear(); // LED Matirx 화면 초기화
  // matrix.drawBitmap(float x(x좌표값), float y(y좌표값), text, int width(가로행), int height(세로열), brightness(밝기))
  matrix.drawBitmap(0,0,smile_bmp,8,8,100);

  delay(1000);
  matrix.clear();
  delay(2000);
}
