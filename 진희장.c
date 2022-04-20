int PIN_LED1 = 7;
int PIN_LED2 = 6;
int PIN_LED3 = 8;
int PIN_LED4 = 9;
int PIN_TRIGER = 4;
int PIN_ECHO = 3;

void setup()
{
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_LED4, OUTPUT);
  pinMode(PIN_TRIGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  
  int distance = 0; 
  
  digitalWrite(PIN_TRIGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGER, LOW);
 	
  distance = pulseIn(PIN_ECHO,HIGH);
  int cm = distance / 57;
  
  Serial.println(cm);
  if(cm > 150) {
	digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, HIGH);
    digitalWrite(PIN_LED4, HIGH);
  } else if (cm > 120) {
  	digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_LED4, LOW);
  } else if (cm > 90){
  	digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_LED4, LOW);
  } else if (cm > 60){
  	digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, HIGH);
    digitalWrite(PIN_LED4, LOW);
  } else if (cm > 30){
  	digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_LED4, HIGH);
  } else {
  	digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_LED4, LOW);
  }
}