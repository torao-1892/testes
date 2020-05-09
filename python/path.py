import os
import sys

print 'os.getcwd()',os.getcwd()
print '__file__', __file__
print 'sys.argv',sys.argv
print 'sys.path',sys.path
print 'os.path', os.path
print 'os.path.realpath(__file__)',os.path.realpath(__file__)
print 'os.path.dirname(__file__)',os.path.dirname(__file__) # relative directory path
print 'os.path.abspath(__file__)',os.path.abspath(__file__) # absolute file path
print 'os.path.basename(__file__)',os.path.basename(__file__) # the file name only
