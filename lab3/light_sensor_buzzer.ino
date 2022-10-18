#define _A0_LIGHT_ADC 36 //ADC 포트 설정

int freq=2000;
int channel=0;
int resolution=8;

void setup() {
  //인터페이스 초기화
  Serial.begin(115200);
  ledcSetup(channel,freq,resolution);
  ledcAttachPin(25,channel);
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
 
}

void loop() {
  int a = analogRead(_A0_LIGHT_ADC);
  ledcWrite(channel,128);
  ledcWriteTone(channel,a);
  delay(100);
}
