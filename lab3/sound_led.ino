#define _MIC_36 36 // ADC1_CH0 pin(SENSOR_VP, GPIO36) 매크로 지정

#define _LED_R_GPIO_12 12
#define _LED_B_GPIO_14 14

int freq = 500;     // PWM 주파수 설정 500Hz
int ledChannel = 0; // PWM 채널 설정(0~15)
                    // RED=0, GREEN=1, BLUE=2
int resolution = 0; // PWM duty cycle resolution(해상도) 설정
                    // 8bit=0~255, 16bit=0~65535

int MIC_threshold = 1500;

void setup() {
  // Sound
  Serial.begin(115200);

  // LED
  pinMode(_LED_R_GPIO_12, OUTPUT);
  digitalWrite(_LED_R_GPIO_12, LOW);
  pinMode(_LED_B_GPIO_14, OUTPUT);
  digitalWrite(_LED_B_GPIO_14, LOW);
  
  ledcSetup(ledChannel, freq, resolution);    // PWM채널, 주파수, 해상도 설정
  ledcAttachPin(_LED_R_GPIO_12, ledChannel);  // GPIO Pin, 채널설정
  ledcSetup(ledChannel+2, freq, resolution);
  ledcAttachPin(_LED_B_GPIO_14, ledChannel+2);
}

void loop() {
  // LED의 동작 상태를 읽어 와서 기준값과 Mic값의 변화에 따라 RED/BLUE LED 색상 연출
  // Sound Sensor 입력 값을 읽어서 콘솔에 출력 : 시리얼 모니터 및 플로터로 읽은 값 확인
  Serial.println(analogRead(_MIC_36)); // MIC 입력 값 출력
  
  int led_state = digitalRead(_LED_R_GPIO_12); // 현재 RED LED의 상태 값을 읽어서 led_state 변수에 저장
  if ( analogRead(_MIC_36) > MIC_threshold) { // 센서 값이 정해진 Threshold 보다 클때 LED 출력 제어
    if (led_state == LOW) {
      // RED LED는 ON
      // BLUE LED는 OFF
      ledcWrite(ledChannel, 255); 
      ledcWrite(ledChannel+2, 0); 
      delay(100);
    } else {
      // RED LED는 OFF
      // BLUE LED는 ON
      ledcWrite(ledChannel, 0); 
      ledcWrite(ledChannel+2, 255); 
      delay(100);
    }
  }
  delay(2);
}
