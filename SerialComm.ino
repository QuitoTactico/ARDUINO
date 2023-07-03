int b = 22;
int a = 23;
char valor = '0';
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
}

void loop() {
  
  if(Serial.available()>0){
    valor = Serial.read();
    if(valor == '0'){
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
    }else{
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
    }
  }
  Serial.println(valor);
}
