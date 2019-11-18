# ScrewDriver
Arduino Library that allows variables to be modified via serial monitor. The overall goal is to allow variables to change without re-upload to hasten the debug and tuning processes.

## Include
Include like any other library once added

    #include "ScrewDriver.h"

## Setup
A variable map must be created and initialized to link variables
Variable map is of type:

    VARIABLE_PAIR variableMap[size];
A variable pair is what actually creates the linking and is of type:

    struct VARIABLE_PAIR {
      String varName;
      VAR var;
    };
> Note: The variable pair can link to all the arduino defined [data types](https://www.arduino.cc/reference/en/#structure)


An example of this is:

    double d = 1.0;
    int i = 2;

    ScrewDriver::VARIABLE_PAIR variableMap[] =
    {
      { "var0", VAR(&d) },
      { "var1", VAR(&i) }
    };
    const unsigned int numVariables = 2;
> Note: Make sure the variables set in the map do not go out of scope! An easy way around this is to set them as globals

All that is left is to parse the commands to run on the variables
The commands currently supported are:

1. list
2. update \<variable\> \<value\>
3. print \<variable\>

Commands are ran using

    ScrewDriver::Run()

continuing from the previous example:

    sd.Run("update var0 2.718281828459045");

To read from the Serial monitor just set up a while loop in the loop() function like such:

    if (Serial.available() > 0) {
      String s = Serial.readString();
      sd.Run(s);
    }

## Example snippet

To wrap it up is a snippet of the program in action using the above example setup variables:
```js
list

var0: 1.00
var1: 2
update var0 42

update var1 60

print var0

var0: 42.00
list

var0: 42.00
var1: 60
```
