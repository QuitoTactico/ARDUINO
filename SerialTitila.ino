int a = 22;
char valor = '0';
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  digitalWrite(a, LOW);
}

void loop() {
  
  if(Serial.available()>0){
    valor = Serial.read();
    if(valor == '0'){
      digitalWrite(a, LOW);
    }else{
      while(valor == '1'){
        digitalWrite(a, HIGH);
        delay(200);
        digitalWrite(a,LOW);
        delay(200);
        if(Serial.available()>0){
          valor = Serial.read();
        }
      }
    }
  }
  Serial.println(valor);
}
