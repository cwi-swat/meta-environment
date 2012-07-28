include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = pandora 

noinst_HEADERS = mapping.h pandora.h Box.h Box-utils.h Box_dict.h 

pkgdata_DATA = pandora.idef

pandora_SOURCES = \
	main.c \
	mapping.c \
	Box.c \
	Box-utils.c \
	Box_dict.c \
	Box-to-Text.c \
	pandora.isrc

AM_CPPFLAGS += ${ASC_SUPPORT_CFLAGS}
pandora_LDADD = ${ASC_SUPPORT_LIBS}

asfc:
	asfc \
		-i ${top_builddir}/spec/text/Box-to-Text.eqs \
		-o Box-to-Text.c -v 

api:
	sdf2-to-c -i Box.def --prefix BOX_ -v

