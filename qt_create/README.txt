===========
Roscreate-Qt
===========

Provides scripts for generating (wizard-style) qt-based ros packages
from common templates. It caters for both traditional rosbuild and
newer catkin packages.

Typical usage looks like this::

    roscreate-qt-pkg qfoo        # catkinized package
    roscreate-qt-legacy-pkg qfoo # rosbuild package

Notes
=========

The packages generated include a master chooser, logging and
simple sigslot connections for interaction between the ros 
node and the qt program.

