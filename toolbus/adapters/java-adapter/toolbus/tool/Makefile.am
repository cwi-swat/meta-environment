bin_SCRIPTS = javatif

java_JAVA   = JavaTif.java TestTool.java ToolException.java \
              Test.java  Tool.java 

EXTRA_DIST  = test.tb  javatif.src

CLEANFILES  = test.tifs Testing.java javatif

javadir     = $(prefix)/classes/toolbus/tool

JAVAROOT    = $(top_builddir)/adapters/java-adapter/

%.tifs: %.tb
	$(top_builddir)/toolbus/toolbus -gentifs $<

TestingTool.java : Testing.java

Testing.java: test.tifs
	java -classpath ../..:$$CLASSPATH toolbus.tool.JavaTif \
           -tool testing -tifs test.tifs -package toolbus.tool

% : %.src
	sed 's#__PREFIX__#$(prefix)#g' < $< > $@ && \
	chmod +x $@
 
