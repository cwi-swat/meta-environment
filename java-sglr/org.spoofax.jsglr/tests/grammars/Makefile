all : Booleans.tbl

%.tbl : %.def
	sdf2table -i $< -o $@ -t -m basic/$(basename $<)

%.def : basic/%.sdf
	pack-sdf -I . -i $< -o $@


clean:
	rm -f *.def *.tbl
