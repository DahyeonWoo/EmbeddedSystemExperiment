#define _TOUCH_LEFT_27 27 // LEFT TOUCH 장치 Pin번호 매크로 지정(GPIO27)
#define _TOUCH_RIGHT_4 4 // RIGHT TOUCH 장치 Pin번호 매크로 지정(GPIO4)

#define _LED_R_GPIO_12 12
#define _LED_B_GPIO_14 14

int freq = 500;     // PWM 주파수 설정 500Hz
int ledChannel = 0; // PWM 채널 설정(0~15)
                    // RED=0, GREEN=1, BLUE=2
int resolution = 0; // PWM duty cycle resolution(해상도) 설정
                    // 8bit=0~255, 16bit=0~65535

int threshold_off_L = 10;
int threshold_off_R = 15;

void setup() {
  // Touch
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

  Serial.print("Left : ");
  Serial.print(touchRead(_TOUCH_LEFT_27)); // Capacitor에 의한 전하량 Read
  Serial.print(" ");
  Serial.print("Right : ");
  Serial.println(touchRead(_TOUCH_RIGHT_4));
  delay(500);

  if (touchRead(_TOUCH_LEFT_27) < threshold_off_L && touchRead(_TOUCH_RIGHT_4) > threshold_off_R) { // Left Touch
        // Red LED ON, Blue LED OFF
        ledcWrite(ledChannel, 255); 
        ledcWrite(ledChannel+2, 0); 
        Serial.println("Red LED ON");

        // Wait
        delay(500);

        // All OFF
        ledcWrite(ledChannel, 0); 
  }

  if (touchRead(_TOUCH_RIGHT_4) > threshold_off_L && touchRead(_TOUCH_RIGHT_4) < threshold_off_R) { // Right Touch
        // Red LED OFF, Blue LED ON
        ledcWrite(ledChannel, 0); 
        ledcWrite(ledChannel+2, 255); 
        Serial.println("BLUE LED ON");

        // Wait
        delay(500);
        
        // All OFF
        ledcWrite(ledChannel+2, 0); 
  }

}
