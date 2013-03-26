##############################################################################
# Utilities
##############################################################################

def author_name():
    """
    Utility to compute logged in user name
    
    :returns: name of current user, ``str``
    """
    import getpass
    name = getpass.getuser()
    try:
        import pwd
        login = name
        name = pwd.getpwnam(login)[4]
        name = ''.join(name.split(',')) # strip commas
        # in case pwnam is not set
        if not name:
            name = login
    except:
        #pwd failed
        pass
    if type(name) == str:
        name = name.decode('utf-8')
    return name

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
def instantiate_template(template, package, description, author, depends):
    return template%locals()
