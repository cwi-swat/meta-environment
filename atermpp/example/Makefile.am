EXTRA_DIST = Jamfile.v2 

noinst_PROGRAMS = \
	aterm_list \
	make_term

INCLUDES = \
	-I$(top_srcdir) \
	-I$(BOOST_INCLUDE) \
	-I$(ATERM_INCLUDE)

aterm_list_SOURCES = aterm_list.cpp
aterm_list_LDADD = -L$(ATERM_LIB) -lATerm

make_term_SOURCES = make_term.cpp
make_term_LDADD = -L$(ATERM_LIB) -lATerm
