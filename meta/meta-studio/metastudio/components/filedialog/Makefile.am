include ${top_srcdir}/make_rules

pkgdata_DATA = filedialog.idef
EXTRA_DIST = ${java_JAVA} filedialog.idef

CLASSPATH_ENV = CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${EXTERNAL_JARS}

JAVAROOT = ${top_builddir}/meta-studio
javadir = ${prefix}/classes/metastudio

jtif: 
	${IDEF} filedialog.idef
	${TOOLBUS}/bin/tifstojava -tool file-dialog -tifs filedialog.tifs \
		-package metastudio.components.filedialog -swing

java_JAVA = \
	FileDialog.java \
	FileDialogBridge.java \
	FileDialogTool.java \
	FileDialogTif.java
