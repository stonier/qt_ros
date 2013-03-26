
import os
import shutil
from utils import author_name
from utils import read_template
from utils import instantiate_template

##############################################################################
# Template
##############################################################################

def get_qt_text_templates(package, type):
    template_dir = os.path.join(os.path.dirname(__file__),'templates',type) 
    templates = {}
    templates['mainpage.dox'] = read_template(os.path.join(template_dir,'mainpage.dox'))
    templates['CMakeLists.txt'] = read_template(os.path.join(template_dir,'CMakeLists.txt'))
    templates['package.xml'] = read_template(os.path.join(template_dir,'package.xml'))
    templates[os.path.join('ui','main_window.ui')] = read_template(os.path.join(template_dir,'ui','main_window.ui'))
    templates[os.path.join('src','main.cpp')] = read_template(os.path.join(template_dir,'src','main.cpp'))
    templates[os.path.join('src','main_window.cpp')] = read_template(os.path.join(template_dir,'src','main_window.cpp'))
    templates[os.path.join('src','qnode.cpp')] = read_template(os.path.join(template_dir,'src','qnode.cpp'))
    templates[os.path.join('resources','images.qrc')] = read_template(os.path.join(template_dir,'resources','images.qrc'))
    templates[os.path.join('include',package,'main_window.hpp')] = read_template(os.path.join(template_dir,'include','PACKAGE_NAME','main_window.hpp'))
    templates[os.path.join('include',package,'qnode.hpp')] = read_template(os.path.join(template_dir,'include','PACKAGE_NAME','qnode.hpp'))
    return templates

def create_qt_ros_package(package, depends, type):
    
    p = os.path.abspath(package)
    os.makedirs(os.path.join(p,"src"))
    os.makedirs(os.path.join(p,"include"))
    os.makedirs(os.path.join(p,"include",package))
    os.makedirs(os.path.join(p,"resources"))
    os.makedirs(os.path.join(p,"resources","images"))
    os.makedirs(os.path.join(p,"ui"))
    print "Created qt package directories."

    # Qt text files
    templates = get_qt_text_templates(package, type)
    for filename, template in templates.iteritems():
        contents = instantiate_template(template, package, package, author_name(), depends)
        try:
            p = os.path.abspath(os.path.join(package, filename))
            f = open(p, 'w')
            f.write(contents)
            print "Created package file", p
        finally:
            f.close()
    # Qt binary files
    template_dir = os.path.join(os.path.dirname(__file__),'templates',type) 
    shutil.copy(os.path.join(template_dir,'resources','images','icon.png'),
                os.path.join(os.path.abspath(package),'resources','images','icon.png'))
    
def create_qt_ros_catkin_package(package, depends):
    create_qt_ros_package(package, depends, 'qt-ros')
