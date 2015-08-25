/*
Copyright 2015 Hugo LEVY-FALK

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#include "../Listuino.h"

void setup()
{
    // In order to display the results
    Serial.begin(9600);

    // Let's create a uint8_t list !
    List <uint8_t> a;

    // Okay, now we want to add 2 values at the end of the list :
    a.append(1);
    a.append(2);

    // End if we want to add a value at the begining :
    a.preface(3);

    // We can also insert a value anywhere in the list :
    a.insertValue(1, 4);

    // Of course, it is possible to read a value :
    // There is also a getFirstValue and a getLastValue methods.
    Serial.println(a.getValue(1));

    // Here's a good way to read the entiere list :
    // Note : you can specify what is the first index when in a.get(index)
    // and there is also a getPrevious method.
    for(ListElement<uint8_t>* i = a.get(0); i != 0; i=i->getNext()){
        Serial.println(i->getValue());
    }

    // You can remove a value of the list with... remove value !
    // There is also a removeFirstValue and a removeLastValue methods.
    a.removeValue(1);

    // And you can set a value with the setValue method. 
    // The first argument is the value index and the second is the value.
    // There is also a setFirstValue and a setLastValue methods.
    a.setValue(1, 5);

    // The pop method allow you to get the value at the given index and remove it.
    // There is also a popFirstValue and a popLastValue methods.
    Serial.println(a.pop(2));
}

void loop()
{
}
