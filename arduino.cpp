// C++ code
//
#include <LiquidCrystal.h>
//LiquidCrystal lcd(RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(13, 12, 6, 5, 4, 3);

int optionA=0;
int optionB=0;
int optionC=0;
int optionD=0;

bool encendido = false;

String respuestas[10] = {"D", "A", "A", "C", "D", "B", "A", "B", "B", "C"};

void setup()
{
  Serial.begin(9600);
  // OUTPUT OPTIONS
  pinMode(11, OUTPUT); // A
  pinMode(10, OUTPUT); // B
  pinMode(9, OUTPUT);  // C
  pinMode(8, OUTPUT);  // D
  // INPUT OPTIONS
  pinMode(A0, INPUT);  // A
  pinMode(A1, INPUT);  // B
  pinMode(A2, INPUT);  // C
  pinMode(A3, INPUT);  // D
  
  // PIN BOTON
  pinMode(A4, INPUT);
  // LED BOTON
  pinMode(7, OUTPUT);
  
  // LCD
  lcd.begin(16, 2); 
}

void loop()
{
  bool boton = digitalRead(A4);
  
  digitalWrite(7, boton);

  lcd.setCursor(0,0);
  lcd.print("");
  lcd.setCursor(2, 1);
  lcd.print("");
  if (boton) {
    optionA = analogRead(A0);
    optionB = analogRead(A1);
    optionC = analogRead(A2);
    optionD = analogRead(A3);

    if(optionA<10) digitalWrite(11, HIGH);
    else digitalWrite(11, LOW);

    if(optionB<10) digitalWrite(10, HIGH);
    else digitalWrite(10, LOW);

    if(optionC<10) digitalWrite(9, HIGH);
    else digitalWrite(9, LOW);

    if(optionD<10) digitalWrite(8, HIGH);
    else digitalWrite(8, LOW);
    
    String respuesta = "A";
    
    lcd.setCursor(0,0); 
    lcd.print("Respuesta: " + respuesta);
    lcd.setCursor(2,1);
    if (optionA) {
      lcd.print("Elegida: A");
    } else if (optionB) {
      lcd.print("Elegida: B");
    } else if (optionC) {
      lcd.print("Elegida: C");
    } else if (optionD) {
      lcd.print("Elegida: D");
    }
  }
}