#!/usr/bin/env python3

import sys
import os

top = sys.argv[1]
IND = '   '

for root, dirs, files in os.walk( top ) :
	print( f'{root}:\n=================' )

	for d in dirs :
		print( f'{IND}DIR: {d}' )
	for f in files :
		print( f'{IND}FILE: {f}' )
	
	print( '' )
