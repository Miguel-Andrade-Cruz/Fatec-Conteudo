#define EX5

// TMP36 - Sensor de temperatura
#ifdef EX0
int TMP = A0; 
float temperatura, tensao;
int leitura;
int ledPin = 13;

void setup() {
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}

void loop() {//  2 – Acrescente mais 2 leds a montagem. Conforme a temperatura aumenta os
//  leds vão acendendo progressivamente. O buzzer deve apitar quando o último led acender.

leitura = analogRead(TMP);
temperatura = ((float(leitura) * 5 / 1023) -0.5) * 100; 
Serial.print("Temperatura: ");
Serial.println(temperatura);
//se o valor lido for maior que 27, liga o led
 if (temperatura >= 27) {
    digitalWrite(ledPin,HIGH);
      }
 // senão, apaga o led
 else {
    digitalWrite(ledPin,LOW);
      }
delay(100);
}
#endif



// -------------------------------------------------------
// -------------------------------------------------------



#ifdef EX1
//  1. +buzzer; led acende > buzzer apita
int TMP = A0; 
float temperatura, tensao;
int leitura;
int ledPin = 13;
int buzzerPin = 7;

void setup() {
pinMode(ledPin, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
leitura = analogRead(TMP);
temperatura = ((float(leitura) * 5 / 1023) -0.5) * 100; 
Serial.print("Temperatura: ");
Serial.println(temperatura);
//se o valor lido for maior que 27, liga o led
 if (temperatura >= 27) {
  digitalWrite(ledPin,HIGH);
  tone(buzzerPin, 400);
  }
 // senão, apaga o led
 else {
  digitalWrite(ledPin,LOW);
  noTone(buzzerPin);
  }
delay(100);
}
#endif



// -------------------------------------------------------
// -------------------------------------------------------



#ifdef EX2
//  2 – Acrescente mais 2 leds a montagem. Conforme a temperatura aumenta os
//  leds vão acendendo progressivamente. O buzzer deve apitar quando o último led acender.
int TMP = A0; 
float temperatura, tensao;
int leitura;
int ledPin1 = 11;
int ledPin2 = 12;
int ledPin3 = 13;
int buzzerPin = 7;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
leitura = analogRead(TMP);
temperatura = ((float(leitura) * 5 / 1023) -0.5) * 100; 
Serial.print("Temperatura: ");
Serial.println(temperatura);
  if (temperatura >= 7) { 
    digitalWrite(11, HIGH); 
  } else {
    digitalWrite(ledPin1, LOW);
  }
  if (temperatura >= 17) { 
    digitalWrite(ledPin2, HIGH); 
  } else {
    digitalWrite(ledPin2, LOW);
  }
  if (temperatura >= 27) { 
    digitalWrite(ledPin3, HIGH);
    tone(buzzerPin, 400); // buzzer só toca no último LED
  } else {
    digitalWrite(ledPin3, LOW);
    noTone(buzzerPin);
  }
  delay(100);
}
#endif



// -------------------------------------------------------
// -------------------------------------------------------



#ifdef EX3
// 3. Leitura do sensor de temp em uma função que retorna o valor
int TMP = A0; 
float temperatura, tensao;
int ledPin1 = 11;
int ledPin2 = 12;
int ledPin3 = 13;
int buzzerPin = 7;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

int leituraTemp() {
    return ((float(analogRead(TMP)) * 5 / 1023) -0.5) * 100; 
}

void loop() {
temperatura = leituraTemp();
Serial.print("Temperatura: ");
Serial.println(temperatura);
  if (temperatura >= 7) { 
    digitalWrite(ledPin1, HIGH); 
  } else {
    digitalWrite(ledPin1, LOW);
  }
  if (temperatura >= 17) { 
    digitalWrite(ledPin2, HIGH); 
  } else {
    digitalWrite(ledPin2, LOW);
  }
  if (temperatura >= 27) { 
    digitalWrite(ledPin3, HIGH);
    tone(buzzerPin, 400); // buzzer só toca no último LED
  } else {
    digitalWrite(ledPin3, LOW);
    noTone(buzzerPin);
  }
  delay(100);
}
#endif



// -------------------------------------------------------
// -------------------------------------------------------



#ifdef EX4
// 4. Controla led funcao (recebe valor lido)
int TMP = A0; 
float temperatura, tensao;
int ledPin1 = 11;
int ledPin2 = 12;
int ledPin3 = 13;
int buzzerPin = 7;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

int leituraTemp() {
    return ((float(analogRead(TMP)) * 5 / 1023) -0.5) * 100; 
}

void controlaLed1(int valor) {
  if (valor >= 7) digitalWrite(ledPin1, HIGH);
  else digitalWrite(ledPin1, LOW);
}

void controlaLed2(int valor) {
  if (valor >= 17) digitalWrite(ledPin2, HIGH);
  else digitalWrite(ledPin2, LOW);
}

void controlaLed3(int valor) {
  if (valor >= 27) digitalWrite(ledPin3, HIGH);
  else digitalWrite(ledPin3, LOW);
}

void loop() {
  temperatura = leituraTemp();
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  controlaLed1(temperatura);
  controlaLed2(temperatura);
  controlaLed3(temperatura);

  if (temperatura >= 27) { 
    tone(buzzerPin, 400); // buzzer só toca no último LED
  } else {
    noTone(buzzerPin);
  }
  delay(100);
}
#endif



// -------------------------------------------------------
// -------------------------------------------------------



#ifdef EX5
// 5. Controla buzzer funcao (recebe valor lido)
int TMP = A0; 
float temperatura, tensao;
int ledPin1 = 11;
int ledPin2 = 12;
int ledPin3 = 13;
int buzzerPin = 7;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

int leituraTemp() {
    return ((float(analogRead(TMP)) * 5 / 1023) -0.5) * 100; 
}

void controlaLed1(int valor) {
  if (valor >= 7) digitalWrite(ledPin1, HIGH);
  else digitalWrite(ledPin1, LOW);
}

void controlaLed2(int valor) {
  if (valor >= 17) digitalWrite(ledPin2, HIGH);
  else digitalWrite(ledPin2, LOW);
}

void controlaLed3(int valor) {
  if (valor >= 27) digitalWrite(ledPin3, HIGH);
  else digitalWrite(ledPin3, LOW);
}

void controlaBuzzer(int valor) {
  if (valor >= 27) {
    tone(buzzerPin, 400);
  } else {
    noTone(buzzerPin);
  }
}


void loop() {
  temperatura = leituraTemp();
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  controlLed1(temperatura);
  controlaLed2(temperatura);
  controlaLed3(temperatura);
  controlaBuzzer(temperatura);
  delay(100);
}
#endif