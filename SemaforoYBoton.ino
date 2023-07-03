// ESTEBAN VERGARA GIRALDO

#define rojo 22
#define amarillo 23
#define verde 24

#define rojop 28
#define verdep 29

#define boton 37

int hinicial;
int hactual;
bool botonActivo;

void setup() {
  pinMode(rojo,OUTPUT);
  pinMode(amarillo,OUTPUT);
  pinMode(verde,OUTPUT);

  digitalWrite(rojo,LOW);
  digitalWrite(amarillo,LOW);
  digitalWrite(verde,LOW);

  pinMode(rojop,OUTPUT);
  pinMode(verdep,OUTPUT);

  digitalWrite(rojop,LOW);
  digitalWrite(verdep,LOW);

  pinMode(boton,INPUT);
}

void loop() {
  digitalWrite(verde,HIGH);
  digitalWrite(rojop,HIGH);

  hinicial = millis();
  hactual = millis();
  botonActivo = false;
  while(hactual-hinicial <= 10000  && !botonActivo){
     hactual = millis();
     botonActivo = digitalRead(boton);
  }
  
  digitalWrite(verde,LOW);
  for(int i = 0; i <= 3; i++){
    digitalWrite(verde,HIGH);
    delay(500);
    digitalWrite(verde,LOW);
    delay(1000);
  }
  digitalWrite(amarillo,HIGH);
  delay(1000);
  digitalWrite(amarillo,LOW);
  digitalWrite(rojo,HIGH);
  digitalWrite(rojop,LOW);
  digitalWrite(verdep,HIGH);
  delay(3000);
  for(int i = 0; i <= 3; i++){
    digitalWrite(verdep,HIGH);
    delay(1000);
    digitalWrite(verdep,LOW);
    delay(500);
  }
  digitalWrite(rojo,LOW);
}
