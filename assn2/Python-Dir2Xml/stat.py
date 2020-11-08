#!/usr/bin/env python3
#
# Demonstrates:  os.listdir os.path.join os.stat stat stat.ST_MODE stat.S_ISREG os.path.abspath
#

import sys
import os
import stat

top = sys.argv[1]
IND = '   '

tests = {
	stat.S_ISREG : 'Regular' ,
	stat.S_ISDIR : 'Directory' ,
	# stat.S_ISLNK : 'Soft Link' ,  # TODO  Not working
	stat.S_ISFIFO : 'Named Pipe' ,
	stat.S_ISSOCK : 'Socket' 
}


for f in os.listdir( top ) :

	mode = os.stat( f )[stat.ST_MODE]

	# f = os.path.join( os.path.abspath( top ), f )

	for t, n in tests.items() :
		if t( mode ) :
			print( f'{n:11}: {f}' )
			break


