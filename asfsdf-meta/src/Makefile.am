# $Id$

EXTRA_DIST    = meta.sh.src pt-dump.sh.src eqs-dump.sh.src

bin_SCRIPTS = meta pt-dump eqs-dump

% : %.sh.src Makefile
	sed 's@__ASF__@${prefix}@g;\
	     s@__META__@${META}@' < $< > $@ && chmod +x $@
