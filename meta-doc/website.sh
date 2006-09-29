#! /bin/sh

set -e

CATEGORIES="getting-started howto demos understanding courses project"
WEB="./doc/html"

mkdir -p ${WEB} || true


getTitle() {
  DOCBOOK=$1
  TITLE=`grep "<title>" $DOCBOOK | head -1 | cut -d '>' -f 2 | cut -d '<' -f 1`
  echo ${TITLE}
}

INDEX="${WEB}/index.html"
echo "<html><head><title>" > ${INDEX}
echo "  Meta-Environment Online Documentation" >> ${INDEX}
echo "</title></head><body>" >> ${INDEX}

for i in ${CATEGORIES}; do
  echo "<h1>`cat $i/TITLE`</h1><ul>" >> ${INDEX}
  BOOKS=`ls $i`
  mkdir -p ${WEB}/$i || true
  for b in ${BOOKS}; do
    if [ -d $i/$b ]; then
      if [ -f $i/$b/$b.xml ]; then
	(docbook2html --output ${WEB}/$i/$b --nochunks $i/$b/$b.xml)	
	title=`getTitle $i/$b/$b.xml`
	echo "<li><a href=\"./$i/$b/$b.html\">${title} (html)</a></li>" >> ${INDEX}
      elif [ -f $i/$b/$b.pdf ]; then
	  mkdir -p ${WEB}/$i/$b
	  cp $i/$b/$b.pdf ${WEB}/$i/$b/$b.pdf
	  title=`cat $i/$b/TITLE`
	  echo "<li><a href=\"./$i/$b/$b.pdf\">${title} (pdf)</a></li>" >> ${INDEX}
      elif [ -f $i/$b/$b.url ]; then
	  title=`cat $i/$b/TITLE`
	  url=`cat $i/$b/$b.url`
	  echo "<li><a href=\"${url}\">${title}</a></li>" >> ${INDEX}
      fi
    fi
  done
  echo "</ul>" >> ${INDEX}
done

echo "</body></html>" >> ${INDEX}
