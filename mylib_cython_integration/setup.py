from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

ext_modules = [Extension(name="my_extension", sources=["my_extension.pyx"], include_dirs=["../mylib"], library_dirs=["../mylib"], libraries=["mylib"], language='c++')]

setup(
  name = 'my_extension',
  ext_modules = cythonize(ext_modules)
)
