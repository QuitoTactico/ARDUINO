//Definicion de pines de I/O
#define pA 29
#define pB 28
#define pC 27
#define pD 26
#define pE 25
#define pF 24
#define pG 23

#define LR 2
#define LG 3
#define LB 4

#define S1 34
#define S2 35
#define S3 36

//Definicion de variables
unsigned int cont = 0;
void int2bcd(unsigned int num) //Función que toma un numero entero y lo convierte a BCD
{
switch (num)
{
case 0:
digitalWrite(pA, HIGH);
digitalWrite(pB, HIGH);
digitalWrite(pC, HIGH);
digitalWrite(pD, HIGH);
digitalWrite(pE, HIGH);
digitalWrite(pF, HIGH);
digitalWrite(pG, LOW);
break;
case 1:
digitalWrite(pA, LOW);
digitalWrite(pB, HIGH);
digitalWrite(pC, HIGH);
digitalWrite(pD, LOW);
digitalWrite(pE, LOW);
digitalWrite(pF, LOW);
digitalWrite(pG, LOW);
break;
case 2:
digitalWrite(pA, HIGH);
digitalWrite(pB, HIGH);
digitalWrite(pC, LOW);
digitalWrite(pD, HIGH);
digitalWrite(pE, HIGH);
digitalWrite(pF, LOW);
digitalWrite(pG, HIGH);
break;
case 3:
digitalWrite(pA, HIGH);
digitalWrite(pB, HIGH);
digitalWrite(pC, HIGH);
digitalWrite(pD, HIGH);
digitalWrite(pE, LOW);
digitalWrite(pF, LOW);
digitalWrite(pG, HIGH);
break;
case 4:
digitalWrite(pA, LOW);
digitalWrite(pB, HIGH);
digitalWrite(pC, HIGH);
digitalWrite(pD, LOW);
digitalWrite(pE, LOW);
digitalWrite(pF, HIGH);
digitalWrite(pG, HIGH);
break;
case 5:
digitalWrite(pA, HIGH);
digitalWrite(pB, LOW);
digitalWrite(pC, HIGH);
digitalWrite(pD, HIGH);
digitalWrite(pE, LOW);
digitalWrite(pF, HIGH);
digitalWrite(pG, HIGH);
break;
case 6:
digitalWrite(pA, HIGH);
digitalWrite(pB, LOW);
digitalWrite(pC, HIGH);
digitalWrite(pD, HIGH);
digitalWrite(pE, HIGH);
digitalWrite(pF, HIGH);
digitalWrite(pG, HIGH);
break;
case 7:
digitalWrite(pA, HIGH);
digitalWrite(pB, HIGH);
digitalWrite(pC, HIGH);
digitalWrite(pD, LOW);
digitalWrite(pE, LOW);
digitalWrite(pF, LOW);
digitalWrite(pG, LOW);
break;
case 8:
digitalWrite(pA, HIGH);
digitalWrite(pB, HIGH);
digitalWrite(pC, HIGH);
digitalWrite(pD, HIGH);
digitalWrite(pE, HIGH);
digitalWrite(pF, HIGH);
digitalWrite(pG, HIGH);
break;
case 9:
digitalWrite(pA, HIGH);
digitalWrite(pB, HIGH);
digitalWrite(pC, HIGH);
digitalWrite(pD, LOW);
digitalWrite(pE, LOW);
digitalWrite(pF, HIGH);
digitalWrite(pG, HIGH);
break;
}
}

void setup()
{
    pinMode(pA, OUTPUT);
    pinMode(pB, OUTPUT);
    pinMode(pC, OUTPUT);
    pinMode(pD, OUTPUT);
    pinMode(pE, OUTPUT);
    pinMode(pF, OUTPUT);
    pinMode(pG, OUTPUT);
    digitalWrite(pA, LOW);
    digitalWrite(pB, LOW);
    digitalWrite(pC, LOW);
    digitalWrite(pD, LOW);
    digitalWrite(pE, LOW);
    digitalWrite(pF, LOW);
    digitalWrite(pG, LOW);
    Serial.begin(9600);

    pinMode(LR, OUTPUT); //Segmento rojo como salida
    pinMode(LG, OUTPUT); //Segmento verde como salida
    pinMode(LB, OUTPUT); //Segmento azul como salida
    //Limpieza de salidas fisicas
    digitalWrite(LR, LOW); //Apago segmento rojo
    digitalWrite(LG, LOW); //Apago segmento rojo
    digitalWrite(LB, LOW); //Apago segmento rojo

    pinMode(S1, INPUT); //Segmento rojo como salida
    pinMode(S2, INPUT); //Segmento verde como salida
    pinMode(S3, INPUT); //Segmento azul como salida
}

void loop()
{
    bool s1 = digitalRead(S1) == HIGH;
    bool s2 = digitalRead(S2) == HIGH;
    bool s3 = digitalRead(S3) == HIGH;

    if (!s1 && !s2 && !s3){
      int2bcd(0);
      analogWrite(LR, 0);
      analogWrite(LG, 0);
      analogWrite(LB, 0);
    }
    if (s1 && !s2 && !s3){
      int2bcd(1);
      analogWrite(LR, 150);
      analogWrite(LG, 0);
      analogWrite(LB, 0);
    }
    if (!s1 && s2 && !s3){
      int2bcd(2);
      analogWrite(LR, 0);
      analogWrite(LG, 150);
      analogWrite(LB, 0);
    }
    if (s1 && s2 && !s3){
      int2bcd(3);
      analogWrite(LR, 150);
      analogWrite(LG, 150);
      analogWrite(LB, 0);
    }
    if (!s1 && !s2 && s3){
      int2bcd(4);
      analogWrite(LR, 0);
      analogWrite(LG, 0);
      analogWrite(LB, 150);
    }
    if (s1 && !s2 && s3){
      int2bcd(5);
      analogWrite(LR, 150);
      analogWrite(LG, 0);
      analogWrite(LB, 150);
    }
    if (!s1 && s2 && s3){
      int2bcd(6);
      analogWrite(LR, 0);
      analogWrite(LG, 150);
      analogWrite(LB, 150);
    }
    if (s1 && s2 && s3){
      int2bcd(7);
      analogWrite(LR, 150);
      analogWrite(LG, 150);
      analogWrite(LB, 150);
    }
   
   
    delay(50); //Retardo de 1 segundo
}
