SUBDIRS = toolbus

EXTRA_DIST = java-adapter
bin_SCRIPTS = java-adapter

jar:
	jar cf java-adapter-1.0.jar \
		`find . -name '*.class' -o -name '*.java'`
