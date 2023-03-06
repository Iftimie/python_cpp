import ctypes
import numpy as np

image = np.zeros((1, 5), dtype=np.uint8)
image[0, 1] = 1
image[0, 3] = 3

mylib = ctypes.CDLL("./mylib_wrapper.so")
mylib_ptr = mylib.MyLibClass_new()
mylib.MyLibClass_print_value(mylib_ptr, 10)
mylib.MyLibClass_sendDataBuffer(mylib_ptr, image.ctypes.data_as(ctypes.POINTER(ctypes.c_char)))


mylib = ctypes.cdll.LoadLibrary("./mylib_wrapper.so")

MyLibClass_new = mylib.MyLibClass_new
MyLibClass_new.restype = ctypes.c_void_p
MyLibClass_new.argtypes = []
mylib_ptr = MyLibClass_new()

MyLibClass_print_value = mylib.MyLibClass_print_value
MyLibClass_print_value.restype = ctypes.c_void_p
MyLibClass_print_value.argtypes = [ctypes.c_void_p, ctypes.c_int]
MyLibClass_print_value(mylib_ptr, 10)
