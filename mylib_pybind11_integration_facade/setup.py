from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

ext_modules = [
    Pybind11Extension("my_extension", ["MyLibFacade.cpp", "my_extension.cpp"],
        include_dirs=["../mylib"], library_dirs=["../mylib"], libraries=["mylib"])
]

setup(
    name="my_extension",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)
