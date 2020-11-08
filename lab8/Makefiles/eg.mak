# eg.mak
#
# Kurt Schmidt
# JUL 2014
#
# GNU Make 3.81
#
# EDITOR: tabstop=2, cols=80
#
# Demonstrates: variables .PHONY bash multiline "environment variables"
#
# To run:
#  $ make -f eg.mak <target>
#

	# variables, for portability.  Can be read from another file
cc = gcc
OBJ = o
EXE = main


	# this will be the default target, if none is supplied
$(EXE) : main.$(OBJ) foo.$(OBJ)
	$(cc) -o $@ main.$(OBJ) foo.$(OBJ)

	# :: describe terminal rules.  Dependencies won't be built, if they don't
	#   exist
foo.$(OBJ) :: foo.c foo.h
	$(cc) -c foo.c

main.$(OBJ) :: main.c foo.h
	$(cc) -c main.c


	# A single rule can produce multiple targets
tmp1 tmp2 :
	[ ! -e tmp1 ] && touch tmp1
	[ ! -e tmp2 ] && touch tmp2

	# .PHONY targets will be built, even if named files exist
.PHONY : clean hello

hello :
	@ echo Hello.  My name is $${USER}

clean :
	- \rm *.$(OBJ)
	- \rm main

count :
	for (( i=0; i<10; ++i )) ;\
	do \
		echo $$i ;\
	done
