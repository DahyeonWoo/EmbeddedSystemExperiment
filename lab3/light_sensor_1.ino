#define _A0_LIGHT_ADC_36  36 //ADC 포트 설정

void setup() {
	//인터페이스 초기화
  Serial.begin(115200);
}

void loop() {
	//실습 #1 : 조도 센서 값을 읽어서 콘솔 모니터 출력
  Serial.print("Light Sensor Value = ");
  Serial.println(analogRead(_A0_LIGHT_ADC_36));
  delay(100);
}
