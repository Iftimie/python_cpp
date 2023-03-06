#include <mylib.hpp>

extern "C"
{
    extern void* MyLibClass_new()
    {
        return new MyLibClass();
    }

    extern void MyLibClass_print_value(void* obj, int x) {
        ((MyLibClass*)obj)->print_value(x);
    }

    extern void MyLibClass_sendDataBuffer(void* obj, char* ptr) {
        ((MyLibClass*)obj)->sendDataBuffer(ptr);
    }
}