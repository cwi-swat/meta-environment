#! /bin/sh

set -x

SCRATCH=/export/scratch1/jong/meta
SHARE=$SCRATCH/install/share

INCLUDES=""
INCLUDES="$INCLUDES -I$SHARE/toolbus"
INCLUDES="$INCLUDES -I$SHARE/graph-support"
INCLUDES="$INCLUDES -I$SHARE/sglr"
INCLUDES="$INCLUDES -I$SHARE/meta"
INCLUDES="$INCLUDES -I$SHARE/pt-support"

META_KERNEL=$SCRATCH/build/meta-kernel/src/toolbus/meta-kernel.tb

toolbus $INCLUDES $META_KERNEL
