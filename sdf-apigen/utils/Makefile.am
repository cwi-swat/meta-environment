#
# vim:ts=8:sw=8:sts=0
#
# $Id$
#

include $(top_srcdir)/make_rules

EXTRA_DIST = sdf2-to-adt.sh.src \
	     sdf2-to-java.sh.src \
	     sdf2-to-c.sh.src \
	     CHARLIST.java.template \
	     CHARLIST_String.java.template \
	     CHARLIST.t.template \
	     CHARLIST.c.template

pkgdata_DATA= CHARLIST.java.template \
	      CHARLIST_String.java.template \
	      CHARLIST.t.template \
	      CHARLIST.c.template


bin_SCRIPTS		= sdf2-to-adt sdf2-to-java sdf2-to-c

% : %.sh.src Makefile
	sed 's@__APIGEN__@${APIGEN}@g;\
	     s@__ATERM__@${ATERM}@g;\
	     s@__PT_SUPPORT__@${PT_SUPPORT}@g;\
	     s@__SGLR__@${SGLR}@g;\
	     s@__ASF__@${ASF}@g;\
	     s@__PREFIX__@${prefix}@g' < $< > $@ && chmod +x $@
