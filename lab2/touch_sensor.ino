#define _TOUCH_LEFT_27 27 // LEFT TOUCH 장치 Pin번호 매크로 지정(GPIO27)
#define _TOUCH_RIGHT_4 4 // RIGHT TOUCH 장치 Pin번호 매크로 지정(GPIO4)
void setup() {
  Serial.begin(115200);
}
void loop() {
  Serial.print("Left touch = ");
  Serial.print(touchRead(_TOUCH_LEFT_27)); // Capacitor에 의한 전하량 Read
  Serial.print(" | ");
  Serial.print("Right Touch = ");
  Serial.println(touchRead(_TOUCH_RIGHT_4));
  delay(500);
}
