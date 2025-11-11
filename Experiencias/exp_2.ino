#define exc1

#ifdef exc1

int buzzerPin = 4;

int leftButtonPin = 2;
int rightButtonPin = 8;

int blueLedPin = 12;
int greenLedPin = 13;

void setup()
{
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(leftButtonPin, INPUT);
  pinMode(rightButtonPin, INPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop()
{
  
  int leftButtonState = digitalRead(leftButtonPin);
  int rightButtonState = digitalRead(rightButtonPin);
  
  if (leftButtonState == 1) {
    digitalWrite(blueLedPin, LOW);
  } else {
    digitalWrite(blueLedPin, HIGH);
  }
  
  if (rightButtonState == 1) {
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(greenLedPin, HIGH);  
  }
}

#endif

// -----------------------------------------------------------

#ifdef exc2

int buzzerPin = 4;

int leftButtonPin = 2;
int rightButtonPin = 8;

int blueLedPin = 12;
int greenLedPin = 13;

void setup() {

  pinMode(buzzerPin, OUTPUT);
  pinMode(leftButtonPin, INPUT);
  pinMode(rightButtonPin, INPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);  
}


void loop() {

   if (digitalRead(leftButtonPin) == 1) {
    digitalWrite(blueLedPin, LOW);
    noTone(buzzerPin);
  } else {
    digitalWrite(blueLedPin, HIGH);
    tone(buzzerPin, 2000);
  }
  
  if (digitalRead(rightButtonPin) == 1) {
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(greenLedPin, HIGH);  
  }
}

#endif

// ----------------------------------------------------------

#ifdef exc3

int buzzerPin = 4;

int leftButtonPin = 2;
int rightButtonPin = 8;

int blueLedPin = 12;
int greenLedPin = 13;

void setup() {

  pinMode(buzzerPin, OUTPUT);
  pinMode(leftButtonPin, INPUT);
  pinMode(rightButtonPin, INPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);  
}


void loop() {

  if (digitalRead(leftButtonPin) == 1) {
    digitalWrite(blueLedPin, LOW);
  } else {
    digitalWrite(blueLedPin, HIGH);
  }
  
  if (digitalRead(rightButtonPin) == 1) {
    digitalWrite(greenLedPin, LOW);
    noTone(buzzerPin);
  } else {
    digitalWrite(greenLedPin, HIGH);
    tone(buzzerPin, 2000);
  }
}

#endif

// --------------------------------------------------------

#ifdef exc4

int buzzerPin = 4;

int leftButtonPin = 2;
int rightButtonPin = 8;

int blueLedPin = 12;
int greenLedPin = 13;

void setup() {

  pinMode(buzzerPin, OUTPUT);
  pinMode(leftButtonPin, INPUT);
  pinMode(rightButtonPin, INPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);  
}


void loop() {

  if (digitalRead(leftButtonPin) == 1) {
    digitalWrite(greenLedPin, LOW);
    noTone(buzzerPin);
  } else {
    digitalWrite(greenLedPin, HIGH);
    tone(buzzerPin, 2000);
  }
  
  if (digitalRead(rightButtonPin) == 1) {
    digitalWrite(blueLedPin, LOW);
    noTone(buzzerPin);
  } else {
    digitalWrite(blueLedPin, HIGH);
    tone(buzzerPin, 2000);
  }
}

#endif

// --------------------------------------------------------

#ifdef exc5

int buzzerPin = 4;

int leftButtonPin = 2;
int rightButtonPin = 8;

int blueLedPin = 12;
int greenLedPin = 13;

int readLeftButton() {
	return digitalRead(leftButtonPin);
}

int readRightButton(){
	return digitalRead(rightButtonPin);
}

void setup() {

  pinMode(buzzerPin, OUTPUT);
  pinMode(leftButtonPin, INPUT);
  pinMode(rightButtonPin, INPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);  
}

void loop() {

  if (readLeftButton() == 1) {
    digitalWrite(blueLedPin, LOW);
    noTone(buzzerPin);

  } else {
    digitalWrite(blueLedPin, HIGH);
    tone(buzzerPin, 2000);
  }
  
  if (readRightButton() == 1) {
    digitalWrite(greenLedPin, LOW);
    noTone(buzzerPin);
  } else {
    digitalWrite(greenLedPin, HIGH);
    tone(buzzerPin, 2000);
  }
}

#endif

// -------------------------------------------------------

#ifdef exc6

int buzzerPin = 4;

int leftButtonPin = 2;
int rightButtonPin = 8;

int blueLedPin = 12;
int greenLedPin = 13;


void turnOnLeftLed() {
  
  if (digitalRead(leftButtonPin) == 1) {
    digitalWrite(blueLedPin, LOW);
  } else {
    digitalWrite(blueLedPin, HIGH);
  }  
}

void turnOnRightLed(){
  
  if (digitalRead(rightButtonPin) == 1) {
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(greenLedPin, HIGH);
  }
}


void setup() {

  pinMode(buzzerPin, OUTPUT);
  pinMode(leftButtonPin, INPUT);
  pinMode(rightButtonPin, INPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);  
}

void loop() {
  turnOnLeftLed();
  turnOnRightLed();
}

#endif

// --------------------------------------------------------------------

#ifdef exc7

int buzzerPin = 4;

int leftButtonPin = 2;
int rightButtonPin = 8;

int blueLedPin = 12;
int greenLedPin = 13;


void turnOnLeftLed() {
  
  if (digitalRead(leftButtonPin) == 1) {
    digitalWrite(blueLedPin, LOW);
  } else {
    digitalWrite(blueLedPin, HIGH);
  }  
}

void turnOnRightLed(){
  
  if (digitalRead(rightButtonPin) == 1) {
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(greenLedPin, HIGH);
  }
}


void turnOnBuzzer() {
  
  if (digitalRead(leftButtonPin) == 0 || digitalRead(rightButtonPin) == 0) {
  	tone(buzzerPin, 2000);
  } else {
    noTone(buzzerPin);
  }
}

void setup() {

  pinMode(buzzerPin, OUTPUT);
  pinMode(leftButtonPin, INPUT);
  pinMode(rightButtonPin, INPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);  
}

void loop() {
  
  turnOnLeftLed();
  turnOnRightLed();
  turnOnBuzzer();
}

#endif

// -----------------------------------------------------------------------

#ifdef exc8

int DO = 264;
int RE = 297;
int MI = 330;
int FA = 352;
int SOL = 396;
int LA = 440;
int SI = 495;
int D = 500;
int N = 29;
int notas[][2] = { {SOL, D/2}, {SOL, D/2}, {LA,D*2}, {SOL, D}, {DO*2,D},
{SI,D*3}, {SOL, D/2}, {SOL, D/2}, {LA,D*2}, {SOL,D }, {RE*2,D }, {DO*2,D },
{DO*2,D }, {0,D }, {MI*2,D/2 }, {MI*2,D/2 }, {SOL*2,D*2 }, {MI*2,D }, 
{DO*2,D },
{SI,D }, {LA,D }, {0,D }, {FA*2,D/2 }, {FA*2,D/2 }, {MI*2,D*2 }, {DO*2,D },
{RE*2,D }, {DO*2,D }, {DO*2,D*3} };

int duracao;
int nota;
int buzzerPin = 4;

int leftButtonPin = 2;
int rightButtonPin = 8;

int blueLedPin = 12;
int greenLedPin = 13;

void setup(){
  pinMode(buzzerPin,OUTPUT);
}

void loop(){
  
  if (digitalRead(leftButtonPin) == 0) {

    for (int i = 0; i < N; i++){
      nota = notas[i][0];
      duracao = notas[i][1];
      tone(buzzerPin, nota, duracao);
      delay(duracao);
    }
  }
}
#endif