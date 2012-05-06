from distutils.core import setup

import sys
sys.path.insert(0, 'src')

from qt_create import __version__

setup(name='roscreate-qt-pkg',
      version= __version__,
      packages=['qt_create'],
      package_dir = {'':'src'},
      scripts = ["scripts/roscreate-qt-pkg","scripts/roscreate-qt-legacy-pkg"],
      package_data = {'qt_create': [
           'templates/qt-ros/CMakeLists.txt',
           'templates/qt-ros/src/*.cpp',
           'templates/qt-ros/ui/*.ui',
           'templates/qt-ros/include/PACKAGE_NAME/*.hpp',
           'templates/qt-ros/resources/*.qrc',
           'templates/qt-ros/resources/images/*.png',
           'templates/qt-ros/mainpage.dox',
           'templates/qt-ros/manifest.xml',
           'templates/qt-ros/Makefile',
           'templates/qt-ros-legacy/CMakeLists.txt',
           'templates/qt-ros-legacy/src/*.cpp',
           'templates/qt-ros-legacy/ui/*.ui',
           'templates/qt-ros-legacy/include/PACKAGE_NAME/*.hpp',
           'templates/qt-ros-legacy/resources/*.qrc',
           'templates/qt-ros-legacy/resources/images/*.png',
           'templates/qt-ros-legacy/mainpage.dox',
           'templates/qt-ros-legacy/manifest.xml',
           'templates/qt-ros-legacy/Makefile',
           ]},
      author = "Daniel Stonier",
      author_email = "d.stonier@gmail.com",
      url = "http://pypi.python.org/pypi/roscreate-qt-pkg/",
      download_url = "https://github.com/stonier/qt_ros.git",
      keywords = ["ROS"],
      classifiers = [
        "Programming Language :: Python",
        "License :: OSI Approved :: BSD License" ],
      description = "Creates qt package templates for RoS",
      long_description = open('README.txt').read(),
      license = "BSD"
      )

