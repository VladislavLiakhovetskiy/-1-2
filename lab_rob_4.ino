const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10; 
// присвоєння відповідним пінам ніжок світлодіодів (кожна ніжка відповідає за свій колір)

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;
//присвоєння анологовим виходам відповідних фоторезисторів

int redValue = 0 ;
int greenValue = 0; 
int blueValue = 0;

int redSensorValue = 0 ;
int greenSensorValue =0 ; 
int blueSensorValue = 0 ; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //відкриття серійного порту
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  Serial.print("Raw Sensor Values \t Red");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);
// вивід на монітор порту відповідних значень
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.print(blueValue);
  // вивід на монітор порту відповідних значень
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
  // передаєм значення на відповідну ніжку світлодіода
}
