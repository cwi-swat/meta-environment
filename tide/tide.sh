#!/bin/sh
CLASSPAH=/ufs/olivierp/Research:$CLASSPATH
export CLASSPATH
toolbus $@ -TB_PORT 9500 tide.tb
echo "TOOLBUS ENDED EXECUTION"
