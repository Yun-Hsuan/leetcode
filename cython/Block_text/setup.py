from distutils.core import setup, Extension
from Cython.Build import cythonize
from Cython.Distutils import build_ext
import numpy as np

ext = Extension("pyUni10",
                sources=["pyUni10.pyx", "Block.cpp", "Matrix.cpp"],
                extra_compile_args=["-O3", "-Wno-unused-function", "-Wno-constant-logical-operand"],
                include_dirs=[np.get_include()],
                language="c++")

setup(
      name="pyUni10",
      ext_modules=cythonize(ext))

#setup(
#      name = 'pyBlock',
#      ext_modules=[
#            Extension('pyBlock', 
#                  sources=['pyBlock.pyx', 'Block.cpp'],
#                  extra_compile_args=['-O3', '-Wno-constant-logical-operand'],
#                  language='c++'
#            ) 
#      ],
#      cmdclass = {'build_ext': build_ext}
#
#)
