javadir		= ${prefix}/classes/toolbus

CLEANFILES	= test.tifs example.tifs

EXTRA_DIST	= test.tb test.tifs example.tb example.tifs

java_JAVA	= Tool.java AbstractTool.java TestTool.java JavaTif.java \
		Testing.java Example.java

JAVAROOT	= ${top_builddir}/aterm/java/

# This is some kind of hack to make sure that generated Java files are
# generated before compiling all other java files but that it will
# not be included in the distribution nor that it will be generated
# during a make dist.
TESTCLASSES	= TestingTif.java TestingTool.java TestingBridge.java 
EXAMPLECLASSES	= ExampleTif.java ExampleTool.java ExampleBridge.java 

noinst_SCRIPTS	= ${TESTCLASSES} ${EXAMPLECLASSES}

bin_SCRIPTS	= tifstojava

${EXAMPLECLASSES}: example.tifs JavaTif.class
	CLASSPATH=${top_srcdir}/aterm/java:${CLASSPATH} \
	${top_srcdir}/aterm/java/toolbus/tifstojava \
	-tifs example.tifs -tool example -package toolbus

${TESTCLASSES}: test.tifs JavaTif.class
	CLASSPATH=${top_srcdir}/aterm/java:${CLASSPATH} \
	${top_srcdir}/aterm/java/toolbus/tifstojava \
	-tifs test.tifs -tool testing -package toolbus

test.tifs: test.tb
	${top_builddir}/toolbus/toolbus -gentifs test.tb

example.tifs: example.tb
	${top_builddir}/toolbus/toolbus -gentifs example.tb

%.class: %.java
	$(CLASSPATH_ENV) $(JAVAC) $(JAVACFLAGS) -O -d $(JAVAROOT) $<
