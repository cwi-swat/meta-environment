#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

include $(top_srcdir)/make_rules

EXTRA_DIST = sdf2-to-adt.sh.src \
	     sdf2-to-java.sh.src \
	     sdf2-to-c.sh.src \
	     CHARLIST_StringImpl.java.template \
	     CHARLIST.h.template \
	     CHARLIST.c.template

pkgdata_DATA= CHARLIST_StringImpl.java.template \
	      CHARLIST.c.template \
	      CHARLIST.h.template


bin_SCRIPTS = sdf2-to-adt sdf2-to-java sdf2-to-c 

noinst_SCRIPTS = sdf2-to-adt.test sdf2-to-java.test sdf2-to-c.test
	      

% : %.sh.src Makefile
	sed 's@__APIGEN__@${APIGEN}@g;\
	     s@__ATERM__@${ATERM}@g;\
	     s@__PT_SUPPORT__@${PT_SUPPORT}@g;\
	     s@__SGLR__@${SGLR}@g;\
	     s@__ASF__@${ASF}@g;\
	     s@__PKGDATA__@${pkgdatadir}@g;\
	     s@__PREFIX__@${prefix}@g' < $< > $@ && chmod +x $@

%.test : %.sh.src Makefile
	sed 's@__APIGEN__@${APIGEN}@g;\
	     s@__ATERM__@${ATERM}@g;\
	     s@__PT_SUPPORT__@${PT_SUPPORT}@g;\
	     s@__SGLR__@${SGLR}@g;\
	     s@__ASF__@${ASF}@g;\
	     s@__PKGDATA__@${top_builddir}/utils@g;\
	     s@__PREFIX__@${top_builddir}/utils@g' < $< > $@ && chmod +x $@
