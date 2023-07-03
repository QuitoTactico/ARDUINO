/*      - ESTEBAN VERGARA GIRALDO -
 * - Unidad de Control (CON) - Autómata -
 */
// [FUNCIONES]
#define LDA 22
#define ADD 23
#define SUB 24
#define MULT 25
#define DIV 26
#define CALL 27
#define RTRN 28
#define GOTO 29
#define OUT 30
#define HLT 31
#define POW 32
#define GRTR 33
#define LOWR 34
#define MOD 35
#define FACT 36

// [ÓRDENES (PC)]
#define LP 6
#define EP 7

// [ÓRDENES]
#define LA 37
#define EA 38
#define SU 39
#define RU 40
#define MU 41
#define DU 42
#define GU 43
#define LU 44
#define EU 45
#define LB 46
#define LO 47
#define LC 48
#define EC 49
#define LM 50
#define ER 51
#define LI 52
#define EI 53

//F = PC INPUT | K = PC OUTPUT
//DDL_ : setup | PORT_ : output | PIN_ : input
unsigned int PC = 0;
unsigned int PCtemp = 0;

bool rtrnmode = false;
bool callmode = false;

unsigned int clk = 200; // (ms) | (1000 / frecuencia del clock)


//       -----------------------------------------

void setup() {
  pinMode(LDA, INPUT);
  pinMode(ADD, INPUT);
  pinMode(SUB, INPUT);
  pinMode(MULT, INPUT);
  pinMode(DIV, INPUT);
  pinMode(CALL, INPUT);
  pinMode(RTRN, INPUT);
  pinMode(GOTO, INPUT);
  pinMode(OUT, INPUT);
  pinMode(HLT, INPUT);
  pinMode(POW, INPUT);
  pinMode(GRTR, INPUT);
  pinMode(LOWR, INPUT);
  pinMode(MOD, INPUT);
  pinMode(FACT, INPUT);

  pinMode(LA, OUTPUT);
  pinMode(EA, OUTPUT);
  pinMode(SU, OUTPUT);
  pinMode(RU, OUTPUT);
  pinMode(MU, OUTPUT);
  pinMode(DU, OUTPUT);
  pinMode(GU, OUTPUT);
  pinMode(LU, OUTPUT);
  pinMode(EU, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(LO, OUTPUT);
  pinMode(LC, OUTPUT);
  pinMode(EC, OUTPUT);
  pinMode(LM, OUTPUT);
  pinMode(ER, OUTPUT);
  pinMode(LI, OUTPUT);
  pinMode(EI, OUTPUT);

  pinMode(LP, OUTPUT);
  pinMode(EP, OUTPUT);

  DDRF = 0B11111111;
  DDRK = 0B00001111;

  Serial.begin(9600);
}

//       ----------------------------------------- 

void exeLDA(){
  Serial.print("LDA ");
  
  digitalWrite(EI,1);
  digitalWrite(LM,1);
  delay(clk);
  digitalWrite(LM,0);
  digitalWrite(EI,0);
  
  digitalWrite(ER,1);
  digitalWrite(LA,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.println(PINF);
  digitalWrite(LP,0);
  digitalWrite(LA,0);
  digitalWrite(ER,0);
}

void exeLDB(){
  digitalWrite(EI,1);
  digitalWrite(LM,1);
  delay(clk);
  digitalWrite(LM,0);
  digitalWrite(EI,0);
  
  digitalWrite(ER,1);
  digitalWrite(LB,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.println(PINF);
  digitalWrite(LP,0);
  digitalWrite(LB,0);
  digitalWrite(ER,0);
}

void exeADD(){
  Serial.print("ADD ");

  exeLDB();
  digitalWrite(SU,1);
  digitalWrite(EU,1);
  digitalWrite(LA,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.print("->");
  Serial.println(PINF);
  digitalWrite(LP,0);
  digitalWrite(LA,0);
  digitalWrite(EU,0);
  digitalWrite(SU,0);
}

void exeSUB(){
  Serial.print("SUB ");

  exeLDB();
  digitalWrite(RU,1);
  digitalWrite(EU,1);
  digitalWrite(LA,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.print("->");
  Serial.println(PINF);
  digitalWrite(LP,0);
  digitalWrite(LA,0);
  digitalWrite(EU,0);
  digitalWrite(RU,0);
}

void exeMULT(){
  Serial.print("MULT ");

  exeLDB();
  digitalWrite(MU,1);
  digitalWrite(EU,1);
  digitalWrite(LA,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.print("->");
  Serial.println(PINF);
  digitalWrite(LP,0);
  digitalWrite(LA,0);
  digitalWrite(EU,0);
  digitalWrite(MU,0);
}

void exeDIV(){
  Serial.print("DIV ");

  exeLDB();
  digitalWrite(DU,1);
  digitalWrite(EU,1);
  digitalWrite(LA,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.print("->");
  Serial.println(PINF);
  digitalWrite(LP,0);
  digitalWrite(LA,0);
  digitalWrite(EU,0);
  digitalWrite(DU,0);
}

void exeCALL(){
  Serial.print("CALL ");
  delay(clk);
  PCtemp = PC;
  
  digitalWrite(EI,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.println(PINF);
  PC = PINF-1;
  digitalWrite(LP,0);
  digitalWrite(EI,0);
  
  callmode = true;
}

void exeRTRN(){
  Serial.print("RTRN ");
  Serial.println(PCtemp);
  rtrnmode = true;
}

void exeGOTO(){
  Serial.print("GOTO ");
  delay(clk);
  PCtemp = PC;

  digitalWrite(EI,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.println(PINF);
  PC = PINF-1;
  digitalWrite(LP,0);
  digitalWrite(EI,0);
}

void exeOUT(){
  Serial.print("OUT ");

  digitalWrite(EA,1);
  digitalWrite(LO,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.println(PINF);
  digitalWrite(LP,0);
  digitalWrite(LO,0);
  digitalWrite(EA,0); 
}

void exeHLT(){
  Serial.println("HLT");
  Serial.println("Goodbye!");
  Serial.println("[EVG]");
  delay(clk);
  exit(1);
}

void exePOW(){
  Serial.print("POW ");
  int i = 0;
    
  digitalWrite(EA,1);
  digitalWrite(LB,1);
  delay(clk);
  digitalWrite(LB,0);
  digitalWrite(EA,0);
  
  digitalWrite(EI,1);
  digitalWrite(LM,1);
  delay(clk);
  digitalWrite(LM,0);
  digitalWrite(EI,0);
  
  digitalWrite(ER,1);
  digitalWrite(LP,1);
  delay(clk);
  i = PINF;
  Serial.println(i);
  digitalWrite(LP,0);
  digitalWrite(ER,0);

  for(i; i-- ; i>1){
    if(i<=1){
      break;
    }
    digitalWrite(MU,1);
    digitalWrite(EU,1);
    digitalWrite(LB,1);
    digitalWrite(LP,1);
    delay(clk);
    Serial.print("->");
    Serial.print(PINF);
    digitalWrite(LP,0);
    digitalWrite(LB,0);
    digitalWrite(EU,0);
    digitalWrite(MU,0);
  }
  digitalWrite(EU,1);
  digitalWrite(LA,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.print("->");
  Serial.println(PINF);
  digitalWrite(LP,0);
  digitalWrite(LA,0);
  digitalWrite(EU,0);
}

void exeGRTR(){
  Serial.print("GRTR ");

  exeLDB();
  digitalWrite(GU,1);
  digitalWrite(EU,1);
  digitalWrite(LA,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.print("->");
  if(PINF == 1){
    Serial.println("TRUE");
  }else{
    Serial.println("FALSE");
  }
  digitalWrite(LP,0);
  digitalWrite(LA,0);
  digitalWrite(EU,0);
  digitalWrite(GU,0);
  
}

void exeLOWR(){
  Serial.print("LOWR ");
  
  exeLDB();
  digitalWrite(LU,1);
  digitalWrite(EU,1);
  digitalWrite(LA,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.print("->");
  if(PINF == 1){
    Serial.println("TRUE");
  }else{
    Serial.println("FALSE");
  }
  digitalWrite(LP,0);
  digitalWrite(LA,0);
  digitalWrite(EU,0);
  digitalWrite(LU,0);
}

void exeMOD(){
  Serial.print("MOD ");

  digitalWrite(EA,1);
  digitalWrite(LC,1);
  delay(clk);
  digitalWrite(LC,0);
  digitalWrite(EA,0);
  
  exeLDB();
  digitalWrite(DU,1);
  digitalWrite(EU,1);
  digitalWrite(LA,1);
  delay(clk);
  digitalWrite(LA,0);
  digitalWrite(EU,0);
  digitalWrite(DU,0);

  digitalWrite(MU,1);
  digitalWrite(EU,1);
  digitalWrite(LB,1);
  delay(clk);
  digitalWrite(LB,0);
  digitalWrite(EU,0);
  digitalWrite(MU,0);

  digitalWrite(EC,1);
  digitalWrite(LA,1);
  delay(clk);
  digitalWrite(LA,0);
  digitalWrite(EC,0);

  digitalWrite(RU,1);
  digitalWrite(EU,1);
  digitalWrite(LA,1);
  digitalWrite(LP,1);
  delay(clk);
  Serial.print("->");
  Serial.println(PINF);
  digitalWrite(LP,0);
  digitalWrite(LA,0);
  digitalWrite(EU,0);
  digitalWrite(RU,0);
}

void exeFACT(){
  Serial.print("FACT ");
  int i = 0;

  digitalWrite(EI,1);
  digitalWrite(LM,1);
  delay(clk);
  digitalWrite(LM,0);
  digitalWrite(EI,0);
  
  digitalWrite(ER,1);
  digitalWrite(LA,1);
  digitalWrite(LB,1);
  digitalWrite(LC,1);
  digitalWrite(LP,1);
  delay(clk);
  i = PINF;
  Serial.println(i);
  digitalWrite(LP,0);
  digitalWrite(LC,0);
  digitalWrite(LB,0);
  digitalWrite(LA,0);
  digitalWrite(ER,0);
  
  for(i; i-- ; 1<i){
    if(i<=1){
      break;
    }
    digitalWrite(DU,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(clk);
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(DU,0);

    digitalWrite(RU,1);
    digitalWrite(EU,1);
    digitalWrite(LA,1);
    delay(clk);
    digitalWrite(LA,0);
    digitalWrite(EU,0);
    digitalWrite(RU,0);

    digitalWrite(EC,1);
    digitalWrite(LB,1);
    delay(clk);
    digitalWrite(LB,0);
    digitalWrite(EC,0);

    digitalWrite(MU,1);
    digitalWrite(EU,1);
    digitalWrite(LC,1);
    digitalWrite(LP,1);
    delay(clk);
    Serial.print("->");
    Serial.print(PINF);
    digitalWrite(LP,0);
    digitalWrite(LC,0);
    digitalWrite(EU,0);
    digitalWrite(MU,0);

    digitalWrite(EA,1);
    digitalWrite(LB,1);
    delay(clk);
    digitalWrite(LB,0);
    digitalWrite(EA,0);
  }
  Serial.println("");
  digitalWrite(EC,1);
  digitalWrite(LA,1);
  delay(clk);
  digitalWrite(LA,0);
  digitalWrite(EC,0);
}

//       -----------------------------------------

void loop() {
  PORTK = PC;
  digitalWrite(EP,1);
  digitalWrite(LM,1);
  delay(clk);
  digitalWrite(LM,0);
  digitalWrite(EP,0);
  digitalWrite(ER,1);
  digitalWrite(LI,1);
  delay(clk);
  digitalWrite(LI,0);
  digitalWrite(ER,0);
  
  Serial.print("PC: ");
  Serial.print(PC);
  Serial.print(" ,Orden: ");

  if(digitalRead(LDA) == 1){
    exeLDA();
  }else if(digitalRead(ADD) == 1){
    exeADD();
  }else if(digitalRead(SUB) == 1){
    exeSUB();
  }else if(digitalRead(MULT) == 1){
    exeMULT();
  }else if(digitalRead(DIV) == 1){
    exeDIV();
  }else if(digitalRead(CALL) == 1){
    exeCALL();
  }else if(digitalRead(RTRN) == 1){
    exeRTRN();
  }else if(digitalRead(GOTO) == 1){
    exeGOTO();
  }else if(digitalRead(OUT) == 1){
    exeOUT();
  }else if(digitalRead(HLT) == 1){
    exeHLT();
  }else if(digitalRead(POW) == 1){
    exePOW();
  }else if(digitalRead(GRTR) == 1){
    exeGRTR();
  }else if(digitalRead(LOWR) == 1){
    exeLOWR();
  }else if(digitalRead(MOD) == 1){
    exeMOD();
  }else if(digitalRead(FACT) == 1){
    exeFACT();
  }else{
    Serial.println("NONE");
  }

  if(rtrnmode == true){
    PC = PCtemp;
    rtrnmode = false;
  }
  if(callmode == true){
    rtrnmode = true;
    callmode = false;
  }

  delay(clk);
  PC++;
}
