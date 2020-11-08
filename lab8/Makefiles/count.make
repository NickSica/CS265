SHELL = bash

linecount : foo.c
	-[ -e linecount ] && rm linecount
	-wc -l foo.c > linecount

name :
	@echo $${USER%d*}

toten :
	for (( i=1; i<=10; ++i )) ; do \
		echo $$i ;\
	done

.PHONY : hey
hey :
	echo $$USER

