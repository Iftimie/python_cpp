#include "mylib.hpp"
#include <stdio.h>

MyLibClass::MyLibClass(){ }

void MyLibClass::printValue(int x)
{
    printf("Printing value %d\n", x);
}

void MyLibClass::sendDataBuffer(char* ptr)
{
    for(int i = 0; i < 5; i++) {
        printf("%d ", (int)ptr[i]);
    } 
}