SUBDIRS = trans

EXTRA_DIST = trans-adapter
bin_SCRIPTS = trans-adapter

jar:
	jar cf trans-adapter-1.0.jar \
		`find . -name '*.class' -o -name '*.java'`
