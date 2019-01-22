const int MAX_SENS = 6;
String result[MAX_SENS];
int index = 0;

void setup() {
  Serial.begin(9600);

  //printInit();
  
  // LEDS
  testLed(6, "RGB BD6 (Azul)");
  testLed(5, "RGB GD5 (Verde)");
  testLed(9, "RGB RD9 (Rojo)");
  testLed(13, "LED D13 (Rojo)");
  testLed(12, "LED D12 (Naranja)");
  testLed(11, "LED D11 (Verde)");

  printResult();
}

void loop() {
}


void testLed(int pin, String text) {
  Serial.println("¿Está encendido el " + text + "?");

  analogWrite(pin, 255);
  saveResult(isCorrect(), text);
  analogWrite(pin, 0);
}



bool isCorrect() {
  const int SR = 2, SL = 3;
  bool ok, ko;

  Serial.println("- Pulsa SR si es correcto");
  Serial.println("- Pulsa SL si no es correcto");

  do {
    delay(1);
    ok = digitalRead(SR) == HIGH;
    ko = digitalRead(SL) == HIGH;
  } while (!ok && !ko);

  if(ok) return true;
  if(ko) return false;
}

void saveResult(bool op, String text) {
  String aux = op ? "✓" : "✗";
  aux+= " -> ";
  aux+= text;
  result[index++] = aux;

  printSpace();
  delay(1000);
}



void printInit() {
  Serial.println("---------------------------------------------------");
  Serial.println("El test de EchidnaShield empezará en 5 segundos ...");
  Serial.println("---------------------------------------------------");
  delay(5000);
}

void printSpace() {
  Serial.println("\n");
}

void printResult() {
  Serial.println("----------------------------------------------");
  Serial.println("El resultado del test ha sido el siguiente ...");
  for(int i=0; i<MAX_SENS; i++) {
    Serial.println(result[i]);
  }
  Serial.println("----------------------------------------------");
}
