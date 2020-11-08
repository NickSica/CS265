cc = gcc
EXE = foo
JAVAC = javac
JRE = java
PAGER = less
TEST_OUT = test.out
EXP_OUT = expected.out

.PHONY: clean run-py run-c read run-java save-java test-java

foo.o: foo.c foo.h
	$(cc) -c foo.c -o $@ 

main.o: main.c foo.h
	$(cc) -c main.c -o $@

$(EXE): foo.o main.o
	$(cc) $^ -o $@

run-c: $(EXE)
	@./$^	

run-py: $(EXE).py
	@python ./$^

read:
	@if [ -f "README" ] ; then \
		cat README | $(PAGER) ;\
	fi

foo.class: foo.java
	@$(JAVAC) $^

run-java: foo.class
	@$(JRE) foo

save-java:
	@$(JRE) foo >> $(TEST_OUT)

test-java: $(TEST_OUT) $(EXP_OUT)
	-@if diff $(TEST_OUT) $(EXP_OUT) &> /dev/null ; then \
	  	echo "Passed!" ;\
	else \
		echo "Not the same!" ;\
	fi

clean:
	-rm *.o
	-rm test.out
	-rm *.class
	-rm foo
