const int sensorPin = A0;
const float baselineTemp = 25.0; //початкова температура відносно якої буде порівнюватись температура в подальшому 
void setup() {
  Serial.begin(9600);
  for(int pinNumber = 2;pinNumber < 5;pinNumber ++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: "); // інформація яку ми можемо бачити моніторі портв
  Serial.print(sensorVal);
  float Voltage = (sensorVal/1024.0)*5.0; // переретворення даних з датчика температури в напругу
  Serial.print(", Volts: "); // виивід даних напруги в монітор порта
  Serial.print(Voltage);
  Serial.print(", degrees C: "); // вивид даних температури в монітор порта
  float temperature = (Voltage - 0.5)*100; // перетворення напруги в температури
  Serial.println(temperature);
  if(temperature < baselineTemp){ // якщо температура нижча за задану початкову
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    //не горить ні один світлодіод
  }else if (temperature >= baselineTemp+2 && temperature < baselineTemp+4){ // якщо температура відрізняється 2 градуси но не більше ніж на 4 градуси від початкової
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    // горить лише один світлодіод
  }else if (temperature >= baselineTemp+4 && temperature < baselineTemp+6){ // якщо температура відрізняється 4 градуси но не більше ніж на 6 градуси від початкової
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    // горить два світлодіода
  }else if (temperature >= baselineTemp+6){ // якщо температура відрізняєтьсябільше ніж на 6 градуси від початкової
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    // горять всі світолдіоди
  }
 
  delay(10);
}
