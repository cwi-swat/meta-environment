#! /bin/sh
DIR=`pwd`

cd /tmp

/ufs/sen1/software/installed/java-source-analysis-0.1/linux/i386/bin/extract-java -o /tmp/java.rstore.pt -s $1

/ufs/sen1/software/installed/rstore-to-aterm-0.3/linux/i686/bin/split-rstore -i /tmp/java.rstore.pt

/ufs/sen1/software/installed/rstore-to-aterm-0.3/linux/i686/bin/rstore-to-aterm -i /tmp/IMPORT.pt | /ufs/sen1/software/installed/asfsdf-meta-1.5.3/linux/i386/bin/unparsePT  |  sed 's@, (@, tuple(@g' | sed 's@\[ (@\[tuple(@g' > /tmp/IMPORT.trm
