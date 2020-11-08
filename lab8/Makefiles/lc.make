# lc.mak - sample makefile
#
# Kurt Schmidt
# 9 JUL 14
#
# GNU Make 3.81
#

WC = wc
RM = \rm

	# .PHONY indicates that these targets are fake.  They will be made, even
	#   if such a named file already exists
.PHONY : hey clean


	# :: make it a terminal rule.  Dependencies can not be intermediates
	#  (if it doesn't exist, no rule to make will be searched)
lc :: foo.c
		# the leading - tells make to ignore any errors
	-[ -f lc ] && $(RM) lc
	$(WC) -l foo.c > lc

hey :
	@echo "Kilroy was here"
	@echo "My name is $${USER}"

clean :
	-\rm lc
