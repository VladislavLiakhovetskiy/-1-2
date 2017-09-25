int StateSwitch = 0 ;

void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);//для виводу параметру на 3 цифровий вивід
  pinMode(4,OUTPUT);//для виводу параметру на 4 цифровий вивід
  pinMode(5,OUTPUT);//для виводу параметру на 5 цифровий вивід
  pinMode(2,INPUT); //для введення інформації з 2 цифрового виводу
}

void loop() {
  // put your main code here, to run repeatedly:
  StateSwitch = digitalRead(2);// зчитуємо інформацію з 2 цифрового виводу і присвоюємо цю інформацію змінній
  if (StateSwitch == LOW) { // якщо кнопка не натиснута, то ...
    digitalWrite(3, HIGH); // зелений світлодіод горить
    digitalWrite(4, LOW); //  червоний діод не горить
    digitalWrite(5, LOW); // червоний діод не горить
  }
  else { // коли кнопка натиснута, то ...
    digitalWrite(3, LOW); //  зелений діод не горить
    digitalWrite(4, LOW);//  червоний діод не горить
    digitalWrite(5, HIGH);// червоний світлодіод горить

    delay(250); // робимо затримку на 1/4 секунди виконання програмного коду

    digitalWrite(4,HIGH); // червоний світлодіод горить
    digitalWrite(5,LOW); // зелений діод не горить
    delay(250);  // робимо затримку на 1/4 секунди виконання програмного коду
  }
} // переходимо на початок блоку loop 
