
EXTRA_DIST	= MANIFEST.MF default.properties
noinst_SCRIPTS  = default.properties

%.properties : %.properties.src
	sed 's@__ASF_LIBRARY_PATH__@${ASF_LIBRARY}/share/asf-library@g' < $< > $@
