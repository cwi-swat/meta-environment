===================================
  DeFacto - Fact Extractor
  Sudoku example
===================================

Contents:

./annos		fact annotations to extract sudoku puzzle information
./grammar	sudoku grammar
./rscript	rscript specification to calculate with and verify extracted facts of sudoku
./data		some example sudoku's



Steps:

1. weave annotations into grammar and dump parse table:
    $ defacto -w -a annos/sudoku.defacto -m grammar/sudoku -o sudoku.tbl

2. extract facts from term file (for instance data/s1.trm):
    $ defacto -i data/s1.trm -t sudoku.tbl -o data/s1.rstore

3. enrich and analyze facts with rscript:
    $ rscript -i rscript/sudoku.rscript -s data/s1.rstore -o data/s1.result.rstore

4. check sudoku puzzle constraints:
    $ rscript -i rscript/sudoku.rscript -s data/s1.rstore -t


.rstore files can be loaded into the Facts tab of the Meta-Environment, to view or visualize the containing facts.




