javadir		= ${prefix}/classes/toolbus

EXTRA_DIST	= ${java_JAVA} test.tb test.tifs example.tb example.tifs

java_JAVA =\
	Tool.java\
	AbstractTool.java\
	JavaTif.java\
	SwingTool.java
	Tool.class \
	AbstractTool.class \
	SwingTool.class \
	JavaTif.class \
	SpecOrderVector.class

JAVAROOT	= ${top_builddir}

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${EXTERNAL_JARS}

EXTRA_DIST = $(JAVASOURCES)
