'''
Various common core functions.

@author: Daniel Stonier
'''

import os
import re
import sys
import subprocess
import roslib

class Console:
    bold = "\033[1m"
    reset = "\033[0;0m"
    red = "\033[31m"

def red_string(msg):
    """bound string with console symbols for red output"""
    return Console.red + msg + Console.reset

def bold_string(msg):
    """bound string with console symbols for bold output"""
    return Console.bold + msg + Console.reset

# Finds and reads one of the templates.
def read_template(tmplf):
    f = open(tmplf, 'r')
    try:
        t = f.read()
    finally:
        f.close()
    return t

# This inserts the labelled variables into the template wherever the corresponding
# %package, %brief, %description and %depends is found.
def instantiate_template(template, package, brief, description, author, depends):
    return template%locals()
