int a = 22;
int t = 100;

void serialEvent(){
    t = Serial.parseInt();
}

void setup() {
  Serial.begin(9600);
  
  pinMode(a, OUTPUT);
  digitalWrite(a, LOW);
}

void loop() {
  
  digitalWrite(a, HIGH);
  delay(t);
  
  digitalWrite(a, LOW);
  delay(t);
}
