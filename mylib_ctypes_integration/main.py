import ctypes
import numpy as np

image = np.zeros((1, 5), dtype=np.uint8)
image[0, 1] = 1
image[0, 3] = 3

c_lib = ctypes.CDLL("../mylib/libmylib.so")
mylib_ptr = c_lib._ZN10MyLibClassC1Ev()
c_lib._ZN10MyLibClass10printValueEi(mylib_ptr, 10)
c_lib._ZN10MyLibClass14sendDataBufferEPc(mylib_ptr, image.ctypes.data_as(ctypes.POINTER(ctypes.c_char)))
