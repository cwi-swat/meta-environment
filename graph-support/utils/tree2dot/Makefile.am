# $Id$

bin_PROGRAMS		= tree2dot

INCLUDES		= -I${PT_SUPPORT}/include \
			-I${ATERM}/include 

noinst_HEADERS		= PT2dot.h

tree2dot_SOURCES        = tree2dot-main.c PT2dot.c
tree2dot_LDADD          = -L${PT_SUPPORT}/lib -lmept \
                          -L${ATERM}/lib -lATerm

