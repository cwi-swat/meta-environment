# $Id$

EXTRA_DIST = $(wildcard *.src)

bin_SCRIPTS = asfsdf-meta pt-dump eqs-dump asfsdf-meta-config

TBSCRIPTS = \
	    -I$(prefix)/share/asfsdf-meta \
	    -I$(ASF)/share/asf \
	    `$(SDF_META)/bin/sdf-meta-config --toolbus-includes`

CLEANFILES = \
	asfsdf-meta \
	asfsdf-meta-config \
	pt-dump \
	eqs-dump

% : %.sh.src Makefile
	sed 's@__ASF__@${ASF}@g;\
	     s@__META__@${META}@g;\
	     s@__TOOLBUS__@${TOOLBUS}@g;\
	     s@__PREFIX__@${prefix}@g;\
	     s@__TBSCRIPTS__@${TBSCRIPTS}@g;' < $< > $@ && chmod +x $@
