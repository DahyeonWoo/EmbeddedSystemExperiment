#define _MIC_36 36 // ADC1_CH0 pin(SENSOR_VP, GPIO36) 매크로 지정
void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(analogRead(_MIC_36)); // MIC 입력 값 출력
  delay(2);
}
