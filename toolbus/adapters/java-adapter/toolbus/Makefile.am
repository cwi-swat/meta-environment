javadir		= ${prefix}/classes/toolbus

CLEANFILES	= test.tifs example.tifs \
		Example{Tif,Tool,Bridge}.java \
		Testing{Tif,Tool,Bridge}.java

EXTRA_DIST	= test.tb test.tifs example.tb example.tifs

java_JAVA	= Tool.java AbstractTool.java TestTool.java JavaTif.java \
		Testing.java Example.java SwingTool.java

JAVAROOT	= ${top_builddir}/adapters/java-adapter/

# This is some kind of hack to make sure that generated Java files are
# generated before compiling all other java files but that it will
# not be included in the distribution nor that it will be generated
# during a make dist.
TESTCLASSES	= TestingTif.java TestingTool.java TestingBridge.java 
EXAMPLECLASSES	= ExampleTif.java ExampleTool.java ExampleBridge.java 

noinst_SCRIPTS	= ${TESTCLASSES} ${EXAMPLECLASSES}

bin_SCRIPTS	= tifstojava
CLASSPATH_ENV	= CLASSPATH=${JAVAROOT}:${JAVA_ATERM}:${SHARED_OBJECTS}

JAVATIFCLASSES = \
	Tool.class \
	AbstractTool.class \
	SwingTool.class \
	JavaTif.class \
	SpecOrderVector.class

${EXAMPLECLASSES}: example.tifs $(JAVATIFCLASSES)
	$(CLASSPATH_ENV) \
	${top_builddir}/adapters/java-adapter/toolbus/tifstojava \
	-tifs $(srcdir)/example.tifs -tool example -package toolbus

${TESTCLASSES}: test.tifs $(JAVATIFCLASSES)
	$(CLASSPATH_ENV) \
	${top_builddir}/adapters/java-adapter/toolbus/tifstojava \
	-tifs $(srcdir)/test.tifs -tool testing -package toolbus

test.tifs: test.tb
	${top_builddir}/toolbus/toolbus -gentifs test.tb
	

example.tifs: example.tb
	${top_builddir}/toolbus/toolbus -gentifs example.tb

%.class: %.java
	$(CLASSPATH_ENV) $(JAVAC) $(JAVACFLAGS) -O -d $(JAVAROOT) $<
