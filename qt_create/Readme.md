## Catkin Create Qt

Provides scripts for generating (wizard-style) qt-based ros packages
from common templates. It caters for both traditional rosbuild and
newer catkin packages.

Typical usage looks like this::

    roscreate-qt-pkg qfoo        # catkinized package


## Notes

The packages generated include a master chooser, logging and
simple sigslot connections for interaction between the ros 
node and the qt program.

## Dev Notes

This package is setup for pypi creation, but at the moment
I'm just going to install it to catkin's global bin directory
until I work out how to get debs building for our python build tools.
