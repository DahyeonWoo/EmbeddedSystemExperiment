#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
// LED Matrix 드라이버 제어를 위한 라이브러리
// source : Arduino\hardware\espressif\esp32\libraries\Adafruit_IS31FL3731-master
Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();
const char text[4]={'A','J','O','U'};
// 출력을 위한 6개의 문자 배열 선언
void setup() {
  matrix.begin(); // I2C주소값 선언, begin(uint8_t addr = ISSI_ADDR_DEFAULT);
  // #define ISSI_ADDR_DEFAULT 0x74
}
void loop() {
  matrix.setTextSize(1); // Text 크기
  matrix.setTextColor(100); // Text 밝기
  for(int i=0;i<4;i++){ // text[ ] 배열에 대한 반복문 선언
    matrix.clear(); // LED Matrix 화면 초기화
    matrix.setCursor(1,1); // LED Matrix 출력의 좌표값(x, y): matrix.setCursor() 함수
    matrix.printf("%c", text[i]); // 문자 배열값 출력(%c=문자1개) : matrix.printf() 함수
    delay(500);
  }
  matrix.clear();
  delay(2000);
}
