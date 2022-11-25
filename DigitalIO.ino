//Definición de pines de I/O
#define DI0 34//Potenciómetro conectado en el pin A0
#define DO0 31//Potenciómetro conectado en el pin A0

//Definición de variables
unsigned int medicion = 0; //Variable creada para almacenar la medición de la entrada A0

//Configuración
void setup() 
{
    //Comunicaciones
    Serial.begin(9600); //Inicio comunicaciones on el PC (Serial0) a 9600 bauds
    pinMode(DI0,INPUT);
    pinMode(DO0,OUTPUT);

    digitalWrite(DO0,LOW);
}

void loop() 
{
  // put your main code here, to run repeatedly:
     if(digitalRead(DI0)==HIGH)
     {
        digitalWrite(DO0,HIGH); 
     }
     else
     {
        digitalWrite(DO0,LOW);
     }
     delay(500);
}
