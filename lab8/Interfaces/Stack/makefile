
cc = gcc
flags =

stack : main.o stack.o
	$(cc) $(flags) main.o stack.o -o $@

main.o : main.c stack.h
	$(cc) -c $(flags) main.c

stack.o : stack.c stack.h
	$(cc) -c $(flags) stack.c

.PHONY : clean cleanall

clean :
	-\rm *.o

cleanall : clean
	-\rm stack
