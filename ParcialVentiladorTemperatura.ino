#define MEDIDOR 1
#define LEDVERDE 30
#define LEDROJO 31
#define MOTOR 36

float bitsAGrados(unsigned int bits){
  float TEMPERATURA = (bits / 68.3) + 15;
  return TEMPERATURA;
}
void temperaturaBaja(){
  digitalWrite(LEDVERDE,HIGH);
  digitalWrite(LEDROJO,LOW);
  digitalWrite(MOTOR,HIGH);
}
void temperaturaMedia(){
  digitalWrite(LEDVERDE,LOW);
  digitalWrite(LEDROJO,LOW);
  digitalWrite(MOTOR,LOW);
}
void temperaturaAlta(){
  digitalWrite(LEDVERDE,LOW);
  digitalWrite(LEDROJO,HIGH);
  digitalWrite(MOTOR,HIGH);
}


void setup() {
  Serial.begin(9800);

  pinMode(LEDVERDE,OUTPUT);
  pinMode(LEDVERDE,OUTPUT);
  pinMode(MOTOR,OUTPUT);
  
  digitalWrite(LEDVERDE,LOW);
  digitalWrite(LEDROJO,LOW);
  digitalWrite(MOTOR,LOW);
}

void loop() {
  float TEMPERATURA = bitsAGrados( analogRead(MEDIDOR));
  Serial.println(TEMPERATURA);
  
  if       ( TEMPERATURA < 19 ){
    Serial.println("[ TEMPERATURA BAJA ]");
    temperaturaBaja();
    delay(10000);
  }else if ( TEMPERATURA >= 19 && TEMPERATURA <= 25     ){
    temperaturaMedia();
  }else if ( TEMPERATURA > 25 ){
    Serial.println("[ TEMPERATURA ALTA ]");
    temperaturaAlta();
    delay(20000);
  }
  
  delay(50);
}
