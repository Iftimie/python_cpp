#include "mylib.hpp"

extern "C" {
    MyLibClass* MyLibClass_new() {
        return new MyLibClass();
    }

    void MyLibClass_print_value(MyLibClass* obj, int x) {
        obj->print_value(x);
    }

    void MyLibClass_sendDataBuffer(MyLibClass* obj, char* ptr) {
        obj->sendDataBuffer(ptr);
    }  
}