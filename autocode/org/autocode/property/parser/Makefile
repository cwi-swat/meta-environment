
JAVAROOT = ../../../..

CLASSES = PropertyParser.class

all: ${CLASSES}

%.class: %.java
	javac -classpath ${JAVAROOT} $<

PropertyParser.java: PropertyParser.jj
	javacc $<

mycheck:
	java -classpath ${JAVAROOT} \
		org.autocode.property.parser.PropertyParser \
		< test.prop
