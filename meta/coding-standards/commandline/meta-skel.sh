#! /bin/sh
#
#    Meta-Environment - An environment for language prototyping.
#    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#

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
