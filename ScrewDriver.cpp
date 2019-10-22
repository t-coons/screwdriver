
#include "ScrewDriver.h"

ScrewDriver::ScrewDriver() {
}

ScrewDriver::COMMAND_NAMES ScrewDriver::ParseCommand(String s) {
  s.toLowerCase();
  if (s.equals("set"))
    return SET;
  if (s.equals("update"))
    return UPDATE;
  if (s.equals("list"))
    return LIST;
  if (s.equals("print"))
    return PRINT;
  return NONE;
    
}

ScrewDriver::COMMAND ScrewDriver::Tokenize(String s) {
  COMMAND cmd;
  s.trim();
  int i = s.indexOf(' ');
  if (i == -1) {
    cmd.name = ParseCommand(s);
  } else {
    cmd.name = ParseCommand(s.substring(0, i));
    int j = s.indexOf(' ', i + 1);
    if (j != -1) {
      cmd.variable = s.substring(i + 1, j);
    } else {
      cmd.variable = s.substring(i + 1);
    }
    if (j != -1) {
      int k = s.indexOf(' ', j + 1);
      if (k != -1) {
        cmd.value = s.substring(j + 1, k);
      } else {
        cmd.value = s.substring(j + 1);
      }
    }
  }
  return cmd;
}

double* ScrewDriver::VariableLookup(String variableName) {
  for (unsigned int i = 0; i < variableMapSize; i++) {
    if (variableName.equals(variableMap[i].variable)) {
      return variableMap[i].addr;
    }
  }
  return NULL;
}

void ScrewDriver::ListVariables() {
  for (unsigned int i = 0; i < variableMapSize; i++) {
    Serial.print(variableMap[i].variable);
    Serial.print(": ");
    if (variableMap[i].addr) {
      Serial.println(*(variableMap[i].addr));
    } else {
      Serial.println("NULL");
    }
  }
}

void ScrewDriver::PrintVariable(String variableName) {
  double* addr = VariableLookup(variableName);
  Serial.print(variableName);
  Serial.print(": ");
  if (addr) {
    Serial.println(*addr);
  } else {
    Serial.println("does not exist");
  }
  
}

void ScrewDriver::AddVariableMap(VARIABLE_PAIR variableMap[], unsigned int variableMapSize) {
  this->variableMap = variableMap;
  this->variableMapSize = variableMapSize;
}

void ScrewDriver::Run(String s) {
  Serial.println(s);
  COMMAND cmd = Tokenize(s);
  if (cmd.name == NONE) {
    return;
  }
  double* addr = 0;
  double value = 0;
  switch (cmd.name) {
    case SET:
      // TODO: Impliment set
      break;
    case UPDATE:
      addr = VariableLookup(cmd.variable);
      value = cmd.value.toDouble();
      if (addr) {
        *addr = value;
      }
      break;
    case LIST: 
      ListVariables();
      break;
    case PRINT:
      PrintVariable(cmd.variable);
      break;
  }
} 

ScrewDriver::~ScrewDriver() {
}
