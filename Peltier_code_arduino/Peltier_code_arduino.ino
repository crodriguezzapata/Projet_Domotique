#include <SoftwareSerial.h>
SoftwareSerial BT1(4, 1);
SoftwareSerial BT2(8, 7);

char x; //Variable que guardara nuestro dato recibido desde el celular
int variableT; //Varaible convertida en entero
float sensor = 0.0;
float volt = 0.0;
float milivolt = 0.0;
float f = 0.0;
float c = 0.0; //Variable de nuestra temperatura

void setup() {
  BT1.begin(9600);
  BT2.begin(9600);
  Serial.begin(9600);
}

void loop() {

  while (BT2.available()) {

    if (BT2.available()) {

      //Serial.println(x);

      sensor = analogRead(A0);
      volt = (5.0 * sensor) / 1024.0;
      milivolt = volt * 100;
      c = milivolt - 273.15;

      /*Serial.print("Sensor = ");
        Serial.print(sensor);
        Serial.print("\t volt = ");
        Serial.print(volt);
        Serial.print("\t milivolt = ");
        Serial.print(milivolt);*/
      Serial.print("\t Celsius = ");
      Serial.println(c);
      BT2.println(c);

      delay(3);

      pinMode(13, OUTPUT);
      x = BT2.read();
      BT1.println(x);
      if (x == 'e') {
        digitalWrite(13, HIGH);
        Serial.println("Foco On");
      }
      if (x == 'a') {
        digitalWrite(13, LOW);
        Serial.println("Foco Off");
      }
    }
  }
}
