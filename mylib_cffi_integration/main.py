import cffi
import numpy as np

image = np.zeros((1, 5), dtype=np.uint8)
image[0, 1] = 1
image[0, 3] = 3

ffi = cffi.FFI()
ffi.cdef("void* _ZN10MyLibClassC1Ev();")
ffi.cdef("void _ZN10MyLibClass11print_valueEi(void* obj, int x);")
ffi.cdef("void _ZN10MyLibClass14sendDataBufferEPc(void* obj, char* ptr);")
C = ffi.dlopen("../mylib/libmylib.so")

obj = C._ZN10MyLibClassC1Ev()
C._ZN10MyLibClass11print_valueEi(obj, 10)
C._ZN10MyLibClass14sendDataBufferEPc(obj, ffi.cast("char *", image.ctypes.data))
