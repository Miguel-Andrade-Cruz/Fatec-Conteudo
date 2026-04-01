#include "Adafruit_LiquidCrystal.h"

// OUTPUTS

int led_blue = 13;
int led_yellow = 11;
int led_green = 10;

int buzzer = 8;

// --------------


// INPUTS
int button_1 = 7;
int button_2 = 6;
int potenciometer_control_green = A2;

int light_sensor = A0;
int temp_sensor = A1;

Adafruit_LiquidCrystal lcd(0);

void setup()
{
    pinMode(led_blue, OUTPUT);
    pinMode(led_green, OUTPUT);
    pinMode(led_yellow, OUTPUT);
    pinMode(buzzer, OUTPUT);

    pinMode(button_1, INPUT);
    pinMode(button_2, INPUT);
    pinMode(potenciometer_control_green, INPUT);

    lcd.begin(16, 2);

    lcd.setCursor(0, 0);
    lcd.print("TP:       LD");

    lcd.setCursor(0,1);
    lcd.print("PT:    L1:  L2: ");

    Serial.begin(9600);
}

// -------------------------------------

// OUTPUT FUNCTIONS

void lcd_write_temp(float temp) {

    int line = 0;
    int index = 3;

    lcd.setCursor(index, line);
    lcd.print(temp);

    return;
}


void lcd_write_blue_led(char led_state) {

    int line = 1;
    int index = 10;

    lcd.setCursor(index, line);
    lcd.print(led_state);

    return;
}

void lcd_write_yellow_led(char led_state) {

    int line = 1;
    int index = 15;
    lcd.setCursor(index, line);
    lcd.print(led_state);

    return;
}

void lcd_write_light_level(int light_level) {

    int line = 0;
    int index = 12;
    
    lcd.setCursor(index, line);
    lcd.print("    ");
    
    lcd.setCursor(index, line);
    lcd.print(light_level);

    return;
}

void lcd_write_intensity(int intensity) {

    int line = 1;
    int index = 3;
    lcd.setCursor(index, line);

    lcd.print(intensity);
    if (intensity < 10) {
        lcd.print("  ");
    } else if ( intensity < 100) {
        lcd.print(" ");
    }
    return;
}

// --------------------------------------------


// INPUT FUNCTIONS
float get_temp_in_celsius() {

    return (float) ((analogRead(temp_sensor) * 5.0 / 1023 * 1000 - 500) / 10);
}


int read_button_1_state() {

    return digitalRead(button_1);
}


int read_button_2_state() {

    return digitalRead(button_2);
}


int read_light_level() {

    return analogRead(light_sensor);
}


int read_potenciometer_value() {

    return analogRead(potenciometer_control_green);
}


// --------------------------------------------


// UTILITY FUNCTIONS

char toggle_blue_led(int button_1_state) {

    if (digitalRead(button_1_state) == LOW) {
        digitalWrite(led_blue, HIGH);
        return 'L';
    }
    digitalWrite(led_blue, LOW);
    return 'D';
}


char toggle_yellow_led(int button_2_state) {

    if (digitalRead(button_2_state) == LOW) {
        digitalWrite(led_yellow, HIGH);
        return 'L';
    }
    digitalWrite(led_yellow, LOW);

    return 'D';
}

void toggle_green_led(int intensity) {

    digitalWrite(led_green, intensity);
    return;
}


int toggle_buzzer() {

    if (led_blue == HIGH && light_sensor > 400) {
        return 1;
    }
    return 0;
}


int calculate_intensity(int potenciometer_value) {

    int mapped_value = map(potenciometer_value, 0, 1023, 0, 255);
    return mapped_value;
}




void loop()
{
    int temperature = get_temp_in_celsius();
    lcd_write_temp(temperature);

    int button_1_state = read_button_1_state();
    char blue_led_state = toggle_blue_led(button_1_state);
    toggle_buzzer();
    lcd_write_blue_led(blue_led_state);

    int light_level = read_light_level();
    toggle_buzzer();
    lcd_write_light_level(light_level);

    int button_2_state = read_button_2_state();
    char yellow_led_state = toggle_yellow_led(button_2_state);
    lcd_write_yellow_led(yellow_led_state);

    int potenciometer_value = read_potenciometer_value();
    int potenciometer_intensity = calculate_intensity(potenciometer_value);
    lcd_write_intensity(potenciometer_intensity);
    toggle_green_led(potenciometer_intensity);
}
