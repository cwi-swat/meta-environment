proc create-viewer { dap } {
  global Viewers Viewer Dap Proc ES Style
 
  set w .$dap

  set Dap($dap,viewer) 1
  set Viewer($dap,win) $w
  set Viewer($dap,wbreaks) ""
  set Viewer($dap,module) "<none>"

  toplevel $w
  wm positionfrom $w program
  wm sizefrom $w program
  wm title $w "Source Viewer: $dap"
  wm maxsize $w 1152 900
  wm geometry $w 450x400

  frame $w.menu
  frame $w.toolbar -borderwidth 2 -relief groove
  frame $w.middle
  frame $w.buttons

  frame $w.middle.left

  label $w.middle.left.label -text "Source:"
  frame $w.middle.left.f

  text $w.middle.left.f.text -relief sunken -borderwidth 1 \
	-xscrollcommand "$w.middle.left.x set" \
	-yscrollcommand "$w.middle.left.f.y set" \
	-wrap none \
        -width 2 -height 2

  set Viewer($dap,wtext) $w.middle.left.f.text
  bind $Viewer($dap,wtext) <Key> ""
  bind $Viewer($dap,wtext) <ButtonPress-1> "do-location-selected $dap %x %y"
  bind $Viewer($dap,wtext) <ButtonPress-2> "do-toggle-simple-break $dap %x %y"

  scrollbar $w.middle.left.f.y -orient vert -command "$Viewer($dap,wtext) yview"
  scrollbar $w.middle.left.x -orient hor -command "$Viewer($dap,wtext) xview"
  label $w.middle.left.msg -textvariable Viewer($dap,msg) -borderwidth 2 -relief groove

  tide-ui-process-list-create $dap $w.middle.procs
  if { [lsearch $Dap($dap,info) multi-process] == -1 } {
    pack $w.middle.procs -side top -fill x
  } else {
    pack $w.middle.procs -side left -fill y
  }

  pack $w.middle.left.f.text -side left -expand 1 -fill both
  pack $w.middle.left.f.y -side left -fill y
  pack $w.middle.left.f -side top -expand 1 -fill both
  pack $w.middle.left.x -side top -fill x
  pack $w.middle.left.msg -side top -fill x

  pack $w.middle.left -side left -expand 1 -fill both

  pack $w.menu -side top -fill x
  pack $w.toolbar -side top -fill x
  pack $w.middle -side top -expand 1 -fill both
  pack $w.buttons -side bottom -fill y
}
proc print-message { dap args } {
  global Dap Viewer

  if { $Dap($dap,viewer) } {
    set Viewer($dap,msg) [eval format $args]
  }
}
set dnr 0
proc message-dialog { title msg } {
  global dnr

  incr dnr
  set w .dialog$dnr
  toplevel $w
  wm positionfrom $w program
  wm sizefrom $w program
  wm title $w $title
  wm maxsize $w 1152 900

  message $w.msg -text $msg -borderwidth 2 -relief groove
  button $w.ok -text Ok -command "destroy $w"

  pack $w.msg -side top -expand 1 -fill both
  pack $w.ok -side top -fill x 
}
proc highlight { dap hl port style } {
  global Dap Viewer Style

  # analyze pos
  set type [lindex $port 0]
  set when [lindex $port 1]
  set mod  [lindex $port 2]
  
  if { $type != "location" } {
    return
  }

  # tag becomes something like 'cpe-after', or 'break1-before'
  set tag  ${hl}-$when

  # We highlight the designated area
  set start "[lindex $port 3].[mkcol [lindex $port 4]]"
  set end   "[lindex $port 5].[mkcol [lindex $port 6] 1]"

  # Now we can remove any previous highlight of the same type
  if { [lsearch $Dap($dap,hls) $hl] == -1 } {
    lappend Dap($dap,hls) $hl
  } else {
    set oldpos $Dap($dap,hl,$hl,pos)
    set oldtag $Dap($dap,hl,$hl,tag)
    if { $Dap($dap,viewer) && $Dap($dap,hl,$hl,mod) == $Viewer($dap,module) } {
      $Viewer($dap,wtext) tag remove $oldtag [lindex $oldpos 0] [lindex $oldpos 1]
    }
  }

  # Add the new highlight
  set Dap($dap,hl,$hl,pos) [list $start $end]
  set Dap($dap,hl,$hl,mod) $mod
  set Dap($dap,hl,$hl,tag) $tag
  if { $Dap($dap,viewer) && $Viewer($dap,module) == $mod } {
    eval $Viewer($dap,wtext) tag configure $tag $Style($style)
    $Viewer($dap,wtext) tag add $tag $start $end
    $Viewer($dap,wtext) see $start
    # $Viewer($dap,wtext) see $end
  }
}

proc mkcol { col {offset 0} } {
  if { $col == -1 } {
    return end
  }
  return [expr $col+$offset]
}
proc remove-highlight { dap hl } {
  global Dap Viewer

  set idx [lsearch $Dap($dap,hls) $hl]

  if { $idx != -1 } {
    set tag $Dap($dap,hl,$hl,tag)
    set pos $Dap($dap,hl,$hl,pos)
    # When the highlighted module is currently viewed,
    # we have to remove the physical evidence of the highlight.
    if { $Dap($dap,viewer) && $Dap($dap,hl,$hl,mod) == $Viewer($dap,module) } {
      $Viewer($dap,wtext) tag remove $tag [lindex $pos 0] [lindex $pos 1]
    }
    set Dap($dap,hls) [lreplace $Dap($dap,hls) $idx $idx]
    unset Dap($dap,hl,$hl,pos)
    unset Dap($dap,hl,$hl,mod)
    unset Dap($dap,hl,$hl,tag)
  }
}
proc load-module { dap module } {
  global Dap Viewer

  set paths [tide-get-search-paths $dap source]
  puts stderr "load-module: $module in $paths"
  foreach path $paths {
    set file $path/$module
    puts stderr "trying $file"
    if {[load-file $dap $file]} {
      set Viewer($dap,module) $module
      set Viewer($dap,file) $file
      return 1
    }
  }
  return 0
}
proc load-file { dap file } {
  global Viewer

  $Viewer($dap,wtext) configure -state normal
  $Viewer($dap,wtext) delete 1.0 end

  if { [catch {set f [open $file]}] } {
    return 0
  }
  puts stderr "load-file: $file"

  while {![eof $f]} {
    set data [read $f 1000]
    $Viewer($dap,wtext) insert end $data
  }
  close $f
  $Viewer($dap,wtext) configure -state disabled
  set Viewer($dap,file) $file
  return 1
}

proc do-location-selected { dap x y } {
  global Viewer Dap

  set mod $Viewer($dap,module)
  if { $mod != "" && $mod != "<none>" } {
    set w $Viewer($dap,wtext)
    scan [$w index @$x,$y] "%d.%d" line col
    set procs $Viewer($dap,pids)
    set port [list location at $mod $line 0 $line -1]
    tide-change-current-port $dap $procs $port
 }
}
proc do-toggle-simple-break { dap x y } {
  global Viewer Dap Break OPoint

  set mod $Viewer($dap,module)
  if { $mod != "" } {
    # First, we are going to try to delete a simple breakpoint at this line.
    set tags [$Viewer($dap,wtext) tag names @$x,$y]
    set rules {}
    foreach tag $tags {
      if { [scan $tag "rule-%d" rid] } {
        lappend rules $rid
      }
    }
    if { $rules != {} } {
      foreach rid $rules {
        if { $Rule($dap,$rid,cond) == "true" && \
	     $Rule($dap,$rid,acts) == "break" && \
	     [lindex $Rule($dap,$rid,port) 0] == "location" } {
	  tide-destroy-rule $dap $rid
	  print-print-message $dap "Destroyed rule $rid"
	  return
        }
      }
      print-message $dap "Cannot remove complex rule(s): $rules"
    } else {
      set w $Viewer($dap,wtext)
      scan [$w index @$x,$y] "%d.%d" line col
      set procs $Viewer($dap,pids)

      # <PO>: at should actually depend on info!
      set loc [list location at $mod $line 0 $line -1]
      tide-create-rule break $dap $procs $loc true break persistent
      print-message $dap "Breakpoint set at line $line"
    }
  }
}

proc tide-dap-connected-sb { dap procs info } {
  global Dap

  set Dap($dap,viewer) 0
  set Dap($dap,hls) {}
  set Dap($dap,file) ""
}
proc tide-dap-disconnected-sb { dap } {
  global Daps Dap Viewers Viewer

  set index [lsearch $Viewers $dap]
  if { $index != -1 } {
    set Viewers [lreplace $Viewers $index $index]
    destroy $Viewer($dap,win)
    if { $Viewer($dap,wbreaks) != "" } {
      destroy $Viewer($dap,wbreaks)
    }
    unset Viewer($dap,win)
    unset Dap($dap,file)
    unset Dap($dap,hls)
    unset Dap($dap,viewer)
  }
}
proc tide-rule-created-sb { dap rid pids port cond acts life } {

  if { [lindex $port 0] == "location" } {
    if { [lsearch $acts break] != -1 ||
         [lsearch $acts halt] != -1 || [lsearch $acts stop] != -1 } {
      set style breakpoint
    } else {
      set style watchpoint
    }
    highlight $dap rule-$rid $port $style
  }
}
proc tide-rule-destroyed-sb { dap rid } {
  remove-highlight $dap rule-$rid
}

proc tide-exec-state-sb { dap pids state } {
  if { $state != "stop" } {
    foreach pid $pids {
      remove-highlight $dap cpe$pid
    }
  }
}
proc tide-cpe-sb { dap pid port } {
  global Dap Viewer


  set mod [lindex $port 2]
  set when [lindex $port 1]

  if { $mod != "" } {
    if { $Dap($dap,viewer) } {
      if { $Viewer($dap,module) != $mod } {
        load-module $dap $mod
      }
    }
    highlight $dap cpe$pid $port cpe-$when
  }
}
proc tide-current-port-sb { dap pids port } {
  highlight $dap selected $port selected
}

proc view-source { dap } {
  global Dap Viewers Viewer

  if { [lsearch $Viewers $dap] == -1 } {
    # Create a new viewer
    set Viewer($dap,pids) "all"
    set Viewer($dap,pid-selection) "all"
    lappend Viewers $dap
    create-viewer $dap
    if { $Dap($dap,current-port) != "" } {
      tide-current-port-sb $dap $Dap($dap,current-pids) $Dap($dap,current-port)
    }
    tide-watch-cpe $dap all { exec-state at stop }
    tide-watch-exec-state $dap
  } else {
    raise $Viewer($dap,win)
  }
}
proc exception { P Port Exception Msg Details } {
  global Dap Viewer PAT_PROC PAT_PROCS PAT_ALL

  set port [TCLport $Port]

  if { [regexp $PAT_ALL $P P dap] } {
    set pids all
  } elseif { [regexp $PAT_PROCS $P P dap Pids] } {
      set pids $Pids
  } else {
    puts stderr "*** exception: wrongly formatted process spec $P"
    return
  }

  set msg [TCLstring $Msg]
  set exception [TCLstring $Exception]

  if { [string first "\n" $msg] == -1 && [string length $msg] < 40} {
    print-message $dap "$exception: $msg"
  } else {
    message-dialog "Exception" "$exception: $msg"
  }
  set mod [lindex $port 2]
  set when [lindex $port 1]
  
  if { $mod != "" } {
    if { $Dap($dap,viewer) } {
      if { $Viewer($dap,module) != $mod } {
        load-module $dap $mod
      }
    }
    highlight $dap exception $port exception
  }
}

set Viewers {}

set Style(breakpoint)	"-background orange"
set Style(watchpoint)	"-background green"
set Style(cpe-before)	"-borderwidth 2 -relief groove -foreground blue"
set Style(cpe-after)	"-borderwidth 2 -relief ridge -foreground blue"
set Style(selected)	"-borderwidth 2 -relief sunken"
set Style(exception)	"-borderwidth 2 -relief raised -background yellow"

wm withdraw .
source "tide-modules.tcl"
tide-init "Source viewer" { 
  daps 
  processes 
  event-rules 
  cpe 
  exec-state 
  exec-control 
  current-port
  ui-process-list
}
