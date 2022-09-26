// GPIO15에 해당하는 Blink LED장치 Define 매크로 함수 정의
// 회로도 참조하여 GPIO 번호 지정 
#define _BLINK_LED_GPIO 15


void setup() { 
  //프로그램이 시작할 때 한번만 실행되는 함수, 초기설정
  //입출력장치 핀설정 및 입출력 모드 설정
  //LED 제어를 하기위해 PIN의 모드를 출력(OUTPUT) 모드로 설정
  // PIN 모드 설정 구현
  pinMode(_BLINK_LED_GPIO, OUTPUT);
}

int i=0;

void loop() { 
  //프로그램이 반복적으로 실행되는 함수 : 메인코드
  digitalWrite(_BLINK_LED_GPIO, HIGH);  //GPIO15 핀 HIGH
  delay(1000);      //시간 딜레이 함수(ms)
  digitalWrite(_BLINK_LED_GPIO, LOW);   //GPIO15 핀 LOW
  delay(1000);
  i++;
  if (i==10) {
    while(1){ // infinite loop
       
    }
  }
}
