
SUBDIRS		= . tool

CLASSPATH	:= ${ATERM}/classes:${TOOLBUS}/classes

javadir		= ${prefix}/classes/tide
JAVAROOT	= ${top_builddir}

java_JAVA	= ${GENJAVA}

GENJAVA		= TideConfig.java

EXTRADIST	= TideConfig.java.src

# This is some kind of hack to make sure that generated Java files are
# generated before compiling all other java files but that it will
# not be included in the distribution nor that it will be generated
# during a make dist.
noinst_SCRIPTS  = ${GENJAVA}

%.java : %.java.src Makefile
	sed 's@__DATADIR__@$(datadir)@g;\
            ' < $< > $@

%.class: %.java
	$(CLASSPATH_ENV) $(JAVAC) $(JAVACFLAGS) -d $(JAVAROOT) $<

