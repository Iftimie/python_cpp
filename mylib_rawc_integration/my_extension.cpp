#include <Python.h>
#include <numpy/arrayobject.h>
#include "mylib.hpp"

static PyObject* interact(PyObject* self, PyObject* args) {
    PyArrayObject* array;
    if (!PyArg_ParseTuple(args, "O!", &PyArray_Type, &array)) {
        return NULL;
    }

    npy_uint8* data = (npy_uint8*)PyArray_DATA(array);

    MyLibClass* mylib_class_ptr = new MyLibClass();
    mylib_class_ptr->printValue(5);
    mylib_class_ptr->sendDataBuffer((char*) data);

    Py_DECREF(array);
    Py_RETURN_NONE;
}

static PyMethodDef methods[] = {
    {"interact", interact, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "my_extension",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_my_extension(void) {
    PyObject* m;
    import_array();

    m = PyModule_Create(&module);
    if (m == NULL) {
        return NULL;
    }

    return m;
}