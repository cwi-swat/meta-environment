
EXTRA_DIST	= MANIFEST.MF default.properties
noinst_SCRIPTS  = default.properties
CLEANFILES+=default.properties

default.properties : default.properties.src
	sed 's@__ASF_LIBRARY_PATH__@${ASF_LIBRARY}/share/asf-library@g' < $< > $@
