
##############################################################################
# Console Output
##############################################################################

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