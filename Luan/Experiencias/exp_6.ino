#define EX1

// 1. +1 led; 2 leds controlados pelo potenciometro
#ifdef EX1
int ledPin1 = 11;
int ledPin2 = 10;
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
    
    Serial.print("pwmPin: ");
    Serial.print(valorLido);
    Serial.print(" | pwmMap: ");
    Serial.println(valorLido);
    
    pwm = map(valorLido, 0, 1023, 0, 255); // Mudança de escala
    
    analogWrite(ledPin1,pwm);
    analogWrite(ledPin2,pwm);
}
#endif



// ---------------------------------------------------------------------
// ---------------------------------------------------------------------


#ifdef EX2
// 2. Leds funcionam invertido; Variação do potenciometro: 1 led vai acendendo e o outro apagando.
int ledPin1 = 11;
int ledPin2 = 10;
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
    
    Serial.print("pwmPin: ");
    Serial.print(valorLido);
    Serial.print(" | pwmMap: ");
    Serial.println(valorLido);
    
    pwm = map(valorLido, 0, 1023, 0, 255); // Mudança de escala
    pwmInvertido = 255 - pwm; 
    
    analogWrite(ledPin1,pwm);
    analogWrite(ledPin2,pwmInvertido);

}
#endif



// ---------------------------------------------------------------------
// ---------------------------------------------------------------------



#ifdef EX3
// 3. +1 led; 3 leds controlados pelo potenciometro, acendendo progressivamente. 
int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
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
    
    Serial.print("pwmPin: ");
    Serial.print(valorLido);
    Serial.print(" | pwmMap: ");
    Serial.println(valorLido);

    pwm = map(valorLido, 0, 1023, 0, 255); // Mudança de escala

    int pwm_led_2, pwm_led_3;
    
    analogWrite(ledPin1, pwm);

    if (pwm >= 63) {
        pwm_led_2 = map(pwm, 63, 255, 0, 255); 
    } 
    else {
        pwm_led_2 = 0;
    }
    analogWrite(ledPin2, pwm_led_2);
    
    if (pwm >= 127) {
        pwm_led_3 = map(pwm, 127, 255, 0, 255); 
    } else {
        pwm_led_3 = 0;
    }
    analogWrite(ledPin3, pwm_led_3);
    
    delay(100);
}

#endif



// ---------------------------------------------------------------------
// ---------------------------------------------------------------------



#ifdef EX4
// 4. +buzzer; quando o ultimo led acenter > buzzer apita.
int buzzerPin = 6;
int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
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
    Serial.print(" | pwmMap: ");
    Serial.println(valorLido);

    pwm = map(valorLido, 0, 1023, 0, 255); // Mudança de escala

    int pwm_led_2, pwm_led_3;
    
    analogWrite(ledPin1, pwm);

    if (pwm >= 63) {
        pwm_led_2 = map(pwm, 63, 255, 0, 255); 
    } 
    else {
        pwm_led_2 = 0;
    }
    analogWrite(ledPin2, pwm_led_2);
    
    if (pwm >= 127) {
        pwm_led_3 = map(pwm, 127, 255, 0, 255);
        tone(buzzerPin, 400);
    } else {
        pwm_led_3 = 0;
        noTone(buzzerPin);
    }
    analogWrite(ledPin3, pwm_led_3);
    
    delay(100);
}
#endif



// ---------------------------------------------------------------------
// ---------------------------------------------------------------------



#ifdef EX5
// 5. Função ler potenciometro.
int buzzerPin = 6;
int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
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
    valorLido = lerPotenciometro(); // valor entre 0 e 1023

    Serial.print("pwmPin: ");
    Serial.print(valorLido);
    Serial.print(" | pwmMap: ");
    Serial.println(valorLido);
    
    pwm = map(valorLido, 0, 1023, 0, 255); // Mudança de escala

    int pwm_led_2, pwm_led_3;
    
    analogWrite(ledPin1, pwm);

    if (pwm >= 63) {
        pwm_led_2 = map(pwm, 63, 255, 0, 255); 
    } 
    else {
        pwm_led_2 = 0;
    }
    analogWrite(ledPin2, pwm_led_2);
    
    if (pwm >= 127) {
        pwm_led_3 = map(pwm, 127, 255, 0, 255);
        tone(buzzerPin, 400);
    } else {
        pwm_led_3 = 0;
        noTone(buzzerPin);
    }
    analogWrite(ledPin3, pwm_led_3);
    
    delay(100);
}
#endif



// ---------------------------------------------------------------------
// ---------------------------------------------------------------------



#ifdef EX6
// 6. Função mudar escala (cálculo).
int buzzerPin = 6;
int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
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
    
    int pwm_led_2, pwm_led_3;
    
    analogWrite(ledPin1, pwm);

    if (pwm >= 63) {
        pwm_led_2 = map(pwm, 63, 255, 0, 255); 
    } 
    else {
        pwm_led_2 = 0;
    }
    analogWrite(ledPin2, pwm_led_2);
    
    if (pwm >= 127) {
        pwm_led_3 = map(pwm, 127, 255, 0, 255);
        tone(buzzerPin, 400);
    } else {
        pwm_led_3 = 0;
        noTone(buzzerPin);
    }
    analogWrite(ledPin3, pwm_led_3);
    
    delay(100);
}
#endif



// ---------------------------------------------------------------------
// ---------------------------------------------------------------------



#ifdef EX7
// 7. Função controlLed.
int buzzerPin = 6;
int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
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

int mudarEscala(int valor) {
  return map(valor, 0, 1023, 0, 255);
}

void controlaLed1(int pwm) {
    
    if (pwm > 0) {
        return 1;
    } else {
        return 0;
    }
}

void controlaLed2(int pwm) {
    
    if (pwm >= 63) {
        return 1;
    } 
    return 0;
}

int controlaLed3(int pwm) {
    
    if (pwm >= 127) {
        return 1;
    }
    return 0;
}

void loop() {
    valorLido = lerPotenciometro();
    Serial.print("pwmPin: ");
    Serial.print(valorLido);
    pwm = mudarEscala(valorLido);
    Serial.print(" | pwmMap: ");
    Serial.println(pwm);
    
    if (controlaLed1(pwm) == 1) {
        analogWrite(ledPin1, pwm);
    } else {
        analogWrite(ledPin1, 0);
    }
    
    if (controlaLed2(pwm) == 1) {
        pwm_led_2 = map(pwm, 63, 255, 0, 255); 
        analogWrite(ledPin2, pwm_led_2);
    } else {
        analogWrite(ledPin2, 0);
    }
    
    if (controlaLed3(pwm) == 1) {
        pwm_led_3 = map(pwm, 127, 255, 0, 255);
        analogWrite(ledPin3, pwm_led_3);
    } else {
        analogWrite(ledPin3, 0);
    }
    
    if (pwm >= 127) {
        tone(buzzerPin, 400);
    } else {
        noTone(buzzerPin);
    }
    
    delay(100);
}
#endif



// ---------------------------------------------------------------------
// ---------------------------------------------------------------------



#ifdef EX8
// 8. Função controlBuzzer.
int buzzerPin = 6;
int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
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

int mudarEscala(int valor) {
  return map(valor, 0, 1023, 0, 255);
}

void controlaLed1(int pwm) {
    
    if (pwm > 0) {
        return 1;
    } else {
        return 0;
    }
}

void controlaLed2(int pwm) {
    
    if (pwm >= 63) {
        return 1;
    } 
    return 0;
}

int controlaLed3(int pwm) {
    
    if (pwm >= 127) {
        return 1;
    }
    return 0;
}

void controlaBuzzer(int pwm) {
    
    if (pwm >= 127) {
        tone(buzzerPin, 400);
    } else {
        noTone(buzzerPin);
    }
    return;
}

void loop() {
    valorLido = lerPotenciometro();
    Serial.print("pwmPin: ");
    Serial.print(valorLido);
    pwm = mudarEscala(valorLido);
    Serial.print(" | pwmMap: ");
    Serial.println(pwm);
    
    if (controlaLed1(pwm) == 1) {
        analogWrite(ledPin1, pwm);
    } else {
        analogWrite(ledPin1, 0);
    }
    
    if (controlaLed2(pwm) == 1) {
        pwm_led_2 = map(pwm, 63, 255, 0, 255); 
        analogWrite(ledPin2, pwm_led_2);
    } else {
        analogWrite(ledPin2, 0);
    }
    
    if (controlaLed3(pwm) == 1) {
        pwm_led_3 = map(pwm, 127, 255, 0, 255);
        analogWrite(ledPin3, pwm_led_3);
    } else {
        analogWrite(ledPin3, 0);
    }
    
    controlaBuzzer(pwm);
    
    delay(100);
}
#endif



// ---------------------------------------------------------------------
// ---------------------------------------------------------------------



#ifdef EX9
// 9. Função escrita no Led. (Já implementado a partir do exercicio 7)
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

void controlaLed1(int pwm) {
    
    analogWrite(ledPin1, pwm);
    return;
}

void controlaLed2(int pwm) {
    
    int pwm_led_2 = 0;
    if (pwm >= 63) {
        pwm_led_2 = map(pwm, 63, 255, 0, 255); 
    } 
    analogWrite(ledPin2, pwm_led_2);
    return;
}

void controlaLed3(int pwm) {
    
    int pwm_led_3 = 0;
    if (pwm >= 127) {
        pwm_led_3 = map(pwm, 127, 255, 0, 255);
        tone(buzzerPin, 400);
    }
    analogWrite(ledPin3, pwm_led_3);
    return;
}

void controlaBuzzer(int pwm) {
    
    if (pwm >= 127) {
        tone(buzzerPin, 400);
    } else {
        noTone(buzzerPin);
    }
    return;
}


void loop() {
    valorLido = lerPotenciometro();
    Serial.print("pwmPin: ");
    Serial.print(valorLido);
    pwm = mudarEscala(valorLido);
    Serial.print(" | pwmMap: ");
    Serial.println(pwm);
    
    controlaLed1(pwm);
    controlaLed2(pwm);
    controlaLed3(pwm);
    
    controlaBuzzer(pwm);
    
    delay(100);
}
#endif
