#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "mylib.hpp"
namespace py = pybind11;

void interact(py::array_t<unsigned char> image){
    MyLibClass* mylib_ptr = new MyLibClass();
    mylib_ptr->print_value(5);
    mylib_ptr->sendDataBuffer((char*)image.data());
    delete mylib_ptr;
}

PYBIND11_MODULE(my_extension, m) {
    m.def("interact", &interact);
}

