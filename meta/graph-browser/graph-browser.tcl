# $Id$
# GraphBrowser: UI for ASF+SDF meta-environment
#               (and viewer for ASF+SDF import graphs)
#


#----------------------------------------------------------------------
# help texts
#----------------------------------------------------------------------

set toolname "Graph Browser"
set metaname "NewMeta"

set help_meta "$metaname

A New Standalone Meta-environment for ASF+SDF
Copyright (C) 1997  UvA, CWI

$metaname development team:
Mark van den Brand, Leon Moonen, Tobias Kuipers,
Pieter Olivier, Jeroen Scheerder

Programming Research Group, University of Amsterdam
Department of Software Technology, CWI"

set help_about "$toolname  -  ASF+SDF Import Graph Browser
Copyright (C) 1997  Leon Moonen <leon@wins.uva.nl>

$toolname provides a graphical view of an ASF+SDF import graph.
The layout of this graph is computed using the dot layout algorithm
developed by AT&T."

set help_mouse "               $toolname - Mouse Operations

Mouse Button:
  - Pops up a contextual menu on the canvas.
  - Selects modules in the Modules list.
Secondary Button (usually Middle or Rightmost, if it exists):
  - Repositions the canvas under the window.
  - Scrolls through the module list.
Tertiary Button (usually Rightmost, if it exists):
  - Pops up a contextual menu on canvas and Modules list.

The dot layout algorithm can be (re-)applied by clicking on
the ``button'' in the lower right corner of the canvas."

#----------------------------------------------------------------------
# packages
#----------------------------------------------------------------------
package require Tcldot

#----------------------------------------------------------------------
# constants
#----------------------------------------------------------------------

# switch to enable/disable printing of diagnostics to stderr
set DIAG 0

set MAXWINSIZE {1000 800}
set MINWINSIZE {100 80}

# width of scrollbars
set SBW 10

# style for "shadowed" modules (i.e. modules that aren't loaded
# but we know they are there)
set SHADOWSTYLE ellipse
set MODULESTYLE box

#----------------------------------------------------------------------
# global variables (bweghh!)
#----------------------------------------------------------------------
global saveFill fileName printCommand g c statuslist

# animation of loading of modules
set animate 0

# resizing after loading of modules
set autoresize 1

# toggle during opening of modules (to turn of animation)
set opening 0

# counter for window id's
set windowcnt 1

# message in the status window
set status "Idle"

# initialize statuslist
set statuslist {}

#----------------------------------------------------------------------
# TB interaction functions
#----------------------------------------------------------------------

# INGOING  (note some proc's are also used internally)

#---
# snd-do(new-graph(graph(nodes([M1,..,Mn]),edges([Mi,Mj],..,[Mm,Mn]))))
#-
# Adds the named modules (nodes) and their import relations
# (directed edges).
# Modules and edges are added only once.
# The proc update-graph is performed afterwards.
#---
proc new-graph { graph } {
    global g

    GBin "new-graph($graph)"

    foreach graphnode [$g listnodes] {
	$graphnode delete
    }

    # change ``graph(nodes('' in ``{''
    regsub {[ \t\n\]*graph[ \t\n\]*\([ \t\n\]*nodes[ \t\n\]*\([ \t\n\]*} \
	    $graph "{" tmp
    # change ``),edges('' in `` ''
    regsub {[ \t\n\]*\)[ \t\n\]*,[ \t\n\]*edges[ \t\n\]*\([ \t\n\]*} \
	    $tmp " " tmp2
    # change ``))'' in ``}''
    regsub {[ \t\n\]*\)[ \t\n\]*\)[ \t\n\]*$} $tmp2 "}" tmp

    eval "set graph $tmp"

    # now we have a list of two elements:
    # (1) a list of nodes
    # (2) a list of edges
    # each edge is in turn a list of two nodes
    # all nodes are `wrapped' in id("...") function appl's

    foreach node [lindex $graph 0] {
	$g addnode [StripId $node]
    }

    foreach edge [lindex $graph 1] {
	AddUniqueEdge $g [$g addnode [StripId [lindex $edge 0]]] \
	       [$g addnode [StripId [lindex $edge 1]]]
    }
    update-graph
}


#---
# snd-do(open-module(Mod))
#-
# Adds the named module.
# Modules are added only once.
# The proc update-graph is performed afterwards.
#---
proc open-module { mod } {
    global g MODULESTYLE
    GBin "open-module($mod)"
    $g addnode [StripId $mod] shape $MODULESTYLE
    update-graph
}

#---
# snd-do(open-empty-module(Mod))
#-
# Adds the named module, but it is being added as an oval
# instead of a box.
# Modules are added only once.
# The proc update-graph is performed afterwards.
#---
proc open-empty-module { mod } {
    global g MODULESTYLE
    GBin "open-empty-module($mod)"
    $g addnode [StripId $mod]
    update-graph
}

#---
# snd-do(delete-module(Mod))
#-
# "Deletes" the named module i.e. turns it into shadowstyle
# and deletes all edges that start in that module.
# The proc update-graph is performed afterwards.
#---
proc delete-module { mod } {
    global g SHADOWSTYLE
    GBin "delete-module($mod)"
    set node [$g findnode [StripId $mod]]
    $node setattributes shape $SHADOWSTYLE

    foreach edge [$node listoutedges] {
	$edge delete
    }
    update-graph
}


#---
# snd-do(imports(Mod, [Mod1, ..., Modn]))
#-
# Adds the named modules (nodes) and their import relations
# (directed edges) using a module and a list of modules it imports.
# Modules and edges are added only once.
# The proc update-graph is performed afterwards.
#---
proc imports { mod modlist } {
    global g SHADOWSTYLE
    GBin "imports($mod,$modlist)"
    set i [$g addnode [StripId $mod]]
    foreach j $modlist {
	AddUniqueEdge $g $i [$g addnode [StripId $j]]
    }
    update-graph
}


#---
# snd-do(add-imports([[Mod, Mod1], [Mod2, Mod3], ... , [Modn, Modm]]))
#-
# Adds the named modules (nodes) and their import relations (directed
# edges) using a list of pairs. In this list, the element [A,B]
# denotes A imports B
# Modules and edges are added only once.
#---
proc add-imports { implist } {
    global g SHADOWSTYLE
    GBin "add-imports($implist)"
    foreach rel $implist {
	AddUniqueEdge $g [$g addnode [StripId [lindex $rel 0]]]	\
		[$g addnode [StripId [lindex $rel 1]]]
    }
    update-graph
}


#---
# snd-do(finished-opening-modules(Mod))
#-
# notifies finishing of opening of modules (to turn on/off animation)
#---
proc finished-opening-modules { mod } {
    global opening

    set opening 0
    update-graph
}


#---
# snd-do(update-graph)
#-
# redraws the canvas based on the internal TclDot graph-structure
#---
proc update-graph {} {
    global g c opening animate autoresize

    if {$animate || !$opening} {
	$c delete all
	$g layout .b.h .a.v
	eval [$g render]
	set bbox [$c bbox all]
	if {$bbox == {}} { set bbox {0 0 0 0} }
	$c configure -scrollregion $bbox
	UpdateModuleList $g
    }
    if {$autoresize  && !$opening} {
        ViewAll
    }
}


# No longer an external function. Now used internally. Use ui-status notes
# instead. See msm-c.tb for more details.
# For backwards compatibility it can still be called.
#---
# snd-do(set-status(s))
#-
# sets the status message to s
#---
proc set-status { str } {
    global status
    set status [TCLstring $str]
}

#---
# snd-do(add-status(id,s))
#-
# sets status message to s, for process with id id. Only called from process
# Status-display. Should not be used directly.
#---
proc add-status { id str } {
    global statuslist

    set str [TCLstring $str]
    set pair {}
    lappend pair $id
    lappend pair $str
    set statuslist [linsert $statuslist 0 $pair]
    set-status $str
}

#---
# snd-do(end-status(id))
#-
# remove all status messages for process id from the status list. Only called
# from process Status-display. Should not be called directly.
#---
proc end-status { id } {
    global statuslist

    set listrm {}
    for {set i [expr [llength $statuslist]-1]} {$i >= 0} {incr i -1} {
	if {[lindex [lindex $statuslist $i] 0] == $id} {
	    lappend listrm $i
	}
    }
    set corr 0
    foreach i $listrm {
	set i [expr $i - $corr]
	set statuslist [lreplace $statuslist $i $i]
	incr corr
    }
    if {$statuslist == {}} {
	set-status "Idle"
    } else {
	set-status [lindex [lindex $statuslist 0] 1]
    }
}

#---
# snd-do(module-info(Mod, [["dir",...],...,[x,y]]))
#-
# Pops up an information window with info on module Mod. The info
# is read from a list of tuples, where both elements of a tuple
# are interpreted as strings.
#---
proc module-info { mod infolist } {
    global windowcnt SBW toolname
    GBin "module-info($mod,$infolist)"
    set mod [StripId $mod]
    set w ".info$windowcnt"
    set windowcnt [expr $windowcnt + 1]
    catch {destroy $w}
    toplevel $w
    wm title $w "$toolname Info on $mod"
    wm iconname $w "Info on $mod"

    frame $w.info -relief raised -bd 2
    pack $w.info -side top -fill x

    scrollbar $w.info.yscroll -width $SBW -command "$w.info.list yview"
    scrollbar $w.info.xscroll -width $SBW -orient horizontal \
        -command "$w.info.list xview"

    # note: choose monospaced font for listbox!!!
    listbox $w.info.list -width 40 -height 8 -setgrid 1 -selectmode none \
        -yscroll "$w.info.yscroll set" -xscroll "$w.info.xscroll set" \
        -font -adobe-courier-bold-r-normal--*-120-*-*-m-*-iso8859-1

    grid $w.info.list    -row 0 -column 0 -rowspan 1 -columnspan 1 -sticky news
    grid $w.info.yscroll -row 0 -column 1 -rowspan 1 -columnspan 1 -sticky news
    grid $w.info.xscroll -row 1 -column 0 -rowspan 1 -columnspan 1 -sticky news
    grid rowconfig    $w.info 0 -weight 1 -minsize 0
    grid columnconfig $w.info 0 -weight 1 -minsize 0

    frame $w.buttons
    pack  $w.buttons -side bottom -expand y -fill x -pady 2m
    button $w.buttons.dismiss -text Dismiss -command "destroy $w"
    pack $w.buttons.dismiss -side left -expand 1

    set longest 0
    foreach tup $infolist {
        set length [string length [lindex $tup 0]]
	if {$length > $longest} { set longest $length }
    }
    set formatstr [format "%%-%ds : %%s" $longest]
    foreach tup $infolist {
        $w.info.list insert end [format $formatstr \
		[TCLstring [lindex $tup 0]] [TCLstring [lindex $tup 1]]]
    }
}


#---
# snd-do(errorf(fmt,args))
#-
# pops up a formatted error window which cannot be ignored
#---
proc errorf {fmt args} {
    set nwargs {}
    foreach arg $args {
        lappend nwargs [TCLstring $arg]
    }
    eval "set errormsg \[format $fmt $nwargs\]"
    set button [tk_messageBox -icon error -type ok \
	-title Message -parent . -message $errormsg]
}

#---
# snd-do(error(Msg))
#-
# pops up an error window which cannot be ignored
#---
proc error {msg} {
    set button [tk_messageBox -icon error -type ok \
	-title Message -parent . -message [TCLstring $msg]]
}



#---
# rec-ack-event(e)
#-
# prints diagnostics
#---
proc rec-ack-event { arg } {
    global g
    GBin "rec-ack-event($arg)"

    TBack $arg
}


#---
# rec-terminate(m)
#-
# prints diagnostics, the termination message and exits
#---
proc rec-terminate { arg } {
    GBin "rec-ack-event($arg)"
    puts stderr $arg
    exit
}


#----------------------------------------------------------------------
# event handling functions
#----------------------------------------------------------------------

# as the mouse moves over an object change its shading
proc mouse_anyenter {c} {
    global saveFill
    set obj [string range [lindex [$c gettags current] 0] 1 end]
    set type [string range $obj 0 3]
    if {$type == "node"} {
	set saveFill [list $obj [lindex [$c itemconfigure 1$obj -fill] 4]]
	$c itemconfigure 1$obj -fill black -stipple gray12
    }
}

# as the mouse moves out of an object restore its shading
proc mouse_anyleave {c} {
    global saveFill
    set obj [string range [lindex [$c gettags current] 0] 1 end]
    set type [string range $obj 0 3]
    if {$type == "node"} {
	$c itemconfigure 1[lindex $saveFill 0] \
		-fill [lindex $saveFill 1] -stipple {}
    }
}

proc mouse_b1_press {c x y} {
    global g SHADOWSTYLE

    set obj [GetObject $c]
    if {$obj != {}} {
	set type [string range $obj 0 3]
	if {$type == "node"} {
  	  if {[$obj queryattributes shape] == $SHADOWSTYLE} {
            tk_popup .shadowmodule-popup $x $y
	  } else {
            tk_popup .module-popup $x $y
          }
	} else {
          tk_popup .canvas-popup $x $y
        }
    } else {
        tk_popup .canvas-popup $x $y
    }
}

#----------------------------------------------------------------------
# other functions
#----------------------------------------------------------------------


#--
# GBevent(event)
#-
# sends 'snd-event(event)' to the TB
#--
proc GBevent { event } {
    TBsend "snd-event($event)"
    GBmsg "outgoing event: $event"
}


#--
# GBpost(event)
#-
# posts 'snd-event(event)' to the TB
#--
proc GBpost { event } {
    TBpost $event
    GBmsg "posting event: $event"
}


#--
# GBvalue(value)
#-
# sends 'snd-value(value)' to the TB
#--
proc GBvalue { value } {
    TBsend "snd-value($value)"
    GBmsg "outgoing value: $value"
}


#--
# GBin(s)
#-
# prints diagnostics on stderr
#--
proc GBin { s } {
    GBmsg "incoming: $s"
}


#--
# GBmsg(msg)
#-
# prints diagnostics on stderr
#--
proc GBmsg { msg } {
    global DIAG
    if {$DIAG} {puts stderr "GB: $msg"}
}


#--
# GetObject(c)
#-
# returns the id of the object that is currently selected on canvas c
#--
proc GetObject { c } {
    return [string range [lindex [$c gettags current] 0] 1 end]
}


#--
# GetObjectName(c)
#-
# returns the name of the object that is currently selected on canvas c
# (object needs to have a showname function which is the case with TclDot
# object)
#--
proc GetObjectName { c } {
    return [[GetObject $c] showname]
}


#--
# SelectedModules()
#-
# returns the list of modules currently selected in the modules listbox
#--
proc SelectedModules {} {
    set selection {}
    foreach ind [.modules.list curselection] {
	lappend selection [.modules.list get $ind]
    }
    return $selection
}


#--
# EditModules(ML)
#-
# generates the toolbus event to request editing of modules ML
#--
proc EditModules { modlist } {
    foreach mod $modlist {
	GBpost [format "edit-module(%s)" [ToId $mod]]
    }
}

proc EditSdf2Modules { modlist } {
    foreach mod $modlist {
	GBpost [format "edit-module(%s)" [ToId $mod]]
    }
}

proc EditEqsModules { modlist } {
    foreach mod $modlist {
	GBpost [format "edit-eqs-module(%s)" [ToId $mod]]
    }
}


#--
# EditTerm(M,W)
#-
# generates the toolbus event to request editing of a term over module M
# and destroys the widget $w.
#--
proc EditTerm {mod w} {
    GBevent [format "edit-term(%s,%s)" [ToId $mod] [ToId [$w.editTerm get]]]
    destroy $w
}


#--
# SaveModules(ML)
#-
# generates the toolbus event to request saving of modules ML
#--
proc SaveModules { modlist } {
    foreach mod $modlist {
        GBpost [format "save-module(%s)" [ToId $mod]]
    }
}


#--
# RevertModules(ML)
#-
# generates the toolbus event to request reverting of modules ML
#--
proc RevertModules { modlist } {
    foreach mod $modlist {
        GBpost [format "revert-module(%s)" [ToId $mod]]
    }
}


#--
# DeleteModules(ML)
#-
# generates the toolbus event to delete modules ML.
#--
proc DeleteModules { modlist graph } {
    foreach mod $modlist {
        GBpost [format "delete-module(%s)" [ToId $mod]]
    }
}


#--
# CompileModules(ML)
#-
# generates the toolbus event to request compilation of modules ML
#--
proc CompileModules { modlist } {
    foreach mod $modlist {
	GBpost [format "compile-module(%s)" [ToId $mod]]
    }
}


#--
# ParseEquations(ML)
#-
# generates the toolbus event to request compilation of modules ML
#--
proc ParseEquations { modlist } {
    foreach mod $modlist {
       GBpost [format "parse-equations(%s)" [ToId $mod]]
    }
}


#--
# OpenModule(M)
#-
# generates the toolbus event to request addition of a module
# and destroys the widget $w.
#--
proc OpenModule { mod } {
    global opening

    set opening 1
    GBevent [format "open-module(%s)" [ToId $mod]]
}


#--
# OpenModuleHelper(w)
#-
# calls OpenModule for requested module and destroys the widget $w.
#--
proc OpenModuleHelper {w} {
    OpenModule [$w.openModule get]
    destroy $w
}


#--
# ClearAll
#-
# generates the toolbus event to request clearing of all modules
#--
proc ClearAll {c g} {
    GBevent "clear-all"
    $g delete
    set g [make-and-init-new-graph]
    $c delete all
    update-graph
}


#--
# SaveAll
#-
# generates the toolbus event to request saving of all modules
#--
proc SaveAll {} {
    GBevent "save-all"
}



#--
# RevertAll
#-
# generates the toolbus event to request reverting of all modules
#--
proc RevertAll {} {
    GBevent "revert-all"
}


#--
# CompileAll
#-
# generates the toolbus event to request compilation of all modules
#--
proc CompileAll {} {
    GBevent "compile-all"
}


#--
# GetModuleInfo(ML)
#-
# generates the toolbus event to request module info for modules ML
#--
proc GetModuleInfo { modlist } {
    foreach mod $modlist {
        GBpost [format "get-module-info(%s)" [ToId $mod]]
    }
}


#--
# ToId(m)
#-
# returns id("m")
#--
proc ToId { mod } {
    return [format "id(\"%s\")" $mod]
}


#--
# StripId(id("m"))
#-
# returns m
#--
proc StripId { trm } {
    return [string range $trm 4 [expr [string length $trm] - 3]]
}


#--
# ViewAll
#-
# enlarges the window to contain the full graph (clipped MAX/MIN WINSIZE)
#--
proc ViewAll {} {
    global c MAXWINSIZE MINWINSIZE
    set bbox [$c bbox all]
    if {$bbox == {}} { set bbox {0 0 0 0} }

    set w [expr [lindex $bbox 2] - [lindex $bbox 0]]
    set h [expr [lindex $bbox 3] - [lindex $bbox 1]]

    if [expr $w > [lindex $MAXWINSIZE 0]] {set w [lindex $MAXWINSIZE 0]}
    if [expr $h > [lindex $MAXWINSIZE 1]] {set h [lindex $MAXWINSIZE 1]}
    if [expr $w < [lindex $MINWINSIZE 0]] {set w [lindex $MINWINSIZE 0]}
    if [expr $h < [lindex $MINWINSIZE 1]] {set h [lindex $MINWINSIZE 1]}

    $c configure -scrollregion $bbox -width $w -height $h
}


proc OpenModuleWidget {} {
#    set w .openModule
#    catch {destroy $w}
#    toplevel $w
#    wm title $w "Open module"
#    wm iconname $w "Open module"
#    label $w.message -text "Open module:"
#    entry $w.openModule
#    bind $w.openModule <Return> "OpenModuleHelper $w"
#    frame $w.buttons
#    button $w.buttons.confirm -text OK -command "OpenModuleHelper $w"
#    button $w.buttons.cancel -text Cancel -command "destroy $w"
#    pack $w.buttons.confirm $w.buttons.cancel -side left -expand 1
#    pack $w.message $w.openModule -side top -anchor w
#    pack $w.buttons -side bottom -expand y -fill x -pady 2m

  set types {
      {{SDF2}   {.sdf2}        }
      {{Any}    *              }
  }
  set mod [GetBasename [tk_getOpenFile -filetypes $types \
                                       -title "Open SDF Module..."] \
                        ".sdf2"]
  if [ expr [ string length $mod ] > 0 ] {
    OpenModule $mod
  }
}

proc GetBasename {fnam ext} {
  set start [string last "/" $fnam]
  if [expr $start < 0]  {
    set start 0
  } else {
    set start [expr $start + 1 ]
  }
  set end [string last ".sdf2" $fnam]
  if [expr $end < 0]  {
    set end [string length $fnam]
  } else {
    set end [expr $end - 1 ]
  }
  set fnam [string range  $fnam $start $end]

  return $fnam
}

proc NewModuleWidget {} {

  set types {
      {{SDF2}   {.sdf2}        }
      {{Any}    *              }
  }
  set mod [GetBasename [tk_getSaveFile -filetypes $types \
                                       -title "New SDF Module..."] \
                        ".sdf2"]
  if [ expr [ string length $mod ] > 0 ] {
    NewModule $mod
  }
}

proc EditTermWidget {mod} {
    global g
    set w .editterm
    catch {destroy $w}
    toplevel $w
    wm title $w "Edit Term"
    wm iconname $w "Edit Term"
    label $w.message -text "Edit Term:"
    entry $w.editTerm
    bind $w.editTerm <Return> "EditTerm $mod $w"
    frame $w.buttons
    button $w.buttons.confirm -text OK -command "EditTerm $mod $w"
    button $w.buttons.cancel -text Cancel -command "destroy $w"
    pack $w.buttons.confirm $w.buttons.cancel -side left -expand 1
    pack $w.message $w.editTerm -side top -anchor w
    pack $w.buttons -side bottom -expand y -fill x -pady 2m
}


proc AddUniqueEdge { graph from to } {
    if [catch {$graph findedge [$from showname] [$to showname]} ] {
	$from addedge $to
    }
}

#--
# OnlineHelp()
#-
# generates the toolbus event to start the online help facility.
#--
proc OnlineHelp { } { 

    GBevent [format "online-help"]
}

#--
# NoOnlineHelp()
#-
# generates the toolbus event to start the online help facility.
#--
proc NoOnlineHelp { } { 

    GBevent [format "no-online-help"]
}

proc Help {msg just class} {
    global toolname
    set w ".help$class"
    catch {destroy $w}
    toplevel $w
    wm title $w "$toolname Help"
    wm iconname $w $toolname
    frame $w.menu -relief raised -bd 2
    pack $w.menu -side top -fill x
    label $w.msg -justify $just -text $msg
    pack $w.msg -side top -pady 2m -padx 2m
    frame $w.buttons
    pack  $w.buttons -side bottom -expand y -fill x -pady 2m
    button $w.buttons.dismiss -text Dismiss -command "destroy $w"
    pack $w.buttons.dismiss -side left -expand 1
}

proc Print {} {
    global g printCommand
    if {[catch {open "| $printCommand" w} f]} {
        Warning "Unable to open pipe to printer command:\n$printCommand; return"
    }
    $g write $f ps
    close $f
    message "Graph printed to:\n$printCommand"
}

proc setPrinterCommand {w} {
    global printCommand
    set printCommand [$w.printCommand get]
    message "Printer command changed to:\n$printCommand"
    destroy $w
}

proc printSetup {} {
    global printCommand
    set w .printer
    catch {destroy $w}
    toplevel $w
    wm title $w "Printer"
    wm iconname $w "Printer"
    label $w.message -text "Printer command:"
    entry $w.printCommand
    $w.printCommand insert end $printCommand
    bind $w.printCommand <Return> "setPrinterCommand $w"
    frame $w.buttons
    button $w.buttons.confirm -text OK -command "setPrinterCommand $w"
    button $w.buttons.cancel -text Cancel -command "destroy $w"
    pack $w.buttons.confirm $w.buttons.cancel -side left -expand 1
    pack $w.message $w.printCommand -side top -anchor w
    pack $w.buttons -side bottom -expand y -fill x -pady 2m
}


proc fileDialog {w operation} {
    #   Type names		Extension(s)	Mac File Type(s)
    #
    #---------------------------------------------------------
    set types {
	{"Import graph terms"   {.ig}	        }
	{"Layouted graph files"	{.dot}	        }
	{"Postscript Files"	{.ps .eps .epsi}}
	{"Image Files"		{.gif}		}
	{"Image Files"		{.jpeg .jpg}	}
	{"Image Files"		""		{GIFF JPEG}}
	{"All files"		*}
    }
    if {$operation == "open"} {
	set file [tk_getOpenFile -filetypes $types -parent $w]
    } else {
	set file [tk_getSaveFile -filetypes $types -parent $w \
	    -initialfile Untitled -defaultextension .dot]
    }
    return $file
}

proc saveFileAs {type} {
  set file [fileDialog . save]
  if [ expr [ string length $file ] > 0 ] {
    saveFileByName $file $type
  }
}

proc saveFileByName {name type} {
    global fileName g
    if {[catch {open $name w} f]} {
        Warning "Unable to open file for write:\n$name; return"
    }
    if {$type == "ig"} {
	set fileName $name
	set nodes {}
	set edges {}
	foreach node [$g listnodes] {
	    lappend nodes [ToId [$node showname]]
	}
	foreach node [$g listnodes] {
	    foreach edge [$node listoutedges] {
		set theedge [$edge listnodes]
		lappend edges [format "\[%s,%s\]" \
			[ToId [[lindex $theedge 0] showname]] \
			[ToId [[lindex $theedge 1] showname]]]
	    }
	}
	puts $f [format "graph(nodes(\[%s\]),edges(\[%s\]))" \
		[join $nodes ,] [join $edges ,]]
    } else {
	$g write $f $type
    }
    close $f
}


proc Message {m} {
    set button [tk_messageBox -icon info -type ok \
	-title Message -parent . -message $m]
}


proc Warning {m} {
    set button [tk_messageBox -icon warning -type ok \
	-title Warning -parent . -message $m]
}


proc UpdateModuleList { graph } {
    set modlist {}
    foreach node [$graph listnodes] {
        lappend modlist [$node showname]
    }
    .modules.list delete 0 end
    foreach mod [lsort $modlist] {
        .modules.list insert end $mod
    }
}


proc define-menu-bar {} {
    global toolname metaname

    frame .menu -relief raised -borderwidth 1

    menubutton .menu.file -text "File" -underline 0 -menu .menu.file.menu
    set m .menu.file.menu
    menu $m
    $m add command -label "New" -state disabled -underline 0 -command {NewModuleWidget}
    $m add command -label "Open" -underline 0 -command {OpenModuleWidget}
    $m add command -label "Save" -underline 0 -command {SaveAll}
    $m add separator
    $m add command -label "Clear" -underline 0 -command {ClearAll $c $g}
    $m add command -label "Revert" -underline 0 -command {RevertAll}
    $m add separator
    $m add cascade -label "Export" -underline 1 -menu $m.export

    menu $m.export -tearoff 0
    $m.export add command -label "Import-Graph ..." -underline 0 -command {saveFileAs ig}
    $m.export add command -label "GIF ..." -underline 0 -command {saveFileAs gif}
    $m.export add command -label "ISMAP ..." -underline 0 -command {saveFileAs ismap}
    $m.export add command -label "HPGL ..." -underline 0 -command {saveFileAs hpgl}
    $m.export add command -label "MIF ..." -underline 0 -command {saveFileAs mif}
    $m.export add command -label "PCL ..." -underline 1 -command {saveFileAs pcl}
    $m.export add command -label "PostScript ..." -underline 0 -command {saveFileAs ps}
    $m add separator
    $m add command -label "Print Setup ..." -underline 0 -command {printSetup}
    $m add command -label "Print" -underline 0 -command {Print}
    $m add separator
    $m add command -label "Quit" -underline 0 -command {GBevent button(quit)}

    menubutton .menu.edit -text "Edit" -underline 0 -menu .menu.edit.menu
    set m .menu.edit.menu
    menu $m
    $m add command -label "Undo" -state disabled    -underline 0 -command {}
    $m add separator
    $m add command -label "Cut" -state disabled     -underline 2 -command {}
    $m add command -label "Copy" -state disabled    -underline 0 -command {}
    $m add command -label "Paste" -state disabled   -underline 0 -command {}
    $m add separator
    $m add command -label "Preferences ..." -state disabled  -underline 1 -command {}

#    menubutton .menu.specification -text "Specification" -underline 0 \
#	-menu .menu.specification.menu
#    set m .menu.specification.menu
#    menu $m

# Adapted by Mark
#    $m add separator
#    $m add command -label "Compile All" -underline 0 -command {CompileAll}

    menubutton .menu.window -text "Graph" -underline 0 -menu .menu.window.menu
    set m .menu.window.menu
    menu $m
    $m add command -label "View all" -underline 0 -command {ViewAll}
    $m add check -label "Autoresize after loading" -underline 0 -variable autoresize
    $m add separator
    $m add check -label "Animate while loading" -underline 0 -variable animate

    menubutton .menu.help -text "Help" -underline 0 -menu .menu.help.menu
    menu .menu.help.menu
    .menu.help.menu add command -label "About $metaname" -underline 0 \
        -command {Help $help_meta center a}
    .menu.help.menu add command -label "About $toolname" -underline 9 \
        -command {Help $help_about center b}
    .menu.help.menu add command -label "Mouse Operations" -underline 0 \
        -command {Help $help_mouse left c}
    .menu.help.menu add command -label "Activate Online Help" -underline 10 \
        -command {OnlineHelp}
    .menu.help.menu add command -label "Deactivate Online Help" -underline 0 \
        -command {NoOnlineHelp}

    menubutton .menu.debug -text "Debug" -underline 0 -menu .menu.debug.menu
    set m .menu.debug.menu
    menu $m
    $m add check -label "Diagnostic messages"  -variable DIAG

#        .menu.specification {left} 
    pack append .menu .menu.file {left} .menu.edit {left} \
        .menu.window {left} .menu.debug {left} .menu.help {right}

    tk_menuBar .menu.file .menu.specification .menu.window .menu.help
}

proc define-modules-frame {} {
    global SBW
    frame .modules -borderwidth 2 -relief groove
    scrollbar .modules.yscroll -width $SBW -orient vertical \
        -command {.modules.list yview}
    scrollbar .modules.xscroll -width $SBW -orient horizontal \
        -command {.modules.list xview}
    listbox .modules.list -width 16 -height 8 -relief flat \
	-selectmode extended -yscroll {.modules.yscroll set} \
	-xscroll {.modules.xscroll set}

    frame .modules.buttons

    button .modules.buttons.editsdfmod -text "Edit Sdf2" \
	-command {EditSdf2Modules [SelectedModules]}
    button .modules.buttons.editeqsmod -text "Edit Eqs" \
	-command {EditEqsModules [SelectedModules]}
    button .modules.buttons.editterm -text "Term" \
	-command {foreach i [SelectedModules] {
	    EditTermWidget $i
	} }
    button .modules.buttons.savemod -text "Save" \
        -command {SaveModules [SelectedModules]}
    button .modules.buttons.revertmod -text "Revert" \
	-command {RevertModules [SelectedModules]}
    button .modules.buttons.deletemod -text "Delete" \
	-command {DeleteModules [SelectedModules] $g}
    button .modules.buttons.modinfo -text "Info" \
	-command {GetModuleInfo [SelectedModules]}
    button .modules.buttons.compile -text "Compile" \
	-command {CompileModules [SelectedModules]}
    button .modules.buttons.parseeqs -text "ParseEqs" \
       -command {ParseEquations [SelectedModules]}

    pack append .modules.buttons \
        .modules.buttons.editsdfmod {top fillx} \
        .modules.buttons.editeqsmod {top fillx} \
	.modules.buttons.editterm {top fillx} \
        .modules.buttons.savemod {top fillx} \
        .modules.buttons.revertmod {top fillx} \
        .modules.buttons.deletemod {top fillx} \
        .modules.buttons.modinfo {top fillx} \
        .modules.buttons.compile {top fillx} \
        .modules.buttons.parseeqs {top fillx}

    grid .modules.list    -row 0 -column 0 -rowspan 1 \
        -columnspan 1 -sticky news
    grid .modules.yscroll -row 0 -column 1 -rowspan 1 \
        -columnspan 1 -sticky news
    grid .modules.xscroll -row 1 -column 0 -rowspan 1 \
        -columnspan 1 -sticky news
    grid .modules.buttons -row 0 -column 2 -rowspan 2 \
        -columnspan 1 -sticky news

    grid rowconfig    .modules 0 -weight 1 -minsize 0
    grid rowconfig    .modules 1 -weight 0

    grid columnconfig .modules 0 -weight 1 -minsize 0
    grid columnconfig .modules 1 -weight 0
    grid columnconfig .modules 2 -weight 0
}

proc define-graph-frame {} {
    global c SBW
    frame .graph -borderwidth 2 -relief groove

    set c [canvas .graph.canvas -cursor crosshair \
        -xscrollcommand {.graph.xscroll set} \
        -yscrollcommand {.graph.yscroll set} \
        -borderwidth 0]

    $c xview scroll 10 unit
    $c yview scroll 10 unit

    scrollbar .graph.xscroll -width $SBW -orient horizontal \
        -command "$c xview"
    scrollbar .graph.yscroll -width $SBW -orient vertical \
        -command "$c yview"

    set buttonwidth [expr $SBW - 2]
    button .graph.layout -width $buttonwidth -height $buttonwidth \
    	-bitmap gray50 -command "update-graph"

    grid .graph.canvas  -row 0 -column 0 -rowspan 1 \
        -columnspan 1 -sticky news
    grid .graph.yscroll -row 0 -column 1 -rowspan 1 \
        -columnspan 1 -sticky news
    grid .graph.xscroll -row 1 -column 0 -rowspan 1 \
        -columnspan 1 -sticky news
    grid .graph.layout -row 1 -column 1 -rowspan 1 \
        -columnspan 1 -sticky news

    grid rowconfig    .graph 0 -weight 1 -minsize 0
    grid rowconfig    .graph 1 -weight 0

    grid columnconfig .graph 0 -weight 1 -minsize 0
    grid columnconfig .graph 1 -weight 0
}

proc define-status-frame {} {
    frame .status -relief raised
    label .status.label -text "Status:"
    label .status.msg -borderwidth 2 -relief sunken -anchor w -textvariable status
    pack append .status .status.label {left} .status.msg {left expand fill}
}

proc define-module-popup {} {
    set m .module-popup
    menu $m -tearoff 0
    $m add command -label "Edit Sdf2 module" \
        -command {EditSdf2Modules [GetObjectName $c]}
    $m add command -label "Edit Eqs module" \
        -command {EditEqsModules [GetObjectName $c]}
    $m add command -label "Edit term" \
        -command {EditTermWidget [GetObjectName $c]}
    $m add separator
    $m add command -label "Save module" \
        -command {SaveModules [GetObjectName $c]}
    $m add command -label "Revert module" \
        -command {RevertModules [GetObjectName $c]}
    $m add command -label "Delete module" \
        -command {DeleteModules [GetObjectName $c] $g}
    $m add separator
    $m add command -label "Module info" \
        -command {GetModuleInfo [GetObjectName $c]}
    $m add separator
    $m add command -label "Compile module" \
        -command {CompileModules [GetObjectName $c]}
    $m add command -label "Parse equations" \
        -command {ParseEquations [GetObjectName $c]}
}

proc define-shadowmodule-popup {} {
    set m .shadowmodule-popup
    menu $m -tearoff 0
    $m add command -label "Open this module" \
        -command {OpenModule [GetObjectName $c]}
    $m add command -label "Edit this module" \
        -command {EditModules [GetObjectName $c]}
}

proc define-modlist-popup {} {
    set m .modlist-popup
    menu $m -tearoff 0
    $m add command -label "Edit modules" \
        -command {EditModules [SelectedModules]}
    $m add separator
    $m add command -label "Save modules" \
        -command {SaveModules [SelectedModules]}
    $m add command -label "Revert modules" \
        -command {RevertModules [SelectedModules]}
    $m add command -label "Delete modules" \
        -command {DeleteModules [SelectedModules] $g}
    $m add separator
    $m add command -label "Modules info" \
        -command {GetModuleInfo [SelectedModules]}
}

proc define-canvas-popup {} {
    set m .canvas-popup
    menu $m -tearoff 0
    $m add command -label "Open module" -command "OpenModuleWidget"
}

proc make-and-init-new-graph {} {
  global SHADOWSTYLE
  set g [dotnew digraph]
  $g setnodeattributes shape $SHADOWSTYLE
  return $g
}


#----------------------------------------------------------------------
# "main" program
#----------------------------------------------------------------------

set g [make-and-init-new-graph]
set saveFill {}
set fileName {no_name.dot}
set printCommand {lpr}

wm title . $toolname
wm iconname . $toolname

define-menu-bar
define-graph-frame
define-modules-frame
define-status-frame

grid .menu    -row 0 -column 0 -rowspan 1 -columnspan 2 -sticky news
grid .graph   -row 1 -column 0 -rowspan 1 -columnspan 1 -sticky news
grid .modules -row 1 -column 1 -rowspan 1 -columnspan 1 -sticky news
grid .status  -row 2 -column 0 -rowspan 1 -columnspan 2 -sticky news

grid rowconfig    . 0 -weight 0
grid rowconfig    . 1 -weight 1 -minsize 0
grid rowconfig    . 2 -weight 0

grid columnconfig . 0 -weight 1 -minsize 0
grid columnconfig . 1 -weight 0

define-module-popup
define-shadowmodule-popup
define-modlist-popup
define-canvas-popup

bind $c <ButtonPress-1> "mouse_b1_press $c %X %Y"
bind $c <ButtonPress-3> "mouse_b1_press $c %X %Y"

$c bind all <Any-Enter> "mouse_anyenter $c"
$c bind all <Any-Leave> "mouse_anyleave $c"

bind $c <ButtonPress-2> "$c scan mark %x %y"
bind $c <B2-Motion> "$c scan dragto %x %y"

bind .modules.list <ButtonPress-3> "tk_popup .modlist-popup %X %Y"
