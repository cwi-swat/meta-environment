SUBDIRS	= org test

EXTRA_DIST = brainstorm.txt todo.txt

bin_SCRIPTS = autocode

noinst_SCRIPTS = autocode-test

CLASS = org.autocode.generator.Main

javadir = ${prefix}/classes/org/autocode

CLEANFILES = $(foreach f, ${MODULES}, $f.sh $f.sh.log)

autocode-test: Makefile.am
	@( \
	echo "#! /bin/sh"; \
	echo "set -e"; \
	echo "java -classpath" `pwd` "${CLASS}" '$$@'; \
	) > $@ && chmod +x $@

autocode: Makefile.am
	@( \
	echo "#! /bin/sh"; \
	echo "set -e"; \
	echo "java -classpath ${javadir} ${CLASS}" '$$@'; \
	) > $@ && chmod +x $@
