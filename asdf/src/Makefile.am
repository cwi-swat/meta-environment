# $Id$

EXTRA_DIST = action.sh.src

CLEANFILES = action

bin_SCRIPTS = action

% : %.sh.src Makefile
	sed 's@__ASF__@${ASF}@g;\
	     s@__META__@${META}@g;\
	     s@__PREFIX__@${prefix}@' < $< > $@ && chmod +x $@
