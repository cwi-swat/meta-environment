#! /bin/sh

# This is a sample shell script, conforming to Meta-Env argument
# conventions.

myname=`basename $0`
myversion="1.0"

# The argument vector: list of option letters, colons denote option
# arguments.  See Usage function, immediately below, for option
# explanation.
myarguments="bhi:o:tvV"

# Usage: displays helpful usage information
Usage() {
cat << E_O_USAGE >&2
Usage: $myname [options]
Options:
    -b              output terms in BAF format (default)
    -h              display help information (usage)
    -i filename     input from file (default stdin)
    -o filename     output to file (default stdout)
    -t              output terms in plaintext format
    -v              verbose mode
    -V              reveal program version (i.e. $myversion)
E_O_USAGE
}

Version() {
    echo "$myname v$myversion" >&2
}

# Default values
input="-"
output="-"
verbose=0
bafmode=1

# getopt handles command line...
args=`getopt $myarguments $* 2> /dev/null`
if test $? != 0
then
        Usage
        exit 2
fi
set -- $args

# Argument interpretation is rather tool-specific, tune as required...
while [ $#  -gt 0 ]
do
    case "$1"
    in
        -b)
            bafmode=1; shift;;
        -h)
            Usage; shift;;
        -i)
            input=$2; shift 2;;
        -o)
            output=$2; shift 2;;
        -t)
            bafmode=0; shift;;
        -v)
            verbose=1; shift;;
        -V)
            Version; shift;;
        --)
            shift; break;;
	# Add additional command line options here...
	*)
            Usage; shift ;;
    esac
done

#  . . .
