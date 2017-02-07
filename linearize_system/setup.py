# setup.py

import sys
import os

if sys.platform == 'darwin':
    from distutils import sysconfig
    vars = sysconfig.get_config_vars()
    vars['LDSHARED'] = vars['LDSHARED'].replace('-bundle', '-dynamiclib')

from distutils.core import setup, Extension

mjpro_path   = os.environ['MUJOCO_PY_MJPRO_PATH']
include_dirs = mjpro_path + '/include'
library_dirs = mjpro_path + '/bin'

setup(name="_jacMujoco",
      py_modules=['_jacMujoco'],
      ext_modules=[Extension("_jacMujoco",
                             ["derivative.i","derivative.cpp"],
                             include_dirs=[include_dirs],
                             library_dirs=[library_dirs],
                             libraries=['mujoco131'],
                             swig_opts=['-c++'],
                             )]
      
      )
