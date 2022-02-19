#include "MCreatorLink.h"
String splitString(String str, char sep, int index)
{
  int found = 0;
  int strIdx[] = { 0, -1 };
  int maxIdx = str.length() - 1;

  for (int i = 0; i <= maxIdx && found <= index; i++)
  {
    if (str.charAt(i) == sep || i == maxIdx)
    {
      found++;
      strIdx[0] = strIdx[1] + 1;
      strIdx[1] = (i == maxIdx) ? i + 1 : i;
    }
  }
  return found > index ? str.substring(strIdx[0], strIdx[1]) : "";
}


void dataEvent(String command, String data) {
  //arriverà nella variabile command una stringa con scritto "msg" e in data ci sarà "param1:param2"
  //la sintassi del comando che invierò da MC sarà per esempio "R:11", ovvero ROSSO Riga 1 Colonna 1
  //a seconda del colore R o B che arriva accendere il pin corretto
  /*R11 = 13
    B11 = 12
    R12 = 11
    B12 = 10
    R13 = 9
    B13 = 8
    R21 = 7
    B21 = 6
    R22 = 5
    B22 = 4
    R23 = 3
    B23 = 2
    R31 = A0
    B31 = A1
    R32 = A2
    B32 = A3
    R33 = A4
    B33 = A5 */

  String colore = splitString(data, ":", 0);
  String index = splitString(data, ":", 1);
  if (colore.equals("R")) {
    if (index.equals("11")) {
      pinMode(13, HIGH);
    } else if (index.equals("12")) {

    } else if (index.equals("13")) {

    } else if (index.equals("21")) {

    } else if (index.equals("22")) {

    } else if (index.equals("23")) {

    } else if (index.equals("31")) {

    } else if (index.equals("32")) {

    } else if (index.equals("33")) {

    }
  } else if (colore.equals("B")) {
    if (index.equals("11")) {

    } else if (index.equals("12")) {

    } else if (index.equals("13")) {

    } else if (index.equals("21")) {

    } else if (index.equals("22")) {

    } else if (index.equals("23")) {

    } else if (index.equals("31")) {

    } else if (index.equals("32")) {

    } else if (index.equals("33")) {

    }
  } else if (colore.equals("RESET")) {
    //spengo tutti i led
    for (int i = 2; i < 14; i++) {
      digitalWrite(i, LOW);
    }
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
  } else {
  }
  //errore
}

void setup() {
  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(20);
  MCreatorLink.setup(Serial);
  MCreatorLink.setListener(dataEvent);
  digitalWrite(A0, HIGH);

}

void loop() {
  MCreatorLink.loop();
}
