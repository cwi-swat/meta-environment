#!/bin/sh
CLASSPATH=/ufs/olivierp/Research/glt/tide/tide.jar:$CLASSPATH
export CLASSPATH
toolbus $@ -TB_PORT 9500 /ufs/olivierp/Research/glt/tide/toolbus/tide.tb
echo "TOOLBUS ENDED EXECUTION"
