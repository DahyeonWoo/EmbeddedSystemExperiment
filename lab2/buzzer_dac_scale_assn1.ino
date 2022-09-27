int freq = 2000; // PWM 주파수 설정(2000Hz)
int channel = 0; // PWM 채널 설정(0~15)
int resolution = 8; // PWM duty cycle resolution(해상도) 설정, 8bit=0~255
double scale[7] = {262.6256, 293.6648, 329.6276, 349.2282, 391.9954, 440.0000, 493.8833};

void setup() { 
  ledcSetup(channel, freq, resolution); // PWM 채널, 주파수, 해상도 설정(ledcSetup)
  ledcAttachPin(2,channel); // GPIO핀, 채널 설정
  pinMode(25,OUTPUT); // 부저 전원인가를 위한 GPIO 제어핀 제어
  digitalWrite(25,HIGH); // 부저 전원 ON
}

void loop() {
  
  //ledcWrite(channel, 125); // 부저의 PWM duty cycle 기준 값
  
  for (int i=0; i<7; i++) {
    // 부저의 PWM 주파수값의 변화를 통해 상태확인 
    // 음계의 주파수를 이용하여 멜로디음을 출력 (ledcWriteTone)
    // 도레미파솔라시
    ledcWriteTone(channel, scale[i]);
    delay(200);
  }
  
  digitalWrite(25, LOW); // 부저 전원 OFF
}
