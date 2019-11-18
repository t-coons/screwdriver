#include "ScrewDriver.h"

ScrewDriver sd;

double d = 1.0;
int i = 2;

ScrewDriver::VARIABLE_PAIR variableMap[] =
{
  { "var0", VAR(&d) },
  { "var1", VAR(&i) }
};
const unsigned int numVariables = sizeof(variableMap) / sizeof(ScrewDriver::VARIABLE_PAIR);

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
