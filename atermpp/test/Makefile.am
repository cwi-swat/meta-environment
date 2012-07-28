EXTRA_DIST = Jamfile.v2 

TESTS = \
	constructors \
	make_term

check_PROGRAMS = $(TESTS)

INCLUDES = \
	-I$(top_srcdir) \
	-I$(BOOST_INCLUDE) \
	-I$(ATERM_INCLUDE)

constructors_SOURCES = constructors.cpp
constructors_LDADD = -L$(ATERM_LIB) -lATerm

make_term_SOURCES = make_term.cpp
make_term_LDADD = -L$(ATERM_LIB) -lATerm
