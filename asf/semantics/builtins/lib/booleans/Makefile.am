# $Id$


EXTRA_DIST = Booleans.def

# Developers only:
api: Booleans.def
	sdf2-to-c -i $< -P B_ -o Booleans

api-clean:
	rm -f Booleans.[ch] Booleans_dict.* Booleans.adt Booleans_bottom.c

Booleans.def:
	@(echo "definition" ; \
          cat ${top_srcdir}/../asf-library/library/basic/Booleans.sdf) > \
	  $@

