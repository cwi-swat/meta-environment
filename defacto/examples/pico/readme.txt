===================================
  DeFacto - Fact Extractor
  Pico Control Flow Graph example
===================================

Contents:

./annos		annotations for Control Flow Graph extraction
./rscript	rscript specification to calculate CFG from extracted facts
./data		some example Pico programs

We use the Pico grammar of the ASF+SDF grammar library.


Steps:

1. weave annotations into grammar and dump parse table:
    $ defacto -w -a annos/PicoCFG.defacto -m languages/pico/syntax/Pico -o PicoCFG.tbl

2. extract facts from term file (for instance data/mediumpico.trm):
    $ defacto -i data/mediumpico.trm -t PicoCFG.tbl -o data/mediumpico.rstore

3. enrich and analyze facts with rscript:
    $ rscript -i rscript/PicoCFG.rscript -s data/mediumpico.rstore -o data/mediumpico.result.rstore

.rstore files can be loaded into the Facts tab of the Meta-Environment, to view or visualize the containing facts.




