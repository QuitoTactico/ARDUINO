#define BUTTON 34 //START-STOP
#define AI0 0 //NIVEL AGUA
#define DO30 30 //AGITADOR
#define DO31 31 //DESCANSO
#define DO32 32 //FIN AGITADOR

unsigned int nivelalto = 800;
unsigned int tanquevacio = 0;
unsigned int nivelagua = 0;
bool encendido = false;
bool esperando = false;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON,INPUT);
 
  pinMode(DO30,OUTPUT);
  pinMode(DO31,OUTPUT);
  pinMode(DO32,OUTPUT);

  digitalWrite(DO30,LOW);
  digitalWrite(DO31,LOW);
  digitalWrite(DO32,LOW);
}

void loop() {
  nivelagua = analogRead(AI0);
  encendido = digitalRead(BUTTON) == HIGH;
  if(encendido = true){
   
    if(nivelagua >= nivelalto && esperando == false){
      for(int i = 0; i < 5 ; i++ ){
        digitalWrite(DO30,HIGH);
        delay(3000);
        digitalWrite(DO30,LOW);
        digitalWrite(DO31,HIGH);
        delay(1000);
        digitalWrite(DO31,LOW);
      }
      esperando = true;
    }
    if(esperando == true){
      digitalWrite(DO32,HIGH);
      if(nivelagua <= tanquevacio){
        esperando = false;
        digitalWrite(DO32,LOW);
      }
    }
  if(encendido = false){
    digitalWrite(DO30,LOW);
    digitalWrite(DO31,LOW);
    digitalWrite(DO32,LOW);
  }
  delay(50);
  }
}
