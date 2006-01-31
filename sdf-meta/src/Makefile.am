# $Id$

EXTRA_DIST = sdf-meta.sh.src

CLEANFILES = sdf-meta

bin_SCRIPTS = sdf-meta

% : %.sh.src Makefile
	sed 's@__ASF__@${ASF}@g;\
	     s@__META__@${META}@g;\
	     s@__PREFIX__@${prefix}@' < $< > $@ && chmod +x $@
