from distutils.core import setup, Extension
from Cython.Build import cythonize

ext = Extension("pyBlock",
                sources=["pyBlock.pyx", "Block.cpp"],
                language="c++")

setup(name="pyBlock",
      ext_modules=cythonize(ext))
