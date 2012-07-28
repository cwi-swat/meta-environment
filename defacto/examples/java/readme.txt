===================================
  DeFacto - Fact Extractor
  Java Control Flow Graph example
===================================

Contents:

./annos		annotations for Control Flow Graph extraction
./rscript	rscript specification to calculate CFG from extracted facts
./data		dir for input java files and output rstore files

We use the Java grammar of the ASF+SDF grammar library.


Steps:

1. weave annotations into grammar and dump parse table:
    $ defacto -w -a annos/JavaCFG.defacto -m languages/java/syntax/Java -o JavaCFG.tbl

2. extract facts from term file.java
    $ defacto -i data/file.java -t JavaCFG.tbl -o data/file.rstore

3. enrich and analyze facts with rscript:
    $ rscript -i rscript/JavaCFG.rscript -s data/file.rstore -o data/file.result.rstore

.rstore files can be loaded into the Facts tab of the Meta-Environment, to view or visualize the containing facts.




