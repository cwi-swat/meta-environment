#! /bin/sh

# TODO
# - check at compile time
#   - external deps
# - generate checks for:
#   - tools used
#   - well-formedness of target_prefix
#   - content of target prefix
# - generate substitutions for external deps.

# The prefixes to be merged into one tar
# and be distributed in binary form.

collect_prefixes=1
prefixes=
externals=

while [ $# -gt 0 ]; do
  case $1 in
   --prefixes)
     collect_prefixes=1
   ;;
   --externals)
     collect_prefixes=0
   ;;
   *)
     if [ $collect_prefixes = 1 ]; then
       prefixes="$1 ${prefixes}";
     else 
       externals="$1 ${externals}";
     fi
   esac
   shift
done

# Check for prefixes given on the commandline
if [ -z "${prefixes}" ]; then
    echo >&2 "Usage: $0 --prefixes <list of (package-)prefixes> [--externals <list of (package-) external dependencies>]"
    exit 1
fi

# Check that given prefixes exist and are well-formed.
errors=""
for prefix in ${prefixes} ; do 
    if [ `echo ${prefix} | cut -b 1` = "/" ] ; then
	if [ `echo ${prefix} | tr -d ' '` = ${prefix} ] ; then
	    if [ ! -d ${prefix} ] ; then
		echo >&2 "error: directory ${prefix} does not exist."
		errors=1
	    fi
	else
	    echo >&2 "error: prefix ${prefix} contains spaces."
	    errors=1
	fi
    else
	echo >&2 "error: prefix ${prefix} is not absolute."
	errors=1
    fi
done

# Check that given externals exist and are well-formed.
errors=""
for external in ${externals} ; do 
    if [ `echo ${external} | cut -b 1` = "/" ] ; then
	if [ `echo ${external} | tr -d ' '` = ${external} ] ; then
	    if [ ! -f ${external} ] ; then
		echo >&2 "error: file ${external} does not exist."
		errors=1
	    fi
	else
	    echo >&2 "error: file ${external} contains spaces."
	    errors=1
	fi
    else
	echo >&2 "error: file ${external} is not absolute."
	errors=1
    fi
done

# Bail out if there are any errors.
if [ ! -z "${errors}" ] ; then
    echo >&2 "can't continue due to errors."
    exit 1
fi

# Add the contents of all prefixes to a tar archive
archive=/tmp/sisyphus_bin_dister.$$.tar
rm -f ${archive}
for prefix in ${prefixes}; do
    (cd ${prefix};  tar uf ${archive} *)
done

# Find the smallest prefix
smallest=""
for prefix in ${prefixes} ; do
    if [ -z "${smallest}" ]; then
	smallest=${prefix}
    fi
    minimum_length=${#smallest}
    current_length=${#prefix}
    if [ ${current_length} -lt ${minimum_length} ]; then
	smallest=${prefix}
    fi
done
minimum_length=${#smallest}

# Substitute each prefix for as many slashes and hash terminator.
for prefix in ${prefixes} ; do  
    space=$((${#prefix} - 1))
    replacement=`printf "%0${space}s#" "" | tr " " "/"`
    sed --in-place  -e "s@${prefix}@${replacement}@g" ${archive}
done

# check existence of externals in tar
for external in ${externals}; do
  occurs=`strings ${archive} | grep -c ${external}`
  if [ ${occurs} = "0" ]; then
    echo >&2 "error: ${external} is not present anywhere in ${archive}"
    exit 1;
  fi
done

generate_dialog() {
for external in ${externals}; do
cat<<ENDCAT
binary=`basename ${external}`
default_location=\`which \${binary}\`
printf "Absolute path of \${binary} [\${default_location}]:"
read read_location
if [ -z \${read_location} ]; then
  location=\${default_location}
else 
  location=\${read_location}
fi
if [ ! \`echo \${location} | cut -b 1\` = "/" ] ; then
  echo >&2 "error: \${location} is not an absolute path"
  exit 1;
fi

if [ -x \${location} -a -f \${location} ]; then
  space=\$((${#external} - \${#location}))
  if [ \${space} -lt 0 ]; then
    echo >&2 "error: binary relocation demands that the target path be shorter than ${#external}, and \${location} is longer than that."
    exit 1
  fi
  padding=\`printf "%0\${space}s" "" | tr " " "/"\`
  external_substs="s@${external}@\${padding}\${location}@g;\${external_substs}"
else
  echo >&2 "error: \${location} is not an executable." 
  exit 1 
fi


ENDCAT
done
}

cat <<EOF
#! /bin/sh
set -e

echo >&2 "Checking preconditions..."

if [ "a`uname -mo`" != "a\`uname -mo\`" ]; then
  echo "warning: this binary release was built on a `uname -mo` system."
  echo "warning: the current system is a \`uname -mo\` system."
  printf "Do you want to continue (yes,no)? [no]"
  read answer
  if [ "a\${answer}" != "ayes" ]; then
    echo >&2 "Aborting installation"
    exit 1;
  fi
fi

checkfor() {
  which \$1 || (echo "error: \$1 not found, aborting installation"; exit 1)
}

checkfor tar
checkfor uudecode
checkfor gunzip
checkfor sed
checkfor mkdir

echo >&2 "Preconditions check was successfull"

default_target_prefix="\${HOME}/\`basename \$0 .bin.sh\`"
printf "Where to install? [\${default_target_prefix}]:"
read read_target_prefix
if [ -z \${read_target_prefix} ]; then
  target_prefix=\${default_target_prefix}
else
  target_prefix=\${read_target_prefix}
fi
 
target_prefix_length=\${#target_prefix}
if [ \${target_prefix_length} -gt ${minimum_length} ]; then
  echo >&2 "error: target prefix \${target_prefix} is longer than ${minimum_length}."
  echo >&2 "This means that some files cannot be relocated. Please choose a shorter one."
  exit 1
fi

`generate_dialog`

mkdir -p \${target_prefix}

file_count=\`ls -1 \${target_prefix} | wc -l\`

if [ \${file_count} -gt 0 ]; then
  printf "There are files in \${target_prefix}, really overwrite (yes,no) ? [no]"
  read answer
  if [ "a\${answer}" != "ayes" ]; then
    echo >&2 "Aborting installation"
    exit 1;
  fi
fi

relocate() {
  space=\$((\${#target_prefix} - 1))
  redex=\`printf "%0\${space}s#" "" | tr " " "/"\`
  sed -e "s@\${redex}@\${target_prefix}@g"
}

rebind_externals() {
  sed -e "\${external_substs}"
}

unpack() {
  (cd \${target_prefix}; tar xvf -)
}

expand() {
  cat | uudecode | gunzip -c
}

echo "Please wait while installing in \${target_prefix}"

(expand | relocate | rebind_externals | unpack) <<THE_QUICK_BROWN_FOX_JUMPS_OVER_THE_LAZY_DOG
EOF
cat ${archive} | gzip | uuencode -m - 
cat<<EOF
THE_QUICK_BROWN_FOX_JUMPS_OVER_THE_LAZY_DOG
echo "Successfully installed \$0 in \${target_prefix}."
EOF
