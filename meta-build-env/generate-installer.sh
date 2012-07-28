#! /bin/sh

# TODO for sun:
# do not use --in-place with sed
# do not use uname -mo, but uname -ps
# GENERAL
# if external_substs is empty, do cat instead of sed of the empty string.


collect_prefixes=1
prefixes=
externals=

# Note: this must be the same as in the generated
# template (below).
# -mo is not support on Sun (-ps comes closest)
platform() {
    uname -mo 2> /dev/null || uname -ps
}

# Base sed on Sun does not substitute properly in tars
# Use gsed instead. Is in the template too.
if [ `uname` = "SunOS" ]; then
    SED=gsed
else
    SED=sed
fi
    
Usage() {
    echo >&2 "Usage: $0 [--help] --prefixes <list of (package-)prefixes> [--externals <list of (package-) external dependencies>]"
    exit 1
}

while [ $# -gt 0 ]; do
  case $1 in
   --help)
     Usage 
   ;;
   -h)
     Usage 
   ;;
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
  Usage
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
    if [ -e ${archive} ]; then
	(cd ${prefix}; tar --append -f ${archive} *)
    else
	(cd ${prefix}; tar cf ${archive} *)
    fi
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
    replacement=`printf "%-${space}s#" "" | tr " " "/"`
    #sed --in-place  -e "s@${prefix}@${replacement}@g" ${archive}
    ${SED} -e "s@${prefix}@${replacement}@g" ${archive} > ${archive}.sed
    mv ${archive}.sed ${archive}
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
  padding=\`printf "%-\${space}s" "" | tr " " "/"\`
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

echo >&2 "Parsing commandline options"
JAVA_CHECK="yes"
CLIB_CHECK="yes"
PLATFORM_CHECK="yes"
OVERWRITE_CHECK="yes"
PREFIX=""

Usage() {
  echo >&2 "Usage: \$0 <options>"
  echo >&2 ""
  echo >&2 "If no commandline options are provided, this script will ask"
  echo >&2 "the user for information and confirmation. The commandline options"
  echo >&2 "may be used to skip these questions."
  echo >&2 ""
  echo >&2 "Options:"
  echo >&2 "  --no-java-check       Ignore Java version mismatches"
  echo >&2 "  --no-clib-check       Ignore C standard library version mismatches"
  echo >&2 "  --no-platform-check   Ignore OS & architecture mismatches"
  echo >&2 "  --no-overwrite-check  Ignore check for overwriting previous installations"
  echo >&2 "  --prefix <path>       Provide installation prefix path"
  exit 1
}

while [ \$# -gt 0 ]
do
  case "\$1"
  in
    -h)
      Usage 
    ;;
    --help)
      Usage
    ;;
    --no-java-check)
      JAVA_CHECK="no"
    ;;
    --no-clib-check)
      CLIB_CHECK="no" 
    ;;
    --no-platform-check)
      PLATFORM_CHECK="no" 
    ;;
    --no-overwrite-check)
      OVERWRITE_CHECK="no" 
    ;;
    --prefix)
      shift;
      PREFIX=\$1 
    ;;
    default)
      Usage
    ;;
  esac
  shift
done

echo >&2 "Checking installation conditions..."

if [ `uname` = "SunOS" ]; then
    SED=gsed
else
    SED=sed
fi

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
  redex=\`printf "%-\${space}s#" "" | tr " " "/"\`
  \${SED} -e "s@\${redex}@\${target_prefix}@g"
}

rebind_externals() {
  if [ "\${external_substs}a" != "a" ] ; then
    \${SED} -e "\${external_substs}"
  else
    cat
  fi
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

if [ "\${JAVA_CHECK}" = "yes" ]; then
  if [ "a`java_version`" != "a\`java_version\`" ]; then
    continue_dialog "java code was compiled with version `java_version`, but is \`java_version\` on this system. The resulting installation may be unstable."
  fi
fi

if [ "\${CLIB_CHECK}" = "yes" ]; then
  if [ "a`libc_version`" != "a\`libc_version\`" ]; then
    continue_dialog "C code was compiled with libc version `libc_version`, but is \`libc_version\` on this system. The resulting installation may be unstable."
  fi
fi

platform() {
    uname -mo 2> /dev/null || uname -ps
}

if [ "\${PLATFORM_CHECK}" = "yes" ]; then
  if [ "a`platform`" != "a\`platform\`" ]; then
    continue_dialog "this binary release was built on a `platform` system, but this system is a \`platform\`. The resulting installation may be unstable."
  fi
fi

echo >&2 "Installation conditions checked."

if [ "a\${PREFIX}" = "a" ]; then  
  default_target_prefix="\${HOME}/\`basename \$0 .bin.sh\`"
  printf "Where to install? [\${default_target_prefix}]:"
  read read_target_prefix
  if [ -z \${read_target_prefix} ]; then
    target_prefix=\${default_target_prefix}
  else
    target_prefix=\${read_target_prefix}
  fi
else
  target_prefix=\${PREFIX}
fi
 
target_prefix_length=\${#target_prefix}
if [ \${target_prefix_length} -gt ${minimum_length} ]; then
  abort_dialog "target prefix \${target_prefix} is longer than ${minimum_length}.\nThis means that some files cannot be relocated. Please choose a shorter one."
fi

`generate_dialog`

mkdir -p \${target_prefix}

if [ "\${OVERWRITE_CHECK}" = "yes" ]; then
  file_count=\`ls -1 \${target_prefix} | wc -l\`

  if [ \${file_count} -gt 0 ]; then
    continue_dialog "There are files in \${target_prefix}, really overwrite (yes,no) ? [no]"
  fi
fi


echo "Please wait while installing in \${target_prefix}"

expand | relocate | rebind_externals | unpack
echo "Successfully installed \$0 in \${target_prefix}."
exit 0
EOF

file_length=$((`wc -l < ${installer_script}` + 1))
${SED} -e "s@__LENGTH_OF_SCRIPT__@${file_length}@g" < ${installer_script}
gzip -c < ${archive} || echo "You need to redirect the output to a file"
