// ESTEBAN VERGARA GIRALDO
#define mayor 37
int win = 0;
int lose = 0;

void setup() {
  pinMode(mayor,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("37 ON  = mayor que 3\n37 OFF = menor que 3\n");

  randomSeed(millis());
  int num = random(0,6);

  if(digitalRead(mayor)){
    Serial.println("       [MAYOR]       ");
  }else{
    Serial.println("       [MENOR]       ");
  }
  
  if((digitalRead(mayor) && num >= 3)||(!digitalRead(mayor) && num < 3)){
    Serial.print("¡GANASTE!, el numero fue ");
    win++;
  }else{
    Serial.print("PERDISTE... el numero fue ");
    lose++;
  }
  Serial.println(num);
  Serial.print("\nWin: ");
  Serial.print(win);
  Serial.print("   |    Lose: ");
  Serial.println(lose);
  Serial.println("\n---------------------------\n");

  delay(6000);
}
