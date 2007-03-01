# $Id$

EXTRA_DIST = rviz.tcl.src

bin_SCRIPTS = rviz

CLEANFILES = rviz

% : %.tcl.src
	sed "s#__WISH__#$(WISH)#g;" < $< > $@
