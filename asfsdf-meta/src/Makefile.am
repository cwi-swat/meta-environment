# $Id$

EXTRA_DIST    = meta.sh.src pt-dump.sh.src eqs-dump.sh.src \
		sdf-editor.sh.src asf-editor.sh.src term-editor.sh.src

bin_SCRIPTS = meta pt-dump eqs-dump sdf-editor asf-editor term-editor

% : %.sh.src Makefile
	sed 's@__ASF__@${ASF}@g;\
	     s@__META__@${META}@g;\
	     s@__PREFIX__@${prefix}@' < $< > $@ && chmod +x $@
