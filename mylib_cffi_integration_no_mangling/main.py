import cffi
import numpy as np


ffi = cffi.FFI()
ffi.cdef("void* MyLibClass_new();")
ffi.cdef("void MyLibClass_printValue(void* obj, int x);")
ffi.cdef("void MyLibClass_sendDataBuffer(void* obj, char* ptr);")
C = ffi.dlopen("./mylib_wrapper.so")

image = np.zeros((1, 5), dtype=np.uint8)
image[0, 1] = 1
image[0, 3] = 3

obj = C.MyLibClass_new()
C.MyLibClass_printValue(obj, 10)
C.MyLibClass_sendDataBuffer(obj, ffi.cast("char *", image.ctypes.data))
