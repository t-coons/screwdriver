#include "ScrewDriver.h"


ScrewDriver sd;

bool vBool = 0;
byte vByte = 0;
char vChar = 0;
double vDouble = 0;
float vFloat = 0;
int vInt = 0;
long vLong = 0;
short vShort = 0;
size_t vSize_t = 0;
unsigned char vUChar = 0;
unsigned int vUInt = 0;
unsigned long vULong = 0;
word vWord = 0;

ScrewDriver::VARIABLE_PAIR variableMap[] =
{
  { "bool", VAR(&vBool) },
  { "byte", VAR(&vByte) },
  { "char", VAR(&vChar) },
  { "double", VAR(&vDouble) },
  { "float", VAR(&vFloat) },
  { "int", VAR(&vInt) },
  { "long", VAR(&vLong) },
  { "short", VAR(&vShort) },
  { "size_t", VAR(&vSize_t) },
  { "uchar", VAR(&vUChar) },
  { "uint", VAR(&vUInt) },
  { "ulong", VAR(&vULong) },
  { "word", VAR(&vWord) }
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
