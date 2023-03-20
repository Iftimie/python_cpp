#include "mylib.hpp"

extern "C" {
    MyLibClass* MyLibClass_new() {
        return new MyLibClass();
    }

    void MyLibClass_printValue(MyLibClass* obj, int x) {
        obj->printValue(x);
    }

    void MyLibClass_sendDataBuffer(MyLibClass* obj, char* ptr) {
        obj->sendDataBuffer(ptr);
    }  
}