# screwdriver
Arduino Library that allows variables to be modified via serial monitor. The overall goal is to allow variables to change without re-upload to hasten the debug and tuning processes.

## Include
Include like any other library once added
    
    #include "ScrewDriver.h"

## Setup
A variable map must be created and initialized to link variables
Variable map is of type:

    VARIABLE_PAIR variableMap[size];
A variable pair is what actually creates the linking and is of type

    struct VARIABLE_PAIR {
      String variable;
      int* addr;
    }
> Note: the variable pair can only link to an integer currently. This is planned to by more dynamic with further updates

An example of this is: 
	
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
    sd.AddVariableMap(variableMap, numVariables);
> Note: Make sure the variables set in the map do not go out of scope! An easy way around this is to set them as globals

All that is left is to parse the commands to run on the variables
The commands currently supported are:

1. list
2. update \<variable\> \<value\>
3. print \<variable\>

Commands are ran using

    ScrewDriver::Run()

continuing from the previous example: 
    
    sd.Run("update var0 7");

To read from the Serial monitor just set up a while loop in the loop() function like such:

    if (Serial.available() > 0) {
      String s = Serial.readString();
      sd.Run(s);
    }

To wrap it up is a snippet of the program in action using the above example setup variables:
```js
list

var0: 0
var1: 1
var2: 2
update var0 42

update var1 60

print var0

var0: 42
list

var0: 42
var1: 60
var2: 2
```
