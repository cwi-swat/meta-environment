include make_rules

SUBDIRS		= util spec rscripts demo rviz

ACLOCAL_FLAGS 	= -I .

CLEANFILES 	= ${PACKAGE}-${VERSION}.pkg

DIST_SUBDIRS	= util spec rscripts demo rviz

EXTRA_DIST	= $(wildcard *.pkg) make_rules reconf $(wildcard *.m4) package

DISTFILE 	= ${distdir}.tar.gz

WWWDIR 		= /hosts/www/projects/MetaEnv/relation-calculus

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

VERSION		= 0.2



