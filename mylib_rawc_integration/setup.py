from distutils.core import setup, Extension
import numpy

setup(
    name="my_extension",
    version="1.0.0",
    ext_modules=[Extension("my_extension", sources=["my_extension.cpp"], extra_compile_args=["-Wall", "-std=c++11"], include_dirs=["../mylib", numpy.get_include()], library_dirs=["../mylib"], libraries=["mylib"])],
)