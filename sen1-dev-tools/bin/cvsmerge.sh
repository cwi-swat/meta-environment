#! /bin/sh

#
# TODO: - check whether required tags are present on ALL cvs files
#

# set -x


LOGFILE=/var/tmp/cvsmerge.log.$$


usage() {
    cat << __END__
usage: cvsmerge  begin-branch  <branch-name>
       cvsmerge  import-from-trunk
       cvsmerge  end-branch  <branch-name>
__END__

    exit 1
}


log() {
    echo + $* >> $LOGFILE
}


info() {
    log cvsmerge: $*
    echo $*
}


assert_in_working_copy() {
    if [ ! -d CVS ]
    then
        info the current working directory is not a CVS working copy.
        exit 1
    fi
}


get_sticky_tag_cwd() {
    log get_sticky_tag_cwd
    (cvs status -v \
        | grep "Sticky Tag:" \
        | head -1 \
        | awk '{print $3}') \
	2>> $LOGFILE
}


assert_in_trunk_working_copy() {
    assert_in_working_copy
    branch_tag=`get_sticky_tag_cwd`
    
    if [ "x$branch_tag" != "x(none)" ]
    then
        info the current working directory is not a CVS TRUNK working copy
        exit 1
    fi
}


assert_in_branch_working_copy() {
    assert_in_working_copy
    branch_tag=`get_sticky_tag_cwd`

    if [ "x$branch_tag" = "x(none)" ]
    then
        info the current working directory is not a CVS BRANCH working copy
        exit 1
    fi
}


assert_argument_count() {
    count=$1
    shift
    
    if [ $# != $count ]
    then
        info wrong number of arguments
        exit 1
    fi
}


tag_name_count() {
    branch_tag=$1

    log tag_name_count
    (cvs status -v \
        | egrep -w '\((branch:|revision:)' \
        | grep $branch_tag \
        | wc -l) \
	2>> $LOGFILE
}


assert_valid_branch_creation() {
    branch_tag=$1
    progress_tag=$2

    if [ `tag_name_count $branch_tag` != 0 ]
    then
        info tag name $branch_tag is already in use in this subtree
        exit 1
    fi

    if [ `tag_name_count $progress_tag` != 0 ]
    then
        info tag name $progress_tag is already in use in this subtree
        exit 1
    fi
}


assert_valid_branch_use() {
    branch_tag=$1
    progress_tag=$2

    if [ `tag_name_count $branch_tag` = 0 ]
    then
        info tag name $branch_tag not found in this subtree
        exit 1
    fi

    if [ `tag_name_count $progress_tag` = 0 ]
    then
        info tag name $progress_tag not found in this subtree
        exit 1
    fi
}


assert_working_copy_up_to_date() {
    type_of_wc=$1
    
    log assert_working_copy_up_to_date
    (cvs status \
        | grep "Status:" \
        | grep -v -q "Up-to-date") \
	2>> $LOGFILE

    good=$?

    if [ $good = 0 ]
    then
        info working copy not up to date wrt the head of the $type_of_wc
        exit 1
    fi
}


#
# Initialize the branch
#
begin_branch() {
    log begin branch: $*
    
    assert_in_trunk_working_copy
    assert_argument_count 1 $*
    
    branch_tag=$1
    progress_tag="${branch_tag}_progress"

    assert_valid_branch_creation $branch_tag $progress_tag
    assert_working_copy_up_to_date trunk
    
    log cvs tag -b $branch_tag
    cvs tag -b $branch_tag >> $LOGFILE 2>&1 

    log cvs tag $progress_tag
    cvs tag $progress_tag  >> $LOGFILE 2>&1
    
    info Created branch $branch_tag and progress tag $progress_tag
}


#
# Merge changes from the trunk into the branch
#
import_from_trunk() {
    log import changes: $*
    
    assert_argument_count 0 $*
    assert_in_branch_working_copy    

    branch_tag=`get_sticky_tag_cwd`    
    progress_tag="${branch_tag}_progress"

    assert_valid_branch_use $branch_tag $progress_tag
    assert_working_copy_up_to_date branch    
        
    frozen_head_tag=fht_$$_`whoami`
    module_name=`cat CVS/Repository`

    info "About to import (merge) changes from the trunk into the working"
    info "copy of module $module_name (branch $branch_tag)".
    info
    echo -n "Are you sure? [y/N] "
    
    read answer
    echo

    if [ x$answer != xy ]
    then
        info Import of changes from trunk aborted.
        exit 1
    fi

    log cvs rtag -r HEAD $frozen_head_tag $module_name
    cvs rtag -r HEAD $frozen_head_tag $module_name >> $LOGFILE 2>&1

    log cvs update -j $progress_tag -j $frozen_head_tag
    (cvs update -j $progress_tag -j $frozen_head_tag 2>&1) \
        | tee --append $LOGFILE \
        | grep -v 'cvs update:'

    log cvs rtag -F -r $frozen_head_tag $progress_tag $module_name
    cvs rtag -F -r $frozen_head_tag $progress_tag $module_name >> $LOGFILE 2>&1

    log cvs rtag -d $frozen_head_tag $module_name
    cvs rtag -d $frozen_head_tag $module_name >> $LOGFILE 2>&1
    
    info "Merged changes from the trunk into the working copy of branch"
    info "$branch_tag from $module_name."
    info 
    info "Don't forget to check for conflicts and commit the merged changes." 
}


assert_progress_is_at_frozen_head() {
    progress_tag=$1
    frozen_head_tag=$2

    find . -type f -not -regex '.*CVS.*' | while read line
    do
        (status=`cvs -Q status $line \
            | grep "Status:" \
            | grep -q "Up-to-date"`) \
	    2>> $LOGFILE
        unknown=$?
        
        if [ $unknown = 1 ]
        then
            info skipping file $line
            continue
        fi
        
        progress_number=(`cvs status -v $line \
            | egrep -w '\((branch:|revision:)' \
            | grep $progress_tag \
            | tr -d '()' \
            | awk '{print $3}'`) \
	    2>> $LOGFILE

        frozen_head_number=(`cvs status -v $line \
            | egrep -w '\((branch:|revision:)' \
            | grep $frozen_head_tag \
            | tr -d '()' \
            | awk '{print $3}'`) \
	    2>> $LOGFILE
        
        if [ $progress_number != $frozen_head_number ]
        then
            info branch is not up-to-date wrt the head of the trunk
            info "File:             $line"
            info "Last merge:       $progress_number"
            info "Current revision: $frozen_head_number"
            info
            info You probably need to go to the branch working copy
            info and run \'cvsmerge import-from-trunk\' over there.

            exit 1
        fi
    done
    status=$?
    
    if [ $status != 0 ]
    then
        exit 1
    fi
}


#
# Merge changes from the branch into the trunk
#
end_branch() {
    log End Branch: $*

    assert_argument_count 1 $*
    assert_in_trunk_working_copy
    
    branch_tag=$1
    progress_tag="${branch_tag}_progress"

    assert_valid_branch_use $branch_tag $progress_tag
    assert_working_copy_up_to_date trunk
    
    module_name=`cat CVS/Repository`
    frozen_head_tag=fht_$$_`whoami`
    cvs rtag -r HEAD $frozen_head_tag $module_name >> $LOGFILE 2>&1
    
    assert_progress_is_at_frozen_head $progress_tag $frozen_head_tag
    
    info "About to merge the changes from branch $branch_tag into the working"
    info "copy of the trunk of module $module_name".
    info
    echo -n "Are you sure? [y/N] "
    
    read answer
    echo

    if [ x$answer != xy ]
    then
        info Import of changes from trunk aborted.
        exit 1
    fi

    # Perform the actual merge
    log cvs update -j $frozen_head_tag -j $branch_tag
    (cvs update -j $frozen_head_tag -j $branch_tag 2>&1) \
        | tee --append $LOGFILE \
        | grep -v 'cvs update:'

    # Remove temporary tag
    log cvs rtag -d $frozen_head_tag $module_name
    cvs rtag -d $frozen_head_tag $module_name >> $LOGFILE 2>&1
    
    info "Merged changes from branch $branch_tag with the working copy of"
    info "module $module_name".
    info 
    info "Don't forget to check for conflicts, commit the merged changes,"
    info "and when everything checks out to remove tag $progress_tag". 
}


if [ $# = 0 ]
then
    usage
fi

date >> $LOGFILE
log Executing: $0 $*

command=$1
shift

echo Logging output to: $LOGFILE
echo
echo Warning: This version has NO collision detection!
echo

case $command in
    begin | begin-branch)
        begin_branch $*
        ;;

    import | import-from-trunk)
        import_from_trunk $*
        ;;

    end | end-branch)
        end_branch $*
        ;;        

    *)
        usage
        ;;
esac
