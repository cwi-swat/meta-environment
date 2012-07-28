SUBDIRS	= org test

EXTRA_DIST = brainstorm.txt todo.txt

data_DATA = autocode.jar

bin_SCRIPTS = autocode

noinst_SCRIPTS = autocode-test

CLASS = org.autocode.generator.Main

javadir = ${prefix}/classes/org/autocode

CLEANFILES = $(foreach f, ${MODULES}, $f.sh $f.sh.log)

.PHONY: autocode.jar
autocode.jar:
	jar cf autocode.jar `find org -name "*.class" -o -name "*.aco"`

autocode-test: Makefile.am
	@( \
	echo "#! /bin/sh"; \
	echo "set -e"; \
	echo "java -classpath" .:`pwd` "${CLASS}" '$$@'; \
	) > $@ && chmod +x $@

autocode: Makefile.am
	@( \
	echo "#! /bin/sh"; \
	echo "set -e"; \
	echo "java -classpath .:${prefix}/share/autocode.jar ${CLASS}" '$$@'; \
	) > $@ && chmod +x $@
