
bin_SCRIPTS=rviz

SOURCES==rviz.tcl.src

% : %.tcl.src
	sed 's#__WISH__#$(WISH)#g;' < $< > $@
