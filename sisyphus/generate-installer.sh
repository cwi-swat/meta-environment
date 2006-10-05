#! /bin/sh

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
    echo >&2 "warning: ${external} is not present anywhere in ${archive}"
  fi
done

java_version() {
  echo "`java -version 2>&1 | head -n 1 | cut -d '"' -f 2 | cut -d '.' -f 1`.`java -version 2>&1 | head -n 1 | cut -d '"' -f 2 | cut -d '.' -f 2`"
}

libc_version() {
  ldd `which cat` | grep libc.so | cut -d '=' -f 1 | cut -d '.' -f 3
}

generate_dialog() {
for external in ${externals}; do
cat<<ENDCAT
binary=`basename ${external}`
default_location=\`which \${binary} || true\`
printf "Absolute path of \${binary} [\${default_location}]:"
read read_location
if [ -z \${read_location} ]; then
  location=\${default_location}
else 
  location=\${read_location}
fi

if [ -z \${location} ]; then
  abort_dialog "You need \${binary} installed."
fi

if [ ! -f \${location} ]; then
  abort_dialog "You need \${binary} installed."
fi

if [ ! \`echo \${location} | cut -b 1\` = "/" ] ; then
  abort_dialog "\${location} is not an absolute path"
fi

if [ -x \${location} -a -f \${location} ]; then
  space=\$((${#external} - \${#location}))
  if [ \${space} -lt 0 ]; then
    abort_dialog "binary relocation demands that the target path be shorter than ${#external}, and \${location} is longer than that."
  fi
  padding=\`printf "%0\${space}s" "" | tr " " "/"\`
  external_substs="s@${external}@\${padding}\${location}@g;\${external_substs}"
else
  abort_dialog "\${location} is not an executable." 
  exit 1 
fi


ENDCAT
done
}

installer_script=/tmp/installer-script.$$
checksum=`sum ${archive}`

cat > ${installer_script}<<EOF
#! /bin/sh
set -e

echo >&2 "Checking installation conditions..."


java_version() {
  echo "\`java -version 2>&1 | head -n 1 | cut -d '"' -f 2 | cut -d '.' -f 1\`.\`java -version 2>&1 | head -n 1 | cut -d '"' -f 2 | cut -d '.' -f 2\`"
}

libc_version() {
  ldd \`which cat\` | grep libc.so | cut -d '=' -f 1 | cut -d '.' -f 3
}

continue_dialog() {
  echo "warning: \$1"
  printf "Do you still want to continue the installation (yes,no)? [no]"
  read answer
  if [ "a\${answer}" != "ayes" ]; then
    echo >&2 "Aborting installation"
    exit 1;
  fi
}

abort_dialog() {
  echo "error: \$1"
  echo "Aborting installation!"
  exit 1;
}

checkfor() {
  which \$1 || (abort_dialog "\$1 not found.")
}

checksum() {
  checksum=\`tail -n +__LENGTH_OF_SCRIPT__ \$0 | gunzip -c | sum\`
  if [ "a\${checksum}" != "a${checksum}" ]; then
    abort_dialog "The installer file appears to be corrupted, according to the checksum."
  fi
}

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
  tail -n +__LENGTH_OF_SCRIPT__ \$0 | gunzip -c
}

checksum

checkfor tar
checkfor sum
checkfor gunzip
checkfor sed
checkfor mkdir
checkfor java
checkfor uname
checkfor grep
checkfor ldd
checkfor cut

if [ "a`java_version`" != "a\`java_version\`" ]; then
  continue_dialog "java code was compiled with version `java_version`, but is \`java_version\` on this system. The resulting installation may be unstable."
fi

if [ "a`libc_version`" != "a\`libc_version\`" ]; then
  continue_dialog "C code was compiled with libc version `libc_version`, but is \`libc_version\` on this system. The resulting installation may be unstable."
fi

if [ "a`uname -mo`" != "a\`uname -mo\`" ]; then
  continue_dialog "this binary release was built on a `uname -mo` system, but this system is a \`uname -mo\`. The resulting installation may be unstable."
fi

echo >&2 "Installation conditions checked."

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
  abort_dialog "target prefix \${target_prefix} is longer than ${minimum_length}.\nThis means that some files cannot be relocated. Please choose a shorter one."
fi

`generate_dialog`

mkdir -p \${target_prefix}

file_count=\`ls -1 \${target_prefix} | wc -l\`

if [ \${file_count} -gt 0 ]; then
  continue_dialog "There are files in \${target_prefix}, really overwrite (yes,no) ? [no]"
fi


echo "Please wait while installing in \${target_prefix}"

expand | relocate | rebind_externals | unpack
echo "Successfully installed \$0 in \${target_prefix}."
exit 0
EOF

file_length=$((`wc -l < ${installer_script}` + 1))
sed -e "s@__LENGTH_OF_SCRIPT__@${file_length}@g" < ${installer_script}
gzip -c < ${archive} || echo "You need to redirect the output to a file"
