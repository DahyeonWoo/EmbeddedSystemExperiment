#define _D0_PIR_GPIO_2 2 //D0핀: PIR센서 입력 // D0핀 입력장치(PIR센서)에 해당하는 GPIO 핀 매크로지정 
#define _D1_PIR_GPIO_15 15 //D1핀: LED 출력 // D1핀 출력장치(PIR센서)에 해당하는 GPIO 핀 매크로지정

void setup() {
   //PIR 센서 입력 및 LED 출력 PIN 동작 모드 설정
	pinMode(_D0_PIR_GPIO_2, INPUT); // D0핀 입력설정
  pinMode(_D1_PIR_GPIO_15, OUTPUT); // D1핀 출력설정
}

void loop() {
	//PIR 센서 입력에 따른 LED ON/OFF 제어
	
  int motionState = digitalRead(_D0_PIR_GPIO_2); // D0핀 입력상태 저장
	
	//PIR 센서 입력값이 HIGH이면 LED ON, 아니면 LED OFF
  if (motionState == HIGH){
    digitalWrite(_D1_PIR_GPIO_15, HIGH);
    delay(100);
  } else {
    digitalWrite(_D1_PIR_GPIO_15, LOW);
    delay(100);
  }
}
