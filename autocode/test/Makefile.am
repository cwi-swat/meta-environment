MODULES = autocode
#JAVAMODULES = Test

#java_JAVA = $(foreach f, ${JAVAMODULES}, $f.java)

JAVAROOT = ${top_builddir}

javadir = ${prefix}/classes/org/autocode/test

EXTRA_DIST = $(foreach f, ${MODULES}, $f.add)

TESTS = $(foreach f, ${MODULES}, $f.sh) $(foreach f, ${JAVAMODULES}, $f.sh)

CLASS = "org.autocode.property.parser.PropertyParser"
PARSE = "java -classpath ${top_builddir} ${CLASS}"

CLEANFILES = $(foreach f, ${MODULES}, $f.sh $f.sh.log)

%.sh: %.add
	@( \
	echo "#! /bin/sh"; \
	echo "set -e"; \
	echo "${PARSE} < $< > $@.log"; \
	) > $@ && chmod +x $@

%.sh: %.class
	@( \
	echo "#! /bin/sh"; \
	echo "set -e"; \
	echo "java -classpath ${top_builddir} test.$*"; \
	) > $@ && chmod +x $@

mycheck:
	mkdir -p ${top_builddir}/test/org/autocode/test
	${top_srcdir}/autocode-test \
		--application client-app \
		--property "java->rootdir:=\"${top_builddir}/test\"" \
		client-app.add
	javadoc \
		-classpath ${top_builddir} \
		-sourcepath ${top_builddir}/test \
		-d ${top_builddir}/test/html \
		org.autocode.test

