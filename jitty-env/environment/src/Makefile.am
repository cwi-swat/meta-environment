# $Id$

EXTRA_DIST    = jitty.sh.src

bin_SCRIPTS = jitty 

% : %.sh.src Makefile
	sed 's@__META__@${META}@g;\
	     s@__PREFIX__@${prefix}@' < $< > $@ && chmod +x $@
