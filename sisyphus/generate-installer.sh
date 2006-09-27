#set -x

# The prefixes to be merged into one tar
# and be distributed in binary form.
prefixes=$1

archive=/tmp/sisyphus_bin_dister.$$.tar
rm -f ${archive}

for prefix in ${prefixes}
  do
  pushd .
  cd ${prefix}
  tar uf ${archive} *
  popd
done

cat <<EOF
set -x
target_prefix=\$1

if [ -z \$target_prefix ] ; then
  echo "Usage: <installer> <prefix>"
  exit 1
fi

mkdir -p \$target_prefix

tmp_archive=/tmp/binary-sisyphus-installer.\$\$.tar

(cat | uudecode | gunzip -c) > \${tmp_archive}<<THE_QUICK_BROWN_FOX_JUMPS_OVER_THE_LAZY_DOG
EOF

cat ${archive} | gzip | uuencode -m - 

cat<<EOF
THE_QUICK_BROWN_FOX_JUMPS_OVER_THE_LAZY_DOG
for prefix in ${prefixes} 
  do
  prefix_length=\`echo -n "\${prefix}" | wc -c\`
  replacement=\`printf "%-\${prefix_length}s" \${target_prefix} | sed -e "s@ @/@g"\`
  replacement_length =\`echo -n "\${replacement}" | wc -c\`
  if [ \${replacement_length} -gt \${prefix_length} ] ; then
     echo "Installation failed; you may try to use a prefix shorter then \${prefix_length}."
     exit 1
  fi
  sed -e "s@\${prefix}@\${replacement}@g" --in-place \${tmp_archive}
done

cd \$target_prefix
tar xvf \$tmp_archive
echo "Successfully installed \$0 in \${target_prefix}."
EOF







