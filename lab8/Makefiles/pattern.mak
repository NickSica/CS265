# pattern.mak
#
# Kurt Schmidt
# JUL 2014
#
# GNU Make 3.81
#
# EDITOR: tabstop=2, cols=80
#
# Demonstrates: variables .PHONY pattern
#
# To run:
#  $ make -f pattern.mak <target>
#
# NOTE:  Make has built-in pattern rules.  Look them up.
#

	# variables, for portability.  Can be read from another file
cc = gcc
CC = g++


	# Compile C files (do not link)
%.o :: %.c
	$(cc) -c $< -o $@

	# Compile C++ files (do not link)
%.o :: %.cc
	$(CC) -c $< -o $@

%.o :: %.cpp
	$(CC) -c $< -o $@

%.o :: %.C
	$(CC) -c $< -o $@
