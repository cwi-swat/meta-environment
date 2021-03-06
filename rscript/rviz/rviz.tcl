

# TO DO:
# - take care of items that are defined outside the application
#   (annotateItem)
# - identical file names in different directories


set options(basex) 30             ;# topleft x position on file canvas
set options(basey) 20             ;# topleft y position on file canvas
set options(maxy)  1000            ;# bottom y position on file canvas

set options(width) 40             ;# width of each rectangle
set options(deltawidth) 3         ;# horizontal distance between rectangles
set options(deltaheight) 8        ;# vertical distance between rectangles
set options(captionlength) 6      ;# number of characters in caption above rectangle

set options(textheight) 18        ;# vertical size of text editor

set options(treeMapHeight) 1000    ;# sizes of treeMap window
set options(treeMapWidth)  1000
set options(treeMapBorder)  3

array set annotations {}          ;# array of line annotations indexed by filename

set itemtypes {}                  ;# list of itemtypes, e.g. Class, ClassUse, Interface,...

set allFiles {}                   ;# list of all files extracted from items
set allDirs {}                    ;# list of all directories extracted from items
array set fileLength  {}          ;# file length, indexed by filename

set maxLength 0                   ;# largest length

array set dirInfo {}              ;# subdirectory information consisting of triples
                                  ;# {subdir length list-of-subdirs}
                                  ;# filename extensions to be ignored
set ignoredExtensions {.o .a .jar .class .cache .ps .pdf .fig .bib .ltx .tex .cls .baf}   
                                  ;# filenames to be ignored
set ignoredFiles {CVS autom4te.cache aclocal.m4 libtool article Makefile Makefile.in Makefile.am configure ltmain.sh}

# ----- item and their access functions for items

array set items {}                ;# an array of items indexed by name
                                  ;# each entry consists of a list of "item"s

proc item-type { item }     { return [lindex $item 0] }

proc item-filename {item }  { return [lindex $item 1] }

proc item-beginline {item}  { return [lindex $item 2] }

proc item-begincol {item}   { return [lindex $item 3] }

proc item-endline {item}    { return [lindex $item 4] }

proc item-endcol {item}     { return [lindex $item 5] }

# ---- has-itemtype: does a given itemtype occur in list of alternatives for an item?

proc has-itemtype {itemtype alts} {
    foreach a $alts {
	if { [item-type $a] == $itemtype } {
	    return 1
	}
    }
    return 0
}

# ---- access functions for tuples in relations

array set relations {}             ;# and array of relations indexed  by name
                                   ;# each relation consists of a list of "tuple"s

proc tuple-typea {tuple}    { return [lindex $tuple 0] }

proc tuple-a {tuple}        { return [lindex $tuple 1] }

proc tuple-typeb {tuple}    { return [lindex $tuple 2] }

proc tuple-b {tuple}        { return [lindex $tuple 3] }

# ---- in-carrier: occurs a given itemname of given itemtype in the carrier of a relation?

proc in-carrier {relation itemtype itemname} {
    global relations

    foreach tuple $relations($relation) {
	set typea [tuple-typea $tuple]
	set a [tuple-a $tuple]

	if { $typea == $itemtype && $a == $itemname } {
	    return 1
	}
	set typeb [tuple-typeb $tuple]
	set b [tuple-b $tuple]
	if { $typeb == $itemtype && $b == $itemname } {
	    return 1
	}
    }
    return 0
}

# ---- The panes of the user interface:
# ---- relations: shows all available relations
# ---- itemtypes: shows all available itemtypes
# ---- items:     shows all items of selected itemtype
# ----            (items that do not occur in selected relation are grey)
# ---- The array "panes" holds three variables that maintain the index
# ---- of the entry last selected in each pane.

set panes(relations-Index) 0
set panes(itemtypes-Index) 0
set panes(items-Index)     0

proc mkFileViewer {} {
    global options allFiles fileLength maxLength relations items itemtypes

    set w .visualizer
    toplevel $w
    set nFiles [llength $allFiles]
    set wd [expr $options(basex) + $nFiles / 2 * [expr $options(width) + $options(deltawidth)]] 
    set ht [expr $maxLength + 2 * $options(basey)]

    frame $w.control
    pack $w.control -side left

    foreach pane {relations itemtypes items} {
	frame $w.control.$pane
	label $w.control.$pane.label -text $pane
	pack  $w.control.$pane.label -side top
	listbox $w.control.$pane.list -relief raised -borderwidth 2 -selectmode single \
	    -yscrollcommand "$w.control.$pane.scroll set" -selectforeground blue
	pack  $w.control.$pane.list -side left -fill y
	scrollbar $w.control.$pane.scroll -command "$w.control.$pane.list yview"
	pack  $w.control.$pane.scroll -side right -fill y
	pack $w.control.$pane -side top -fill y

	bind  $w.control.$pane.list <Button-1> "register $pane  $w.control.$pane.list %y"
    }

    $w.control.items.list configure -height 100

    bind $w.control.items.list <Button-3> "displayItem $w.control.$pane.list %y"

    foreach r [lsort [array names relations]] {
	$w.control.relations.list insert end $r
    }

    foreach c [lsort $itemtypes] {
	$w.control.itemtypes.list insert end $c
    }

    canvas $w.canvas -relief raised -width $wd -height $options(maxy)
    pack $w.canvas -side right -expand true -fill both

    set x $options(basex)

    set y $options(basey)

   foreach f $allFiles {
	if { [expr $y + $fileLength($f)] > $options(maxy) } {
	    set y $options(basey)
	    incr x [expr $options(width) + $options(deltawidth)]
	}
	incr y [drawFile $w $x $y  $f showFileInEditor]
	incr y $options(deltaheight)
   }
    wm geometry $w [format "%dx%d" [expr $x + 250 ] $options(maxy)]
}

proc register { pane list y} {
    global panes items

    clear-annotations

    $list itemconfigure $panes($pane-Index) -foreground black
    set cur [$list nearest $y]
    set panes($pane-Index) $cur
    $list itemconfigure $cur -foreground blue
    set panes(current-$pane) [$list get $cur]

    if { $pane != "items" } {
	.visualizer.control.items.list delete 0 end
	set panes(items-Index) 0
	set itemtype [.visualizer.control.itemtypes.list get $panes(itemtypes-Index)]
	set relation [.visualizer.control.relations.list get $panes(relations-Index)]
	foreach name [lsort -dictionary [lsort -dictionary [array names items]]] {
	    if { [has-itemtype $itemtype $items($name)] } {
		.visualizer.control.items.list insert end $name
		if { ! [in-carrier $relation $itemtype $name] } {
		    .visualizer.control.items.list itemconfigure end -foreground DarkGrey
		}
	    }
	}
    }

    if { $pane == "items" } {
	displayRelation
    }
}

proc clear-annotations {} {
    global annotations

    .visualizer.canvas itemconfigure annotated -fill grey77
    .visualizer.canvas dtag annotated annotated
    .visualizer.canvas itemconfigure annotated:rect -fill white
    .visualizer.canvas dtag annotated "annotated annotated:rect"

    foreach a [array names annotations] {
	set annotations($a) {}
    }
}

proc displayItem { list y} {
    global panes items

    clear-annotations

    $list itemconfigure $panes(items-Index) -foreground black
    set cur [$list nearest $y]
    set panes(items-Index) $cur
    $list itemconfigure $cur -foreground DeepPink
    set panes(current-items) [$list get $cur]

    annotateItem  $panes(current-itemtypes) $panes(current-items) DeepPink
}

# ----

proc displayRelation { } {
    global relations panes

    set rel $panes(current-relations)
    set itemname $panes(current-items)
    set itemtype $panes(current-itemtypes)

    .treeMap.canvas itemconfigure all -fill Green
    .treeMap.canvas delete treemap-caption

    annotateItem $itemtype $itemname blue

    foreach p $relations($rel) {
	set typea [tuple-typea $p]
	set a [tuple-a $p]
	set typeb [tuple-typeb $p]
	set b [tuple-b $p]

# puts stderr "displayRelation $typea $a $typeb $b"
	
	if { $a == $itemname } {
	    annotateItem  $typeb $b red
	} else {
	    if { $b == $itemname } {
		annotateItem $typea $a red
	    }
	}
    }	    
}
 
proc annotateItem {itemtype name color} {
    global annotations items  treeMapRect2ShortName treeMapName2Rect

puts stderr "annotateItem $itemtype $name $color"

# item may not occur in items, e.g. Cloneable

    .visualizer configure -cursor watch
    foreach item $items($name) {
# puts stderr "$item // [item-type $item]"

	if { [item-type $item] == $itemtype } {
	    set filename [item-filename $item]
	    set beginline [item-beginline $item]
	    set begincol [item-begincol $item]
	    set endline [item-endline $item]
	    set endcol [item-endcol $item]

# puts stderr "YEP! $filename $beginline -- $endline"

	    lappend annotations($filename) "$beginline $begincol $endline $endcol $color"

	    set i $beginline
	    while {$i <= $endline} {
		.visualizer.canvas itemconfigure $filename:$i -fill $color -tags "$filename:$i annotated"
		incr i
	    }
	    .visualizer.canvas itemconfigure $filename:rect -fill DarkGrey -tags "$filename:rect annotated:rect"
	    .treeMap.canvas itemconfigure $filename:rect -fill $color -tags "$filename:rect annotated:rect"
	    raiseTreeMapCaption .treeMap.canvas $treeMapName2Rect($filename)
	}
       
    }
    .visualizer configure -cursor arrow
}

# ---- drawFile: display of one file on the canvas

proc countPrefix {prefix} {
    set i 0
    set max [string length $prefix]
    set n 0
    while { $i < $max } {
	set c [string index $prefix $i]
	if { $c == " " } {
	   incr n
	}
	if {$c == "\t" } {
	    set fact [expr $n / 8  + 1]
	    set n [expr $fact * 8]
	}
	incr i
    }
    return $n
}

proc getIndent { line } {
    regexp {[ \t]*} $line prefix
    return [countPrefix $prefix]
}

proc drawFile {w basex basey filename action} {
    global options annotations 
    
#puts stderr "drawFile $w $basex $basey $filename $action"

    set c  $w.canvas
    set width $options(width)
    set file [open $filename r]
    set y $basey
    set sizes []
    set max 1
    if { $file < 0 } {
	puts stderr "Can't open file: $filename\n"
    } else {
	while {![eof $file]} {
	    gets $file line
	    set indent [getIndent $line]
	    set len [string length [string trimleft $line]]
	    lappend sizes "$y $indent $len"
	    if [expr $indent + $len > $max] {
		set max [expr $indent + $len]
	    }
	    incr y
	}
	close $file
	set nLines [expr $y - $basey]

	set scale [expr 1 + $max / $width]

	set basename [file tail $filename]
	set basenamepref [string range $basename 0 $options(captionlength)]
        set caption [$c create text [expr $basex] [expr $basey - 4]\
			 -text $basenamepref -anchor w -font "-Adobe-Helvetica-Medium-R-Normal-*-100-*"]

	foreach triple $sizes {
	    set y [lindex $triple 0]
	    set indent [expr [lindex $triple 1] / $scale]
	    set len [expr [lindex $triple 2] / $scale]
	    set ln [$c create line [expr $basex + $indent] $y [expr $basex + $indent + $len] $y\
			-tag $filename:[expr $y - $basey] -fill grey77]
	    $c bind $ln <Button-1> "$action $w $filename [expr $y - $basey]"
	}

	foreach anno $annotations($filename) {
	    set beginline [lindex $anno 0]
	    set begincol [lindex $anno 1]
	    set endline [lindex $anno 2]
	    set endcol [lindex $anno 3]
	    set color [lindex $anno 4]
	    $c itemconfigure $filename:$beginline -fill $color -tags anno
	}

	set rect [$c create rectangle [expr $basex - 1] $basey [expr $basex + $width] $y -fill white -tags $filename:rect -activefill LightYellow]
	$c lower $rect "$filename:1"
	$c bind $rect <Enter>  "raiseCaption $c $rect $basex [expr $basey - 10] $basename"
	$c bind $rect <Leave> "lowerCaption $c $rect"
    } 
    return $nLines
}

proc raiseCaption {c rect x y text} {
    global options

    $c delete caption
    set txt [$c create text [expr $x + $options(width) / 2] $y -text " $text " \
		 -anchor c -font  "-Adobe-Helvetica-Medium-R-Normal-*-120-*" -tags caption]
    set r [$c create rectangle [$c bbox $txt] -tags caption -fill LightYellow]
    $c lower $r $txt
}

proc lowerCaption {c rect} {
    $c delete caption 
}

# ---- showFileinEditor

proc showFileInEditor {w filename lino} {
    global options allFiles fileLength annotations

    set fileindex [lsearch $allFiles $filename]
    set w .showFileInEditor$fileindex
    toplevel $w
    wm title $w "$filename"
    set tht $options(textheight)
    text $w.text -relief raised -bd 2  -height $tht -setgrid 1 \
	-font "-Adobe-Helvetica-Medium-R-Normal-*-120-*"
    canvas $w.canvas -relief raised -width [expr $options(width)+5 ] \
	-height [expr $fileLength($filename) + 4]
    pack $w.canvas  -side left 
    pack $w.text -side right -expand yes -fill both
    set file [open $filename r]
    if { $file < 0 } {
	puts stderr "Can't open file: $filename\n"
    } else {
	while {![eof $file]} {
	    $w.text insert end "[gets $file]\n"
	}
	close $file
    }
    set textheight [$w.text cget -height]
    $w.text yview [expr $lino - $textheight / 2 - 2].0
    $w.text tag add "focus" [expr $lino - $tht/2].0 "[expr $lino + $tht/2].0"
    $w.text tag configure focus -background white

    set color grey77
    foreach anno $annotations($filename) {
	    set beginline [lindex $anno 0]
	    set begincol [lindex $anno 1]
	    set endline [lindex $anno 2]
	    set endcol [lindex $anno 3]
	    set color [lindex $anno 4]
	    $w.text tag add  annotation $beginline.$begincol $endline.$endcol
	}
    $w.text tag configure annotation -foreground $color

    drawFile $w 6 0 $filename showLine
    $w.canvas create rectangle [ruler $lino] -tags ruler -fill white
    $w.canvas lower ruler
}

proc ruler {lino} {
    global options

    set tht $options(textheight)
    set x1 1
    set x2 [expr $options(width) + 5]
    set y1 [expr $lino - $tht / 2]
    set y2 [expr $lino + $tht / 2]
    return "$x1 $y1 $x2 $y2"
}

proc showLine {w filename lino} {
    global options
    set tht $options(textheight)
    set textheight [$w.text cget -height]
    $w.text yview [expr $lino - $textheight / 2 - 2]
    $w.text tag delete "focus"
    $w.text tag add "focus" [expr $lino - $tht/2].0 "[expr $lino + $tht/2].0"
    $w.text tag configure focus -background white

    $w.canvas coords ruler [ruler $lino]
}

# ---- getFileInfo: read global file data by scanning all files


proc mk-dir {name size subs files} {
    return [ list $name $size $subs $files ]
}
 
proc dir-name { d }  { return [lindex "$d" 0] }
 
proc dir-size { d }  { return [lindex $d 1] }

proc dir-subs { d }  { return [lindex $d 2] }

proc dir-files { d } { return [lindex $d 3] }

proc dir-elems { d } { return [concat [lindex $d 2] [lindex $d 3]] }

proc ignored { name } {
    global ignoredExtensions ignoredFiles

    if { [lsearch -exact $ignoredExtensions [file extension $name]] != -1 } {
	return 1
    }
    if { [lsearch -exact $ignoredFiles [file tail $name]] != -1} {
	return 1
    }
#    if { [file executable $name] } {
#	return 1
#    }
    return 0
}

proc scanFile { name } {
    global maxLength fileLength

    set file [open $name r]
    if { $file < 0 } {
	puts stderr "Can't open file: $name\n"
    } else {
	set nLines 0
	while {![eof $file]} {
	    gets $file
	    incr nLines
	}
	close $file
    }
    set fileLength($name) $nLines
    if { $nLines > $maxLength } {
	set maxLength $nLines
    }
}

proc scanDir { dir } {
    global allFiles

#puts stderr "scanDir $dir"

    foreach f [glob $dir/*] {
	if { ! [ignored $f] } {
	    if { [file isdirectory $f] } {
		scanDir $f
	    } else {
#		puts stderr $f
		if { [lsearch -exact $allFiles $f] == -1 } {
		    lappend allFiles $f
		}
	    }
	}
    }
}

proc getFileInfo { } {
    global allFiles annotations

#    scanDir $dir
    set maxLength 0
    foreach f $allFiles {
#	puts stderr $f
	set annotations($f) {}
	scanFile $f
    }
}

proc getDirInfo { } {
    global allFiles allDirs root fileLength dirInfo

    set allDirs {}
    foreach f $allFiles {
	set  d [file dirname $f]
	if { [lsearch -exact $allDirs $d] == -1 } {
	    lappend allDirs $d
	}	
    }

    # Add the root directory to list of directories
    # Warning: this assumes that there is ONE common directory

    set allDirs [lsort -increasing -dictionary $allDirs]
    lappend allDirs [file dirname [lindex $allDirs 0]]

    # Visit larger directory names first, so that we can do a
    # bottom-up length propagation

    set allDirs [lsort -decreasing -dictionary $allDirs]

puts stderr "allDirs = $allDirs"

    foreach d $allDirs {

puts stderr "--$d--"
	set subs {}
	set files {}
	set length 0
	foreach sd $allDirs {
	    if { $d == [file dirname $sd] } {
puts stderr "----$sd----"
		lappend subs $sd
		incr length [dir-size $dirInfo($sd)]
	    } 
	}

	foreach f $allFiles {
	    if { $d == [file dirname $f] } {
		incr length  $fileLength($f)
		lappend files $f
	    }
	}
	set dirInfo($d) [mk-dir $d $length $subs $files]
    }

    foreach dname [array names dirInfo] {
	puts stderr "$dname [dir-size $dirInfo($dname)]"
	foreach sub [dir-subs $dirInfo($dname)] {
	    puts stderr "\t$sub"
	}
    }
}

proc get-root {} {
    global allDirs
    set tmp [lindex [lsort -increasing -dictionary $allDirs] 0]
    puts stderr "get-root: tmp = $tmp"
    return $tmp
}

# ---- getRelations: read the visualization data

proc item {itemtype name file beginline begincol endline endcol} {
    global items itemtypes allFiles

    if { [lsearch -exact $itemtypes $itemtype] == -1 } {
	lappend itemtypes $itemtype
    }

    if { [lsearch -exact $allFiles $file] == -1 } {
	lappend allFiles $file
    }

    set name [file tail $name]
    lappend items($name)  "$itemtype $file $beginline $begincol $endline $endcol"

}

proc rel {name typea a typeb b} {
    global relations
    lappend relations($name) "$typea $a $typeb $b"
}

proc getRelations {filename} {
    global allFiles

    set file [open $filename r]
    if { $file < 0 } {
	puts stderr "Can't open file: $filename\n"
    } else {
	while {[gets $file cmd] != -1} {
	    if {[catch $cmd result] != 0} {
		puts "error: $result"
	    } 
	}
	close $file
    }

    set allFiles [lsort -dictionary $allFiles]
}

# ---- Drawing of TreeMaps

proc raiseTreeMapCaption {c rect} {
    global treeMapRect2ShortName

    set coords [$c coords $rect]
    set x1 [lindex $coords 0]
    set y1 [lindex $coords 1]
    set x2 [lindex $coords 2]
    set y2 [lindex $coords 3]
    set dx [expr $x2 - $x1]
    set dy [expr $y2 - $y1]
    set x [expr $x1 + $dx / 2] 
    set y [expr $y1 + $dy / 2]

    set text $treeMapRect2ShortName($rect)

#    $c delete treemap-caption
    set txt [$c create text $x $y -text " $text " \
		 -anchor c -font  "-Adobe-Helvetica-Medium-R-Normal-*-120-*" -tags treemap-caption]
    set r [$c create rectangle [$c bbox $txt] -tags treemap-caption -fill LightYellow]
    $c lower $r $txt
}

proc lowerTreeMapCaption {c rect} {
    puts stderr "lower"
    $c delete treemap-caption 
}

proc selectTreeMapFile {c rect name} {
    puts stderr "select"
}

proc drawRect {c name x1 y1 x2 y2 color} {
    global treeMapRect2ShortName treeMapName2Rect

    set rect [$c create rectangle $x1 $y1 $x2 $y2 -activefill red -fill $color -tags $name:rect]
    set treeMapRect2ShortName($rect)  [file tail $name]
    set treeMapName2Rect($name) $rect
    $c bind $rect <1>  "raiseTreeMapCaption $c $rect"
    $c bind $rect <3>  "lowerTreeMapCaption $c $rect"
}

proc treeMap {c path x1 y1 x2 y2 direction} {
    global options dirInfo fileLength

puts stderr "treeMap $path $direction"

    set isdir [file isdirectory $path]

    if { $isdir } { set color blue } else { set color green }

    drawRect $c $path $x1 $y1 $x2 $y2 $color

    if { ! $isdir } {
	return
    }

    set dir $dirInfo($path)
    set elems [dir-elems $dir]

    set total 0
    foreach elm $elems {
	if { [file isdirectory $elm] } {
	    set d $dirInfo($elm)
	    incr total [dir-size $d]
	} else {
	    incr total $fileLength($elm)
	}
    }

    set n [llength $elems]
    set border $options(treeMapBorder)

    set x1 [expr $x1 + $border]
    set y1 [expr $y1 + $border]
    set x2 [expr $x2 - $border]
    set y2 [expr $y2 - $border]

    set h [expr $y2 - $y1]
    set w [expr $x2 - $x1]

    set direction [expr $w < $h]

    set x $x1
    set y $y1

    set available [expr $direction ? $y2 - $y1 : $x2 - $x1]

    foreach elm $elems {
	if { [file isdirectory $elm] } {
	    set d $dirInfo($elm)
	    set name [dir-name $elm]    
	    set length [dir-size $d]
	} else {
	    set name $elm
	    set length $fileLength($elm)
	}

	set n [expr $n - 1]
	set delta  [expr $length * $available / $total]

	if { $direction == 0 } {
	    treeMap $c $name $x $y1 [expr $n == 0 ? $x2 : $x + $delta] $y2 1
	    incr x $delta
	} else {
	    treeMap $c $name  $x1 $y $x2 [expr $n == 0 ? $y2 : $y + $delta] 0	
	    incr y $delta
	}
    }
}

proc mkTreeMapViewer {dir} {
    global options

    set w .treeMap
    toplevel $w
    canvas $w.canvas -relief raised -height $options(treeMapHeight) -width $options(treeMapWidth)
    pack $w.canvas -side right -expand true -fill both
    treeMap $w.canvas $dir 0 0 $options(treeMapWidth) $options(treeMapHeight) 0
}

# ---- mkVisualizer: toplevel construction of the whole visualizer

proc mkVisualizer { vizData } {

    getRelations $vizData
    getFileInfo
    getDirInfo
    mkFileViewer
    mkTreeMapViewer [get-root]
    wm withdraw .
}

mkVisualizer jhotdraw.rviz 