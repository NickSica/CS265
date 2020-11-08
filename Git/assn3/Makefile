PAGER = less
TEST_OUT = test.out
EXP_OUT = expected.out

.PHONY: clean run-py run-c read run-java save-java test-java

view:
	@cat cddb | $(PAGER)
	@cat album.py | $(PAGER)

clean:
	-rm -r album.pyc
	-rm -r __pycache__
