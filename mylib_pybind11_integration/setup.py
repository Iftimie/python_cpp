from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

setup(
    name="use_mylibfacade",
    ext_modules=[Pybind11Extension("my_extension", ["my_extension.cpp"], include_dirs=["../mylib"], library_dirs=["../mylib"], libraries=["mylib"])],
    cmdclass={"build_ext": build_ext},
)
