#include "ScrewDriver.h"


ScrewDriver sd;

int var0 = 0;
int var1 = 1;
int var2 = 2;
const unsigned int numVariables = 3;
ScrewDriver::VARIABLE_PAIR variableMap[numVariables] =
{
  { "var0", &var0 },
  { "var1", &var1 },
  { "var2", &var2 }
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  sd.AddVariableMap(variableMap, numVariables);  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String s = Serial.readString();
    sd.Run(s);
  }
}
