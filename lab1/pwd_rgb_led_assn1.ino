#define _LED_R_GPIO_12 12
#define _LED_G_GPIO_13 13
#define _LED_B_GPIO_14 14

int freq = 500;     // PWM 주파수 설정 500Hz
int ledChannel = 0; // PWM 채널 설정(0~15)
                    // RED=0, GREEN=1, BLUE=2
int resolution = 8; // PWM duty cycle resolution(해상도) 설정
                    // 8bit=0~255, 16bit=0~65535
void setup() {
  pinMode(_LED_R_GPIO_12, OUTPUT);
  digitalWrite(_LED_R_GPIO_12, LOW);
  pinMode(_LED_G_GPIO_13, OUTPUT);
  digitalWrite(_LED_G_GPIO_13, LOW);
  pinMode(_LED_B_GPIO_14, OUTPUT);
  digitalWrite(_LED_B_GPIO_14, LOW);
  
  ledcSetup(ledChannel, freq, resolution);    // PWM채널, 주파수, 해상도 설정
  ledcAttachPin(_LED_R_GPIO_12, ledChannel);  // GPIO Pin, 채널설정

  ledcSetup(ledChannel+1, freq, resolution);
  ledcAttachPin(_LED_G_GPIO_13, ledChannel+1);
  ledcSetup(ledChannel+2, freq, resolution);
  ledcAttachPin(_LED_B_GPIO_14, ledChannel+2);
}

void loop() {
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // Duty Cycle 값이 0~255까지 순차적으로 증가(LED 밝기 증가)
        ledcWrite(ledChannel, dutyCycle); // Write장치 PWM채널, Duty Cycle값 설정
        ledcWrite(ledChannel+1, dutyCycle);
        ledcWrite(ledChannel+2, dutyCycle);
        delay(7);
  }
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        // Duty Cycle 값이 255~0까지 순차적으로 감소(LED 밝기 감소)
        ledcWrite(ledChannel, dutyCycle);
        ledcWrite(ledChannel+1, dutyCycle);
        ledcWrite(ledChannel+2, dutyCycle);
        delay(7);
  }
}
