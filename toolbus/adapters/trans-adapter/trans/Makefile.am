javadir = ${prefix}/classes/trans

JAVAADAPTER = ${top_builddir}/adapters/java-adapter
JAVAROOT = ${top_builddir}/adapters/trans-adapter

CLASSPATH_ENV = CLASSPATH=${JAVAADAPTER}:${JAVAROOT}:${EXTERNAL_JARS}

%.class: %.java
	$(CLASSPATH_ENV) $(JAVAC) $(JAVACFLAGS) -O -d $(JAVAROOT) $<

java_JAVA =  \
	Adapter.java \
	Connection1.java \
	Connection2.java \
	Tb1Bridge.java \
	Tb1Tif.java \
	Tb1Tool.java \
	Tb2Bridge.java \
	Tb2Tif.java \
	Tb2Tool.java
