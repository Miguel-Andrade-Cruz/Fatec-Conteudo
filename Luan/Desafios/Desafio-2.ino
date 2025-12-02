#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// Outputs
int led_blue = 13;
int led_yellow = 11;
int led_green = 10;
int buzzerPin = 8;

// Inputs
int btn1 = 7;
int btn2 = 6;
int ctrl_potent = A2;
int light_sensor = A0;
int temp_sensor = A1;

// Leituras
float temperatura;
int btn1Status;
int btn2Status;
int lightSensorStatus;
int potentiometerStatus;
int potentiometerConvert;

void setup()
{
  lcd.begin(16, 2);
  lcd.print("TP:       LD");
  lcd.setCursor(0, 1);
  lcd.print("PT:    L1:  L2: ");
  lcd.setBacklight(1);

  pinMode(led_blue, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(ctrl_potent, INPUT);
  pinMode(temp_sensor, INPUT);
  Serial.begin(9600);
}

float leituraTemp() {
    return (float)((analogRead(temp_sensor) * 5.0 / 1023 * 1000 - 500) / 10);
}

void printLCD(int type, float value){

  // 1: temperature
  if (type == 1) {
  lcd.setCursor(3, 0);
  lcd.print(value);
  }

  // 2: ligh sensor
  if (type == 2) {
  lcd.setCursor(12, 0);
  lcd.print(int(value));
  }

  // 3: potentiometer
  if (type == 3) {
  lcd.setCursor(3, 1);
  lcd.print(int(value));
  if (value < 10) lcd.print("   ");
  else if (value < 100) lcd.print("  ");
  }

  // 4: led 1
  if (type == 4) {
  lcd.setCursor(10, 1);
  lcd.print(value ? "L" : "D");
  }

  // 5: led 2
  if (type == 5) {
  lcd.setCursor(15, 1);
  lcd.print(value ? "L" : "D");
  }
}

int readBtn(int btnN){
  int btn = (btnN == 1? btn1 : btn2);
  return digitalRead(btn) == LOW;
}

void controlLed(int pin, int state) {
  if (pin == led_blue || pin == led_yellow){
     if (state == 1) digitalWrite(pin, HIGH);
     else digitalWrite(pin, LOW);
  } else if (pin == led_green) {analogWrite(pin, state);}
}

void controlBuzzer(int btnState, int ldrValue) {
  if (btnState == HIGH || ldrValue <= 167) {
    tone(buzzerPin, 400);
  } else {
    noTone(buzzerPin);
  }
}

int readLDR() {
  return analogRead(light_sensor);
}

int readPotent(){
    return analogRead(ctrl_potent); // valor entre 0 e 1023
}

int convScale(int valor, int min, int max) {
  return map(valor, min, max, 0, 255);
}

void loop() {
  temperatura = leituraTemp(); // 1.1 lê e calcula o valor da temperatura através de função
  printLCD(1, temperatura); // 1.2 escreve o valor no lcd através de função

  btn1Status = readBtn(1); // 2.1 lê o valor do botão 1 através de função
  controlLed(led_blue, btn1Status); // 2.2 decide se liga ou desliga o led do pino 13 através de função,
  // 2.3 (JUNTO DE 3.2) decide se o buzzer deve ser acionado ou não através de outra função,
  printLCD(4, btn1Status); // 2.4 escreve a decisão no lcd através de função

  lightSensorStatus = readLDR(); // 3.1 lê o valor do ldr através de função,
  controlBuzzer(btn1Status, lightSensorStatus); // 3.2 + 2.4 decide se o buzzer deve ser acionado ou não através de outra função
  printLCD(2, lightSensorStatus); // 3.3 escreve o valor no lcd através de função

  btn2Status = readBtn(2); // 4.1 lê o valor do botão 2 através de função
  controlLed(led_yellow, btn2Status); // 4.2 decide se liga ou desliga o led do pino 11 através de função
  printLCD(5, btn2Status); // 4.3 escreve em outra função a decisão no lcd

  potentiometerStatus = readPotent(); // 5.1 lê o valor do potenciômetro através de função
  potentiometerConvert = convScale(potentiometerStatus, 0, 1023); // 5.2 faz o cálculo através de função
  printLCD(3, potentiometerConvert); // 5.3 escreve o cálculo no lcd em outra função
  controlLed(led_green, potentiometerConvert); // 5.4 escreve o valor calculado no led do pino 10 através de função
  printLCD(4, btn1Status);


  delay(100);
  // Serial monitor (DEBUGGING)
  /*
  Serial.print("temp: ");
  Serial.print(temperatura);
  Serial.print(" light: ");
  Serial.print(lightSensorStatus);
  Serial.print(" potent: ");
  Serial.print(potentiometerStatus);
  Serial.print(" conv: ");
  Serial.print(potentiometerConvert);
  Serial.print(" bt1: ");
  Serial.print(btn1Status);
  Serial.print(" bt2: ");
  Serial.println(btn2Status);
  */
}

// 1.1 lê e calcula o valor da temperatura através de função
// 1.2 escreve o valor no lcd através de função

// 2.1 lê o valor do botão 1 através de função
// 2.2 decide se liga ou desliga o led do pino 13 através de função,
// 2.3 decide se o buzzer deve ser acionado ou não através de outra função,
// 2.4 escreve a decisão no lcd através de função

// 3.1 lê o valor do ldr através de função,
// 3.2 decide se o buzzer deve ser acionado ou não através de outra função
// 3.3 escreve o valor no lcd através de função

// 4.1 lê o valor do botão 2 através de função
// 4.2 decide se liga ou desliga o led do pino 11 através de função
// 4.3 escreve em outra função a decisão no lcd

// 5.1 lê o valor do potenciômetro através de função
// 5.2 faz o cálculo através de função
// 5.3 escreve o cálculo no lcd em outra função
// 5.4 escreve o valor calculado no led do pino 10 através de função


/*
DUVIDAS

1. Chamar funções genéricas ou específicas para realizar as requisições.
2. Checar resistência do resistor de 100 Ohms pra 1000 Ohms?
3. Declaração de variáveis de estado dentro da função loop

*/
