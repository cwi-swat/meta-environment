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
prefixes=$*

if [ -z "${prefixes}" ]; then
    echo >&2 "Usage: $0 <list of (package-)prefixes>"
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

# Substitute each prefix for as many slashes
for prefix in ${prefixes} ; do  
    space=$((${#prefix} - 1))
    replacement=`printf "%0${space}s#" "" | tr " " "/"`
    sed --in-place  -e "s@${prefix}@${replacement}@g" ${archive}
done
cat <<EOF
#! /bin/sh
set -e
target_prefix=\$1
if [ -z \$target_prefix ] ; then
  echo >&2 "Usage: \$0 <prefix>"
  exit 1
fi
target_prefix_length=\${#target_prefix}
if [ \${target_prefix_length} -gt ${minimum_length} ]; then
  echo >&2 "Error: target prefix \${target_prefix} is longer than ${minimum_length}."
  echo >&2 "This means that some files cannot be relocated. Please choose a shorter one."
  exit 1
fi
mkdir -p \$target_prefix

relocate() {
  space=\$((\${#target_prefix} - 1))
  redex=\`printf "%0\${space}s#" "" | tr " " "/"\`
  sed -e "s@\${redex}@\${target_prefix}@g"
}

unpack() {
  (cd \${target_prefix}; tar xvf -)
}

expand() {
  cat | uudecode | gunzip -c
}

(expand | relocate | unpack) <<THE_QUICK_BROWN_FOX_JUMPS_OVER_THE_LAZY_DOG
EOF
cat ${archive} | gzip | uuencode -m - 
cat<<EOF
THE_QUICK_BROWN_FOX_JUMPS_OVER_THE_LAZY_DOG
echo "Successfully installed \$0 in \${target_prefix}."
EOF







