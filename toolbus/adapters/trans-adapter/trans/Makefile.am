javadir = ${prefix}/classes/trans

JAVAADAPTER = ${top_builddir}/adapters/java-adapter
JAVAROOT = ${top_builddir}/adapters/trans-adapter

CLASSPATH_ENV = CLASSPATH=${JAVAADAPTER}:${JAVAROOT}:${EXTERNAL_JARS}

%.class: %.java
	$(CLASSPATH_ENV) $(JAVAC) $(JAVACFLAGS) -O -d $(JAVAROOT) $<

java_JAVA =  \
	Adapter.java \
	DelegateBridge.java \
	DelegateConnection.java \
	DelegateTif.java \
	DelegateTool.java \
	MasqueradeBridge.java \
	MasqueradeConnection.java \
	MasqueradeTif.java \
	MasqueradeTool.java
