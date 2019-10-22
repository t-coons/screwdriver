
#ifndef ScrewDriver_h
#define ScrewDriver_h

#include <Arduino.h>

class ScrewDriver {
  // Variables
  
  public:
  struct VARIABLE_PAIR {
    String variable;
    int* addr;
  };
  
  private:
  enum COMMAND_NAMES {
    NONE,
    SET,
    UPDATE,
    LIST,
    PRINT
  };

  struct COMMAND {
    COMMAND_NAMES name;
    String variable;
    String value;
  };

  VARIABLE_PAIR* variableMap;
  unsigned int variableMapSize = 0;

  // Methods
  private:

  COMMAND_NAMES ParseCommand(String s);
  
  COMMAND Tokenize(String s);

  int* VariableLookup(String variableName);

  void ListVariables();

  void PrintVariable(String variableName);
  
  public:
  ScrewDriver();

  void AddVariableMap(VARIABLE_PAIR variableMap[], unsigned int variableMapSize);
  
  void Run(String s);
  
  ~ScrewDriver();
};

#endif
