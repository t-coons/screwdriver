#include "screwdriver.h"


ScrewDriver sd;

int test0 = 0;
int test1 = 1;
int test2 = 2;
ScrewDriver::VARIABLE_PAIR variableMap[3] =
{
  { "test0", &test0 },
  { "test1", &test1 },
  { "test2", &test2 }
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  sd.AddVariableMap(variableMap, 3);
  sd.Run("Cmd");
  sd.Run("Cmd arg1");
  sd.Run("Cmd arg1 arg2");
  sd.Run("Cmd arg1 arg2 arg3");
  sd.Run("update test");
  sd.Run("update test0");
  sd.Run("list");
  sd.Run("update test0 1");
  sd.Run("update test1 2");
  sd.Run("update test2 3");
  sd.Run("list");
  sd.Run("print test0");
  sd.Run("print test1");
  sd.Run("print test2");
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String s = Serial.readString();
    sd.Run(s);
  }
}
