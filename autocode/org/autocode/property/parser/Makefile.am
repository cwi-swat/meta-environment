MODULES = \
	PropertyParser \
	PropertyParserConstants \
	PropertyParserTokenManager \
	ParseException \
	SimpleCharStream \
	Token \
	TokenMgrError

EXTRA_DIST = PropertyParser.jj


javadir = ${prefix}/classes/org/autocode/property/parser

JAVAROOT = ${top_builddir}

java_JAVA = ${MODULES:%=%.java}

CLASSES = ${MODULES:%=%.class}

PropertyParser.java: PropertyParser.jj
	javacc -nostatic $<

CLEANFILES = ${MODULES:%=%.java}
