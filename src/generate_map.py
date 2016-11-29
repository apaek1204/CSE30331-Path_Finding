#!/usr/bin/python

import sys
import random

size = sys.argv[1]

tileType = ['f', 'g', 'G', 'h', 'm', 'r']

tiles = ('6\n' +
	'f 3\n' +
	'g 1\n' +
	'G 2\n' +
	'h 4\n' +
	'm 7\n' +
	'r 5\n' +
	size + ' '+ size)

print tiles

#generate random map
size=int(size)
for i in range(0, size):
	temp = ''
	for j in range(0, size):
		temp += tileType[ random.randint(0, 5) ]
		if j != (size-1):
			temp+=' '
	print temp

#origin
print '0 0'
#destination
print str(size-1) + ' ' + str(size-1)
