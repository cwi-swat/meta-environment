SUBDIRS = repository plugin

javadir = ${prefix}/classes/org/autocode/generator/c

JAVAROOT = ${top_builddir}

EXTRA_DIST = c-compilation-unit.ace c-generator.ace

api:
	${top_builddir}/autocode-test \
		--application c-repository \
		--property "java->rootdir:=\"${top_builddir}\"" \
		c-generator.ace

java_JAVA = \
	CGenerator.java
