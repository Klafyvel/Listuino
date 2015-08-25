#include "../Listuino.h"

void setup()
{
    Serial.begin(9600);
    List <uint8_t> a;
    a.append(1);
    a.append(2);
    a.preface(3);
    a.insertValue(1, 4);
    Serial.println(a.getValue(1));
    a.removeValue(1);
    Serial.println(a.getValue(1));
    a.setValue(1, 5);
    Serial.println(a.pop(2));
    pinMode(13, OUTPUT);
}

void loop()
{
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
}
