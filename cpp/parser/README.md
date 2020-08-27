# Parser

## Executing code
This exercise is built with CMake, and the folling commands should be sufficient to build and run it:
```
mkdir build
cd build/
cmake ..
cmake --build .
./parser_test
```

## True log
We have here a very simple string parser that does its job in splitting up a given string along whitespaces. 
Though, due to some strange sides effects appearing sparsingly, the team decided to add a logging point after
the parsing stage, in order to retain the number of words extracted. You volunteered to take this task on.
