#! /bin/sh

ACTION="register"

for arg in $*
do
   case $1 in
      -u ) ACTION="unregister"; shift ;;
      -r ) ACTION="register"; shift ;;
      * ) break ;;
   esac
done

registry=$1
tag=$2
values=$3

unregister ()
{
   if [ -f ${registry} ]; then
      cp ${registry} ${registry}.tmp
      grep -v "${tag}:" ${registry}.tmp > ${registry} || true
      rm -f ${registry}.tmp
   fi
}

register ()
{
   unregister
   if test "a${values}" != "a"; then
     for value in ${values} ; do
       echo "${tag}:${value}" >> ${registry}
     done
   fi   
}


if [ "${ACTION}" = "register" ] ; then
   register
else
   unregister
fi
