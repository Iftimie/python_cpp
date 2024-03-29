cimport numpy as np

cdef extern from "mylib.hpp":
    cdef cppclass MyLibClass:
        MyLibClass()
        void printValue(int x)
        void sendDataBuffer(char* ptr)

def interact(image):
    my_lib_class_ptr = new MyLibClass()
    cdef char* data = <char*>np.PyArray_DATA(image)
    my_lib_class_ptr.printValue(5)
    my_lib_class_ptr.sendDataBuffer(data)

    del my_lib_class_ptr