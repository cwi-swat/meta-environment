# $Id$

SUBDIRS = terms
include $(top_srcdir)/make_rules

# During development
CFLAGS += -Werror

QUERIES = \
  findSortDefinition.c \
  findProduction.c

TESTS = \
  testSortDefinition \
  testProduction

TOOL = query-tool

EXTRA_DIST = $(TOOL).idef

bin_PROGRAMS = $(TOOL)
noinst_PROGRAMS = $(TESTS)
pkgdata_DATA = $(TOOL).idef

SOURCE = \
  $(QUERIES) \
  $(TOOL).c \
  $(TOOL).tif.c \
  $(TOOL).tif.h

INCLUDES = \
  -I$(TOOLBUSLIB)/include \
  -I$(PT_SUPPORT)/include \
  -I$(SDF_SUPPORT)/include \
  -I$(ATERM)/include \
  -DSRC_DIR=\"${srcdir}\"

LIBS = \
  -L$(SDF_SUPPORT)/lib -lPT2SDF -lSDFME \
  -L$(PT_SUPPORT)/lib -lmept \
  -L$(TOOLBUSLIB)/lib -lATB \
  -L$(ATERM)/lib -lATerm \
  $(SOCKLIBS)

query_tool_SOURCES = $(SOURCE)
query_tool_LDADD = $(LIBS)

testProduction_SOURCES = testProduction.c findProduction.c
testProduction_LDADD = $(LIBS)

testSortDefinition_SOURCES = testSortDefinition.c findSortDefinition.c
testSortDefinition_LDADD = $(LIBS)
