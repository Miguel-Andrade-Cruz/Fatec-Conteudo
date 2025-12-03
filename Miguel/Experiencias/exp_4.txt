#define EX2

// 1. adicionar buzzer; Led aceso == buzzer apita
#ifdef EX1
//Sensor de luz

int ledPin = 13; //Led no pino 13
int ldrPin = 0; //LDR no pino analogico A0
int ldrValor = 0; //Valor lido do LDR
int buzzerPin = 8;

void setup() {
pinMode(ldrPin, INPUT);
pinMode(ledPin, OUTPUT); //define a porta 13 como saída
Serial.begin(9600); //Inicia a comunicação serial
pinMode(buzzerPin, OUTPUT);

}
void loop() {
  //ler o valor do LDR
  ldrValor = analogRead(ldrPin); //O valor lido sera entre 0 e 1023
  //imprime o valor lido do LDR no monitor serial
  Serial.println(ldrValor);
  //se o valor lido for maior que 500, liga o led
  if(ldrValor>= 500) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 400);
    // senão, apaga o led 
  }else {
    digitalWrite(ledPin,LOW);
    noTone(buzzerPin);

    }
  delay(100);
}
#endif

// 2. +2 leds; leds acendem conforme menos luminosidade;  último led aceso > buzzer apita.
#ifdef EX2
//Sensor de luz

int ledPin1 = 11; //Led no pino 13
int ledPin2 = 12; //Led no pino 13
int ledPin3 = 13; //Led no pino 13
int ldrPin = 0; //LDR no pino analogico A0
int ldrValor = 0; //Valor lido do LDR
int buzzerPin = 8;

void setup() {
pinMode(ldrPin, INPUT);
pinMode(ledPin1, OUTPUT); // Inicia led1
pinMode(ledPin2, OUTPUT); // Inicia led2
pinMode(ledPin3, OUTPUT); // Inicia led3
Serial.begin(9600); //Inicia a comunicação serial
pinMode(buzzerPin, OUTPUT);

}
void loop(){
  //ler o valor do LDR
  ldrValor = analogRead(ldrPin); //O valor lido sera entre 0 e 1023
  //imprime o valor lido do LDR no monitor serial
  Serial.println(ldrValor);
  //se o valor lido for maior que 500, liga o led

  if (ldrValor <= 500) { 
    digitalWrite(ledPin1, HIGH); 
  } else {
    digitalWrite(ledPin1, LOW);
  }
  if (ldrValor <= 333) { 
    digitalWrite(ledPin2, HIGH); 
  } else {
    digitalWrite(ledPin2, LOW);
  }
  if (ldrValor <= 167) { 
    digitalWrite(ledPin3, HIGH);
    tone(buzzerPin, 400); // buzzer só toca no último LED
  } else {
    digitalWrite(ledPin3, LOW);
    noTone(buzzerPin);
  }
  delay(100);
}
#endif

// 3. Função leitura do sensor de luminosidade (retorna valor lido)
#ifdef EX3
//Sensor de luz

int ledPin1 = 11; //Led no pino 11
int ledPin2 = 12; //Led no pino 12
int ledPin3 = 13; //Led no pino 13
int ldrPin = 0; //LDR no pino analogico A0
int ldrValor = 0; //Valor lido do LDR
int buzzerPin = 8;


void setup() {
pinMode(ldrPin, INPUT);
pinMode(ledPin1, OUTPUT); // Inicia led1
pinMode(ledPin2, OUTPUT); // Inicia led2
pinMode(ledPin3, OUTPUT); // Inicia led3
Serial.begin(9600); //Inicia a comunicação serial
pinMode(buzzerPin, OUTPUT);

}

int leituraLuminosidade() {
    return analogRead(ldrPin);
}

void loop(){
  ldrValor = leituraLuminosidade();
  Serial.println(ldrValor);

  if (ldrValor <= 500) { 
    digitalWrite(ledPin1, HIGH); 
  } else {
    digitalWrite(ledPin1, LOW);
  }
  if (ldrValor <= 333) { 
    digitalWrite(ledPin2, HIGH); 
  } else {
    digitalWrite(ledPin2, LOW);
  }
  if (ldrValor <= 167) { 
    digitalWrite(ledPin3, HIGH);
    tone(buzzerPin, 400); // buzzer só toca no último LED
  } else {
    digitalWrite(ledPin3, LOW);
    noTone(buzzerPin);
  }
  delay(100);
}
#endif

// 4. Controle dos leds são funções (recebe valor lido)
#ifdef EX4
//Sensor de luz

int ledPin1 = 11; //Led no pino 11
int ledPin2 = 12; //Led no pino 12
int ledPin3 = 13; //Led no pino 13
int ldrPin = 0; //LDR no pino analogico A0
int ldrValor = 0; //Valor lido do LDR
int buzzerPin = 8;

void setup() {
pinMode(ldrPin, INPUT);
pinMode(ledPin1, OUTPUT); // Inicia led1
pinMode(ledPin2, OUTPUT); // Inicia led2
pinMode(ledPin3, OUTPUT); // Inicia led3
Serial.begin(9600); //Inicia a comunicação serial
pinMode(buzzerPin, OUTPUT);

}

int leituraLuminosidade() {
    return analogRead(ldrPin);
}

void controlaLed(int pin, int limite, int valor) {
  if (valor <= limite) digitalWrite(pin, HIGH);
  else digitalWrite(pin, LOW);
}

void controlBuzzer(int valor) {
  if (valor <= 167) {
    tone(buzzerPin, 400);
  } else {
    noTone(buzzerPin);
  }
}

void loop(){
  ldrValor = leituraLuminosidade();
  Serial.println(ldrValor);
  controlaLed(ledPin1, 500, ldrValor);
  controlaLed(ledPin2, 333, ldrValor);
  controlaLed(ledPin3, 167, ldrValor);
  
  if (ldrValor <= 167) { 
    tone(buzzerPin, 400);
  } else {
    noTone(buzzerPin);
  }
  delay(100);
}
#endif

// 5. Controle do buzzer em unção (recebe valor lido)
#ifdef EX5
//Sensor de luz

int ledPin1 = 11; //Led no pino 11
int ledPin2 = 12; //Led no pino 12
int ledPin3 = 13; //Led no pino 13
int ldrPin = 0; //LDR no pino analogico A0
int ldrValor = 0; //Valor lido do LDR
int buzzerPin = 8;

void setup() {
pinMode(ldrPin, INPUT);
pinMode(ledPin1, OUTPUT); // Inicia led1
pinMode(ledPin2, OUTPUT); // Inicia led2
pinMode(ledPin3, OUTPUT); // Inicia led3
Serial.begin(9600); //Inicia a comunicação serial
pinMode(buzzerPin, OUTPUT);

}

int leituraLuminosidade() {
    return analogRead(ldrPin);
}

void controlaLed(int pin, int limite, int valor) {
  if (valor <= limite) digitalWrite(pin, HIGH);
  else digitalWrite(pin, LOW);
}

void controlBuzzer(int valor) {
  if (valor <= 167) {
    tone(buzzerPin, 400);
  } else {
    noTone(buzzerPin);
  }
}

void loop(){
  ldrValor = leituraLuminosidade();
  Serial.println(ldrValor);
  controlaLed(ledPin1, 500, ldrValor);
  controlaLed(ledPin2, 333, ldrValor);
  controlaLed(ledPin3, 167, ldrValor);
  controlBuzzer(ldrValor);
  delay(100);
}
#endif