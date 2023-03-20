#include <mylib.hpp>

extern "C"
{
    extern void* MyLibClass_new()
    {
        return new MyLibClass();
    }

    extern void MyLibClass_printValue(void* obj, int x) {
        ((MyLibClass*)obj)->printValue(x);
    }

    extern void MyLibClass_sendDataBuffer(void* obj, char* ptr) {
        ((MyLibClass*)obj)->sendDataBuffer(ptr);
    }
}