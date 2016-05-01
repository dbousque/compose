

import sys

def my_func(string, to_add):
	return string + " : to_add==" + str(to_add) + "."

args = sys.argv[1:]
for elt in args:
	print my_func("line_start", int(elt))