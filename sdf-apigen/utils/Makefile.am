#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

include $(top_srcdir)/make_rules

EXTRA_DIST = sdf2-to-adt.sh.src \
	     sdf2-to-java.sh.src \
	     sdf2-to-c.sh.src \
	     CHARLIST_String.java.template \
	     CHARLIST.h.template \
	     CHARLIST.c.template \
	     string.adt

pkgdata_DATA= CHARLIST_String.java.template \
	      CHARLIST.c.template \
	      CHARLIST.h.template \
	      string.adt


bin_SCRIPTS = sdf2-to-adt sdf2-to-java sdf2-to-c 

noinst_SCRIPTS = sdf2-to-adt.test sdf2-to-java.test sdf2-to-c.test
	    
abs_top_srcdir = $(shell cd ${top_srcdir}; pwd)
abs_top_builddir = $(shell cd ${top_builddir}; pwd)

% : %.sh.src Makefile
	sed 's@__APIGEN__@${APIGEN}@g;\
	     s@__ATERM__@${ATERM}@g;\
	     s@__PT_SUPPORT__@${PT_SUPPORT}@g;\
	     s@__SGLR__@${SGLR}@g;\
	     s@__ASF__@${ASF}@g;\
	     s@__PKGDATA__@${pkgdatadir}@g;\
	     s@__SPECDATA__@${pkgdatadir}@g;\
	     s@__SDF2ADT__@${bindir}/sdf2-to-adt@g;\
	     s@__BINDIR__@${bindir}@g;\
	     s@__PREFIX__@${prefix}@g' < $< > $@ && chmod +x $@

%.test : %.sh.src Makefile
	sed 's@__APIGEN__@${APIGEN}@g;\
	     s@__ATERM__@${ATERM}@g;\
	     s@__PT_SUPPORT__@${PT_SUPPORT}@g;\
	     s@__SGLR__@${SGLR}@g;\
	     s@__ASF__@${ASF}@g;\
	     s@__PKGDATA__@${abs_top_srcdir}/utils@g;\
	     s@__SPECDATA__@${abs_top_builddir}/spec@g;\
	     s@__SDF2ADT__@${abs_top_builddir}/utils/sdf2-to-adt.test --table ${abs_top_srcdir}/spec/Sdf2-to-ADT.trm.tbl --label ${abs_top_srcdir}/spec/add-labels/AddLabels.eqs --generator ${abs_top_builddir}/spec/Sdf2-to-ADT@g;\
	     s@__BINDIR__@${abs_top_builddir}/utils@g;\
	     s@__PREFIX__@${abs_top_builddir}/utils@g' < $< > $@ && chmod +x $@
