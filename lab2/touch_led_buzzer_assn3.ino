//TODO: buzzerChannel 아닐 때 소리가 잘 안나기도 함.다른 걸로 설정해보기.
//TODO: 파란색 인식이 빠르지 않음. 개선점 찾아볼 것.


#define _TOUCH_LEFT_27 27 // LEFT TOUCH 장치 Pin번호 매크로 지정(GPIO27)
#define _TOUCH_RIGHT_4 4 // RIGHT TOUCH 장치 Pin번호 매크로 지정(GPIO4)

#define _LED_R_GPIO_12 12
#define _LED_B_GPIO_14 14

// led
int freq = 500;     // PWM 주파수 설정 500Hz              
int resolution = 0; // PWM duty cycle resolution(해상도) 설정
                    // 8bit=0~255, 16bit=0~65535
int ledChannelRed = 0; // PWM 채널 설정(0~15)
int ledChannelBlue = 2; // PWM 채널 설정(0~15)

int threshold_off_L = 10;
int threshold_off_R = 15;
                    
// buzzer
int buzzerChannel = 1; // PWM 채널 설정(0~15) // PWM 채널이 겹치면 안됨 


void setup() {
  // Touch
  Serial.begin(115200);

  // LED
  pinMode(_LED_R_GPIO_12, OUTPUT);
  digitalWrite(_LED_R_GPIO_12, LOW);
  pinMode(_LED_B_GPIO_14, OUTPUT);
  digitalWrite(_LED_B_GPIO_14, LOW);
  
  ledcSetup(ledChannelRed, freq, resolution);    // PWM채널, 주파수, 해상도 설정
  ledcAttachPin(_LED_R_GPIO_12, ledChannelRed);  // GPIO Pin, 채널설정
  ledcSetup(ledChannelBlue, freq, resolution);
  ledcAttachPin(_LED_B_GPIO_14, ledChannelBlue);

  // Buzzer
  pinMode(25,OUTPUT); // 부저 전원인가를 위한 GPIO 제어핀 제어
  digitalWrite(25,HIGH); // 부저 전원 ON
  
  ledcAttachPin(2,buzzerChannel);
  
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
        ledcWrite(ledChannelRed, 255); 
        ledcWrite(ledChannelBlue, 0); 
        Serial.println("Red LED ON");

        // Buzzer ON
        ledcWriteTone(buzzerChannel, 261.6256); 

        // Wait
        delay(500);
      
        // All OFF
        ledcWrite(ledChannelRed, 0);   
        ledcWrite(ledChannelBlue, 0);  
        ledcWriteTone(buzzerChannel, 0); 
  }

  if (touchRead(_TOUCH_RIGHT_4) > threshold_off_L && touchRead(_TOUCH_RIGHT_4) < threshold_off_R) { // Right Touch
        // Red LED OFF, Blue LED ON
        ledcWrite(ledChannelRed, 0); 
        ledcWrite(ledChannelBlue, 255); 
        Serial.println("BLUE LED ON");
         
        // Buzzer ON
        ledcWriteTone(buzzerChannel, 500); 
        
        // Wait
        delay(500);
      
        // All OFF
        ledcWrite(ledChannelRed, 0);   
        ledcWrite(ledChannelBlue, 0); 
        ledcWriteTone(buzzerChannel, 0); 
  }

}
