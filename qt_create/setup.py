#!/usr/bin/env pyyhon

from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

d = generate_distutils_setup(
      packages=['qt_create'],
      package_dir = {'':'src'},
      scripts = ["scripts/catkin_create_qt_pkg"],
      package_data = {'qt_create': [
           'templates/CATKIN_IGNORE',
           'templates/qt-ros/CMakeLists.txt',
           'templates/qt-ros/src/*.cpp',
           'templates/qt-ros/ui/*.ui',
           'templates/qt-ros/include/PACKAGE_NAME/*.hpp',
           'templates/qt-ros/resources/*.qrc',
           'templates/qt-ros/resources/images/*.png',
           'templates/qt-ros/mainpage.dox',
           'templates/qt-ros/package.xml',
           'templates/qt-ros/Makefile',
           ]},
      requires=[]
      )

setup(**d)

