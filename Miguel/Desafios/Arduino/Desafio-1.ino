#include <Adafruit_LiquidCrystal.h>

int seconds = 0;

Adafruit_LiquidCrystal lcd_1(0);


int horizontal_green = 13;
int horizontal_yellow = 12;
int horizontal_red = 11;

int ped_horizontal_green = 10;
int ped_horizontal_red = 9;

int vertical_green = 7;
int vertical_yellow = 6;
int vertical_red = 5;

int ped_vertical_green = 4;
int ped_vertical_red = 3;


// 1 - chama uma função para apagar o vermelho carro 1 e o amarelo carro 2
void hoz_red_off__vert_yellow_off(){
  digitalWrite(horizontal_red, LOW); 
  digitalWrite(vertical_yellow, LOW);
  lcd_1.setCursor(8, 0);
  lcd_1.print(" ");
  lcd_1.setCursor(5, 1);
  lcd_1.print(" ");
}

// 2 - chama uma função para acender o verde carro 1 e o vermelho carro 2
void hoz_green_on__vert_red_on() {
  digitalWrite(horizontal_green, HIGH); 
  digitalWrite(vertical_red, HIGH);
  lcd_1.setCursor(2, 0);
  lcd_1.print("x");
  lcd_1.setCursor(8, 1);
  lcd_1.print("x");
}

// 3 - chama uma função que apaga o verde do carro 1
void hoz_green_off(){
  digitalWrite(horizontal_green, LOW);
  lcd_1.setCursor(2, 0);
  lcd_1.print(" ");
}

// 4 - chama uma função que acende o amarelo do carro 1
void hoz_yellow_on(){
  digitalWrite(horizontal_yellow, HIGH); 
  lcd_1.setCursor(5, 0);
  lcd_1.print("x");
}

// 5 - chama uma função para apagar o amarelo carro 1
void hoz_yellow_off(){
  digitalWrite(horizontal_yellow, LOW);
  lcd_1.setCursor(5, 0);
  lcd_1.print(" ");
}

// 6 - chama uma função para acender vermelho carro 1
void hoz_red_on(){
  digitalWrite(horizontal_red, HIGH); 
  lcd_1.setCursor(8, 0);
  lcd_1.print("x");
}

// 7 - chama uma função para apagar o vermelho pedestre 1 e o vermelho pedestre 2
void ped_hoz_red_off__ped_vert_red_off(){
  digitalWrite(ped_horizontal_red, LOW);
  digitalWrite(ped_vertical_red, LOW);  
  lcd_1.setCursor(14, 0);
  lcd_1.print(" "); 
  lcd_1.setCursor(14, 1);
  lcd_1.print(" "); 
}

// 8 - chama uma função para acender o verde pedestre 1 e o verde pedestre 2
void ped_hoz_green_on__ped_vert_green_on(){
  digitalWrite(ped_horizontal_green, HIGH); 
  digitalWrite(ped_vertical_green, HIGH);
  lcd_1.setCursor(11, 0);
  lcd_1.print("x");
  lcd_1.setCursor(11, 1);
  lcd_1.print("x"); 
}

// 9 - chama uma função para acender o vermelho pedestre 1 e o vermelho pedestre 2
void ped_hoz_red_on__ped_vert_red_on(){
  digitalWrite(ped_horizontal_red, HIGH);
  digitalWrite(ped_vertical_red, HIGH);
  lcd_1.setCursor(14, 0);
  lcd_1.print("x");
  lcd_1.setCursor(14, 1);
  lcd_1.print("x");
}

// 10 - chama uma função para apagar o verde pedestre 1 e o verde pedestre 2
void ped_hoz_green_off__ped_vert_green_off(){
  digitalWrite(ped_horizontal_green, LOW); 
  digitalWrite(ped_vertical_green, LOW);
  lcd_1.setCursor(11, 0);
  lcd_1.print(" ");
  lcd_1.setCursor(11, 1);
  lcd_1.print(" "); 
}

// 11 - chama uma função para apagar o vermelho carro 2
void vert_red_off(){
  digitalWrite(vertical_red, LOW);
  lcd_1.setCursor(8, 1);
  lcd_1.print(" ");
}
  
// 12 - chama uma função para acender verde carro 2
void vert_green_on(){
  digitalWrite(vertical_green, HIGH);
  lcd_1.setCursor(2, 1);
  lcd_1.print("x");
}

// 13 - chama uma função que apaga o verde do carro 2
void vert_green_off(){
  digitalWrite(vertical_green, HIGH);
  lcd_1.setCursor(2, 1);
  lcd_1.print(" ");
}

// 14 - chama uma função que acende o amarelo do carro 2
void vert_yellow_on(){
  digitalWrite(vertical_yellow, HIGH);
  lcd_1.setCursor(5, 1);
  lcd_1.print("x");
}

void setup()
{
  lcd_1.begin(16, 2);
  lcd_1.print("1V  A  R  V  R  ");
  lcd_1.setCursor(0, 1);
  lcd_1.print("2V  A  R  V  R  ");
  lcd_1.setBacklight(1);
  
  pinMode(horizontal_green, OUTPUT);
  pinMode(horizontal_yellow, OUTPUT);
  pinMode(horizontal_red, OUTPUT);
  
  pinMode(ped_horizontal_green, OUTPUT);
  pinMode(ped_horizontal_red, OUTPUT);
  
  pinMode(vertical_green, OUTPUT);
  pinMode(vertical_yellow, OUTPUT);
  pinMode(vertical_red, OUTPUT);
  
  pinMode(ped_vertical_green, OUTPUT);
  pinMode(ped_vertical_red, OUTPUT);
}



void loop()
{
  hoz_red_off__vert_yellow_off();
  hoz_green_on__vert_red_on();
  delay(3 * 1000);

  hoz_green_off();
  hoz_yellow_on();
  delay(3 * 1000);

  hoz_yellow_off();
  hoz_red_on();
  
  ped_hoz_red_off__ped_vert_red_off();
  ped_hoz_green_on__ped_vert_green_on();
  delay(3 * 1000);  

  ped_hoz_red_on__ped_vert_red_on();
  ped_hoz_green_off__ped_vert_green_off();
  vert_red_off();
  vert_green_on();
  delay(3 * 1000);
  
  vert_green_off();
  vert_yellow_on();
  delay(3 * 1000);
}

// No display as letras representam: 1 e 2 são os semáforos.
/*
V -> lâmpada verde carro
A -> lâmpada amarela carro
R -> lâmpada vermelha carro
V -> lâmpada verde pedestre
R -> lâmpada vermelha pedestre
*/


/*
  1 - chama uma função para apagar o vermelho carro 1 e o amarelo carro 2
  2 - chama uma função para acender o verde carro 1 e o vermelho carro 2
      tempo de 3 seg. 1
  3 - chama uma função que apaga o verde do carro 1
  4 - chama uma função que acende o amarelo do carro 1
      tempo de 3 seg. 2
  5 - chama uma função para apagar o amarelo carro 1
  6 - chama uma função para acender vermelho carro 1
  7 - chama uma função para apagar o vermelho pedestre 1 e o vermelho pedestre 2
  8 - chama uma função para acender o verde pedestre 1 e o verde pedestre 2
      tempo de 3 seg. 3
  9 - chama uma função para acender o vermelho pedestre 1 e o vermelho pedestre 2
  10 - chama uma função para apagar o verde pedestre 1 e o verde pedestre 2
  11 - chama uma função para apagar o vermelho carro 2
  12 - chama uma função para acender verde carro 2
     - tempo de 3 seg. 4
  13 - chama uma função que apaga o verde do carro 2
  14 - chama uma função que acende o amarelo do carro 2
    - tempo de 3 seg. 5
*/