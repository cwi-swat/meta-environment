include $(top_srcdir)/Makefile.java.meta

SUBDIRS = 

ACLOCAL_AMFLAGS = -I .

api: MEPT.adt
	adt-to-java -i $< -p nl.cwi.sen1 -n ptapi --nojar -o src
