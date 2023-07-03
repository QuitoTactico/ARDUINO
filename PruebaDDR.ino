int PC = 0;
#define LP 6
#define EP 7
//F = PC input
//K = PC output

void setup() {
  DDRF = 0B00001111;
  DDRK = 0B00001111;

  pinMode(LP, OUTPUT);
  pinMode(EP, OUTPUT);

  digitalWrite(LP,0);
  digitalWrite(EP,0);
  
  Serial.begin(9600);
}

void loop() {
  PORTK = PC;
  digitalWrite(LP,0);
  digitalWrite(EP,0);
  
  delay(200);
  digitalWrite(LP,1);
  digitalWrite(EP,1);
  delay(200);
  PC++;

  Serial.print("PC:");
  Serial.println(PINF);
}
