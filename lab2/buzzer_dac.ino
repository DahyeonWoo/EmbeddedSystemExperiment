int freq = 2000; // PWM 주파수 설정(2000Hz)
int channel = 0; // PWM 채널 설정(0~15)
int resolution = 8; // PWM duty cycle resolution(해상도) 설정, 8bit=0~255

void setup() { 
  ledcSetup(channel, freq, resolution); // PWM 채널, 주파수, 해상도 설정(ledcSetup)
  ledcAttachPin(2,channel); // GPIO핀, 채널 설정
  pinMode(25,OUTPUT); // 부저 전원인가를 위한 GPIO 제어핀 제어
  digitalWrite(25,HIGH); // 부저 전원 ON
}

void loop() {
  ledcWriteTone(channel, 261); // 부저의 PWM 주파수 기준 값, C(도) 261.6256
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle = dutyCycle + 10) {
    // 부저의 PWM duty cycle값의 변화를 통해 상태확인
    // 한 주기내에서 ON시간과 OFF시간의 비율을 결정하는 값 
    ledcWrite(channel, dutyCycle); 
    delay(200);
  }
  ledcWrite(channel, 125); // 부저의 PWM duty cycle 기준 값
  for (int freq = 255; freq < 5000; freq = freq + 250) {
    // 부저의 PWM 주파수값의 변화를 통해 상태확인 
    // 음계의 주파수를 이용하여 멜로디음을 출력 (ledcWriteTone)
    ledcWriteTone(channel, freq);
    delay(200);
  }
  digitalWrite(2, LOW); // 부저 전원 OFF
}
