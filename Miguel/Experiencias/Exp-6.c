#define EX1

// 1. +1 led; 2 leds controlados pelo potenciometro
#ifdef EX1
int ledPin1 = 5;
int ledPin2 = 9;
int pwmPin = A0;
unsigned int valorLido;
unsigned int pwm;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
Serial.begin(9600);
}

void loop() {
valorLido = analogRead(pwmPin); // valor entre 0 e 1023
Serial.println(valorLido);
pwm = map(valorLido, 0, 1023, 0, 255); // Mudança de escala

analogWrite(ledPin1,pwm);
analogWrite(ledPin2,pwm);
}
#endif

// 2. Leds funcionam invertido; Variação do potenciometro: 1 led vai acendendo e o outro apagando.
#ifdef EX2
int ledPin1 = 5;
int ledPin2 = 9;
int pwmPin = A0;
unsigned int valorLido;
unsigned int pwm;
unsigned int pwmInvertido;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
Serial.begin(9600);
}

void loop() {
valorLido = analogRead(pwmPin); // valor entre 0 e 1023
Serial.println(valorLido);
pwm = map(valorLido, 0, 1023, 0, 255); // Mudança de escala
pwmInvertido = 255 - pwm; 

analogWrite(ledPin1,pwm);
analogWrite(ledPin2,pwmInvertido);

}
#endif

// 3. +1 led; 3 leds controlados pelo potenciometro, acendendo progressivamente. 
#ifdef EX3
int buzzerPin = 4;
int ledPin1 = 5;
int ledPin2 = 9;
int ledPin3 = 10;
int pwmPin = A0;
unsigned int valorLido;
unsigned int pwm;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
Serial.begin(9600);
}

void loop() {
valorLido = analogRead(pwmPin); // valor entre 0 e 1023
Serial.println(valorLido);
pwm = map(valorLido, 0, 1023, 0, 255); // Mudança de escala

  int pwm1;
  if (pwm <= 85) {
    pwm1 = map(pwm, 0, 85, 0, 255);
  } else {
    pwm1 = 255;
  }
  analogWrite(ledPin1, pwm1);

  int pwm2;
  if (pwm <= 85) {
    pwm2 = 0; 
  } 
  else if (pwm <= 170) {
    pwm2 = map(pwm - 85, 0, 85, 0, 255);
  } 
  else {
    pwm2 = 255;
  }
  analogWrite(ledPin2, pwm2);

  int pwm3;
  if (pwm <= 170) {
    pwm3 = 0;
  }
  else if (pwm <= 255) {
    pwm3 = map(pwm - 170, 0, 85, 0, 255);
  }
  else {
    pwm3 = 255;
  }
  analogWrite(ledPin3, pwm3);

  delay(100);
}

#endif

// 4. +buzzer; quando o ultimo led acenter > buzzer apita.
#ifdef EX4
int buzzerPin = 4;
int ledPin1 = 5;
int ledPin2 = 9;
int ledPin3 = 10;
int pwmPin = A0;
unsigned int valorLido;
unsigned int pwm;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
valorLido = analogRead(pwmPin); // valor entre 0 e 1023
Serial.print("pwmPin: ");
Serial.print(valorLido);
pwm = map(valorLido, 0, 1023, 0, 255); // Mudança de escala
Serial.print(" | pwmMap: ");
Serial.println(pwm);
  int pwm1;
  if (pwm <= 85) {
    pwm1 = map(pwm, 0, 85, 0, 255);
  } else {
    pwm1 = 255;
  }
  analogWrite(ledPin1, pwm1);

  int pwm2;
  if (pwm <= 85) {
    pwm2 = 0; 
  } 
  else if (pwm <= 170) {
    pwm2 = map(pwm - 85, 0, 85, 0, 255);
  } 
  else {
    pwm2 = 255;
  }
  analogWrite(ledPin2, pwm2);

  int pwm3;
  if (pwm <= 170) {
    pwm3 = 0;
  }
  else if (pwm <= 255) {
    pwm3 = map(pwm - 170, 0, 85, 0, 255);
  }
  else {
    pwm3 = 255;
  }
  analogWrite(ledPin3, pwm3);

  analogWrite(ledPin3, pwm3);

  if (pwm >= 170) {
    tone(buzzerPin, 400); // buzzer só toca no último LED
  } else {
    noTone(buzzerPin);
  }

  delay(100);
}
#endif

// 5. Função ler potenciometro.
#ifdef EX5
int buzzerPin = 4;
int ledPin1 = 5;
int ledPin2 = 9;
int ledPin3 = 10;
int pwmPin = A0;
unsigned int valorLido;
unsigned int pwm;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

int lerPotenciometro(){
    return analogRead(pwmPin); // valor entre 0 e 1023
}

void loop() {
valorLido = lerPotenciometro();
Serial.print("pwmPin: ");
Serial.print(valorLido);
pwm = map(valorLido, 0, 1023, 0, 255); // Mudança de escala
Serial.print(" | pwmMap: ");
Serial.println(pwm);
  int pwm1;
  if (pwm <= 85) {
    pwm1 = map(pwm, 0, 85, 0, 255);
  } else {
    pwm1 = 255;
  }
  analogWrite(ledPin1, pwm1);

  int pwm2;
  if (pwm <= 85) {
    pwm2 = 0; 
  } 
  else if (pwm <= 170) {
    pwm2 = map(pwm - 85, 0, 85, 0, 255);
  } 
  else {
    pwm2 = 255;
  }
  analogWrite(ledPin2, pwm2);

  int pwm3;
  if (pwm <= 170) {
    pwm3 = 0;
  }
  else if (pwm <= 255) {
    pwm3 = map(pwm - 170, 0, 85, 0, 255);
  }
  else {
    pwm3 = 255;
  }
  analogWrite(ledPin3, pwm3);

  if (pwm >= 170) {
    tone(buzzerPin, 400); // buzzer só toca no último LED
  } else {
    noTone(buzzerPin);
  }

  delay(100);
}
#endif

// 6. Função mudar escala (cálculo).
#ifdef EX6
int buzzerPin = 4;
int ledPin1 = 5;
int ledPin2 = 9;
int ledPin3 = 10;
int pwmPin = A0;
unsigned int valorLido;
unsigned int pwm;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

int lerPotenciometro(){
    return analogRead(pwmPin); // valor entre 0 e 1023
}

int mudarEscala(int valor){
    return map(valor, 0, 1023, 0, 255); // Mudança de escala
}

void loop() {
valorLido = lerPotenciometro();
Serial.print("pwmPin: ");
Serial.print(valorLido);
pwm = mudarEscala(valorLido);
Serial.print(" | pwmMap: ");
Serial.println(pwm);
  int pwm1;
  if (pwm <= 85) {
    pwm1 = map(pwm, 0, 85, 0, 255);
  } else {
    pwm1 = 255;
  }
  analogWrite(ledPin1, pwm1);

  int pwm2;
  if (pwm <= 85) {
    pwm2 = 0; 
  } 
  else if (pwm <= 170) {
    pwm2 = map(pwm - 85, 0, 85, 0, 255);
  } 
  else {
    pwm2 = 255;
  }
  analogWrite(ledPin2, pwm2);

  int pwm3;
  if (pwm <= 170) {
    pwm3 = 0;
  }
  else if (pwm <= 255) {
    pwm3 = map(pwm - 170, 0, 85, 0, 255);
  }
  else {
    pwm3 = 255;
  }
  analogWrite(ledPin3, pwm3);

  if (pwm >= 170) {
    tone(buzzerPin, 400); // buzzer só toca no último LED
  } else {
    noTone(buzzerPin);
  }

  delay(100);
}
#endif

// 7. Função controlLed.
#ifdef EX7
int buzzerPin = 4;
int ledPin1 = 5;
int ledPin2 = 9;
int ledPin3 = 10;
int pwmPin = A0;
unsigned int valorLido;
unsigned int pwm;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

int lerPotenciometro(){
    return analogRead(pwmPin); // valor entre 0 e 1023
}

int mudarEscala(int valor, int min, int max) {
  return map(valor, min, max, 0, 255);
}

void controlLed(int pwm, int ledPin, int ledIndex) {
  int pwmLed = 0;

  if (ledIndex == 1) {
    if (pwm <= 85) {
      pwmLed = mudarEscala(pwm, 0, 85);
    } else {
      pwmLed = 255;
    }
  }

  if (ledIndex == 2) {
    if (pwm > 85 && pwm <= 170) {
      pwmLed = mudarEscala(pwm, 86, 170);
    } else if (pwm > 170) {
      pwmLed = 255;
    }
  }

  if (ledIndex == 3) {
    if (pwm > 170) {
      pwmLed = mudarEscala(pwm, 171, 255);
    }
  }

  analogWrite(ledPin, pwmLed);
}

void loop() {
valorLido = lerPotenciometro();
Serial.print("pwmPin: ");
Serial.print(valorLido);
pwm = mudarEscala(valorLido, 0, 1023); // escala principal
Serial.print(" | pwmMap: ");
Serial.println(pwm);

  controlLed(pwm, ledPin1, 1);
  controlLed(pwm, ledPin2, 2);
  controlLed(pwm, ledPin3, 3);

  if (pwm >= 170) {
    tone(buzzerPin, 400); // buzzer só toca no último LED
  } else {
    noTone(buzzerPin);
  }

  delay(100);
}
#endif

// 8. Função controlBuzzer.
#ifdef EX8
int buzzerPin = 4;
int ledPin1 = 5;
int ledPin2 = 9;
int ledPin3 = 10;
int pwmPin = A0;
unsigned int valorLido;
unsigned int pwm;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

int lerPotenciometro(){
    return analogRead(pwmPin); // valor entre 0 e 1023
}

int mudarEscala(int valor, int min, int max) {
  return map(valor, min, max, 0, 255);
}

void controlLed(int pwm, int ledPin, int ledIndex) {
  int pwmLed = 0;

  if (ledIndex == 1) {
    if (pwm <= 85) {
      pwmLed = mudarEscala(pwm, 0, 85);
    } else {
      pwmLed = 255;
    }
  }

  if (ledIndex == 2) {
    if (pwm > 85 && pwm <= 170) {
      pwmLed = mudarEscala(pwm, 86, 170);
    } else if (pwm > 170) {
      pwmLed = 255;
    }
  }

  if (ledIndex == 3) {
    if (pwm > 170) {
      pwmLed = mudarEscala(pwm, 171, 255);
    }
  }

  analogWrite(ledPin, pwmLed);
}

void controlBuzzer(int pwm) {
  if (pwm >= 170) {
    tone(buzzerPin, 400);
  } else {
    noTone(buzzerPin);
  }
}

void loop() {
valorLido = lerPotenciometro();
Serial.print("pwmPin: ");
Serial.print(valorLido);
pwm = mudarEscala(valorLido, 0, 1023); // escala principal
Serial.print(" | pwmMap: ");
Serial.println(pwm);

  controlLed(pwm, ledPin1, 1);
  controlLed(pwm, ledPin2, 2);
  controlLed(pwm, ledPin3, 3);

  controlBuzzer(pwm);
  delay(100);
}
#endif

// 9. Função escrita no Led. (Já implementado a partir do exercicio 7)
#ifdef EX9
int buzzerPin = 4;
int ledPin1 = 5;
int ledPin2 = 9;
int ledPin3 = 10;
int pwmPin = A0;
unsigned int valorLido;
unsigned int pwm;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
}

int lerPotenciometro(){
    return analogRead(pwmPin); // valor entre 0 e 1023
}

int mudarEscala(int valor, int min, int max) {
  return map(valor, min, max, 0, 255);
}

void controlLed(int pwm, int ledPin, int ledIndex) {
  int pwmLed = 0;

  if (ledIndex == 1) {
    if (pwm <= 85) {
      pwmLed = mudarEscala(pwm, 0, 85);
    } else {
      pwmLed = 255;
    }
  }

  if (ledIndex == 2) {
    if (pwm > 85 && pwm <= 170) {
      pwmLed = mudarEscala(pwm, 86, 170);
    } else if (pwm > 170) {
      pwmLed = 255;
    }
  }

  if (ledIndex == 3) {
    if (pwm > 170) {
      pwmLed = mudarEscala(pwm, 171, 255);
    }
  }

  analogWrite(ledPin, pwmLed);
}

void controlBuzzer(int pwm) {
  if (pwm >= 170) {
    tone(buzzerPin, 400);
  } else {
    noTone(buzzerPin);
  }
}

void loop() {
valorLido = lerPotenciometro();
Serial.print("pwmPin: ");
Serial.print(valorLido);
pwm = mudarEscala(valorLido, 0, 1023); // escala principal
Serial.print(" | pwmMap: ");
Serial.println(pwm);

  controlLed(pwm, ledPin1, 1);
  controlLed(pwm, ledPin2, 2);
  controlLed(pwm, ledPin3, 3);

  controlBuzzer(pwm);
  delay(100);
}
#endif
