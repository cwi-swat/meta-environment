#! /bin/sh

set -x

# {{{  variables

INCLUDES=""
DEFINES=""
SCRATCH=/export/scratch1/jong/meta
STARTUP_SCRIPT=$SCRATCH/build/meta-kernel/src/toolbus/meta-kernel.tb
SHARE=$SCRATCH/install/share

# }}}

# {{{  add_include

add_include() {
  INCLUDES="$INCLUDES -I$SHARE/$1"
}

# }}}
# {{{  add_define

add_define() {
  DEFINES="$DEFINES -D$1"
}

# }}}

add_include toolbus
add_include graph-support
add_include sglr
add_include meta
add_include pt-support

add_define EDITOR=gvim

toolbus $DEFINES $INCLUDES $STARTUP_SCRIPT
