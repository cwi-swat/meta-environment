# Module initialization
proc tide-init-ui-process-list { } {
  tide-init-modules { daps processes exec-state exec-control current-port }
}

# Process list creation/destruction
proc tide-ui-process-list-create { dap w } {
  global Viewer Dap Proc ES IMG

  set Viewer($dap,pid-selection) $dap
  set Viewer($dap,pids) all
  set Viewer($dap,pid-selection) all
  set Viewer($dap,wprocess-list) $w

  frame $w -borderwidth 2 -relief groove
  label $w.label -text "Processes:" -width 16
  frame $w.toolbar

  if { [lsearch $Dap($dap,info) exec-control] != -1 } {
    foreach elem $Dap($dap,info,exec-control) {
      button $w.toolbar.button$elem \
		-bitmap @$ES($elem) \
		-command "pl-do-exec-control-button $dap exec-control $elem" \
		-state normal \
		-anchor c
      pack $w.toolbar.button$elem -side left
      set Viewer($dap,button,$elem) $w.toolbar.button$elem
    }
    frame $w.toolbar.f1 -width 8
    pack $w.toolbar.f1
  }

  if { $Dap($dap,info,multi-process) } {
    frame $w.list
    canvas $w.list.c -width 40 -height 60\
	-xscrollcommand "$w.x set" \
	-yscrollcommand "$w.list.y set"
    scrollbar $w.x -command "$w.list.c xview" -orient hor
    scrollbar $w.list.y -command "$w.list.c yview" -orient vert

    pack $w.list.c -side left -expand 1 -fill both
    pack $w.list.y -side right -fill y

    checkbutton $w.selection \
	-text "Select all" \
	-onvalue all \
	-offvalue partial \
	-variable Viewer($dap,pid-selection) \
	-command "pl-do-select-all $dap"

    set Viewer($dap,wprocs) $w.list.c
    foreach pid $Dap($dap,pids) {
      set Viewer($dap,$pid,mapped) 0
    }
    pl-draw-process-list $dap

    pack $w.label -side top -fill x
    pack $w.list -side top -expand 1 -fill both
    pack $w.x -side top -fill x
    pack $w.selection -side bottom -fill x

    pl-update-process-list $dap
  } else {
    label $w.toolbar.state -image $IMG(unknown)
    pack $w.toolbar.state -side right
    set Viewer($dap,wstate) $w.toolbar.state
  }
  pack $w.toolbar -side top -fill x
}
proc tide-ui-process-list-destroy { dap } {
  global Dap Viewer
  destroy $Viewer($dap,wprocess-list)
  unset Viewer($dap,wprocess-list)
  unset Viewer($dap,wprocs)
  # <PO>: etc.
}

# Update process selection
proc tide-ui-select-processes { dap pids } {
  global Viewer

  set Viewer($dap,pids) $pids
  pl-update-process-list $dap
}

# Callbacks
proc tide-process-created-process-list { dap pid name } {
  global Viewer Proc ES

  puts stderr "process-created: $dap $pid $name"
  set Viewer($dap,$pid,mapped) 0
  set Viewer($dap,$pid,selected) 1
  pl-draw-process-list $dap
}
proc tide-process-destroyed-process-list { dap pid } {
  global Viewer Dap

  if { [info exists $Viewer($dap,wprocs) } {
    $Viewer($dap,wprocs) delete entry $pid
  }
}
proc tide-current-port-process-list { dap pids port } {
  global Viewer

  set Viewer($dap,pids) $pids
  pl-update-process-list $dap

  if { $pids == "all" } {
    set Viewer($dap,pid-selection) all
  } else {
    set Viewer($dap,pid-selection) partial
  }
  pl-update-process-list $dap
}
proc tide-exec-state-process-list { dap pids state } {
  global Dap Viewer IMG

  if { [info exists Viewer($dap,wprocess-list)] } {
    if { $Dap($dap,info,multi-process) } {
      foreach pid $pids {
        pl-update-process $dap $pid
      }
    } else {
      $Viewer($dap,wstate) configure -image $IMG($state)
    }
  } else {
    puts stderr "Viewer($dap,wprocess-list) does not exist"
  }
}

# Local functions
proc pl-draw-process-list { dap } {
  global Dap Proc Viewer IMG

  puts stderr "pl-draw-process-list: $Dap($dap,pids)"
  # First, we clean up all existing items
  if { [info exists Viewer($dap,wprocs)] } {
    foreach pid $Dap($dap,pids) {
      if { $Viewer($dap,$pid,mapped) } {
        $Viewer($dap,wprocs) delete $Viewer($dap,$pid,check-item)
        $Viewer($dap,wprocs) delete $Viewer($dap,$pid,state-item)
        $Viewer($dap,wprocs) delete $Viewer($dap,$pid,name-item)
      }
    }

    # Now we draw all the processes
    set y 16
    set w $Viewer($dap,wprocs)
    foreach pid $Dap($dap,pids) {
      # Create 'checked' item
      set item [$w create image 10 $y -anchor c -image $IMG(selected,1)]
      set Viewer($dap,$pid,check-item) $item
      $w bind $item <ButtonPress-1> "pl-do-process-selected $dap $pid"

      # Create 'state' item
      set item [$w create image 30 $y -anchor c -image $IMG(unknown)]
      set Viewer($dap,$pid,state-item) $item
      $w bind $item <ButtonPress-1> "pl-do-process-selected $dap $pid"

      # Create 'name' item    
      set item [$w create text 42 $y -anchor w -text $Proc($dap,$pid,name)]
      set Viewer($dap,$pid,name-item) $item
      $w bind $item <ButtonPress-1> "pl-do-process-selected $dap $pid"

      set Viewer($dap,$pid,mapped) 1
      incr y 24
    }
  }
}
proc pl-update-process { dap pid } {
  global Dap Viewer Proc ES IMG

  if { [info exists Viewer($dap,wprocs)] 
       && [lsearch $Dap($dap,pids) $pid] != -1 &&
	$Viewer($dap,$pid,mapped) } {
    $Viewer($dap,wprocs) itemconfigure $Viewer($dap,$pid,check-item) \
		-image $IMG(selected,$Viewer($dap,$pid,selected))
    $Viewer($dap,wprocs) itemconfigure $Viewer($dap,$pid,state-item) \
		-image $IMG($Proc($dap,$pid,es))
  }
}
proc pl-update-process-list { dap } {
  global Dap Viewer

  if { [info exists Viewer($dap,wprocs)] } {
    set pids $Viewer($dap,pids)
    if { $pids == "all" } {
      set pids $Dap($dap,pids)
    } else {
      foreach pid $Dap($dap,pids) {
        set Viewer($dap,$pid,selected) 0     
      }
    }
    foreach pid $pids {
      set Viewer($dap,$pid,selected) 1
    }
  }
  foreach pid $Dap($dap,pids) {
    pl-update-process $dap $pid
  } 
}
proc pl-do-select-all { dap } {
  global Dap Viewer

  if { $Viewer($dap,pid-selection) == "all" } {
    set Viewer($dap,pids) "all"
    pl-update-process-list $dap
  } else {
    set Viewer($dap,pids) $Dap($dap,pids)
    pl-update-process-list $dap
  }
}
proc pl-do-process-selected { dap pid } {
  global Dap Viewer

  if { $Viewer($dap,pid-selection) == "all" } {
    set Viewer($dap,pid-selection) partial
  }
  if { $Viewer($dap,$pid,selected) } {
    set Viewer($dap,$pid,selected) 0
    set idx [lsearch $Viewer($dap,pids) $pid]
    set Viewer($dap,pids) [lreplace $Viewer($dap,pids) $idx $idx]
  } else {
    set Viewer($dap,$pid,selected) 1
    lappend Viewer($dap,pids) $pid
  }
  pl-update-process $dap $pid
#  set Viewer($dap,pids) [$Viewer($dap,wprocs) subwidget hlist selection get]

  if { $Viewer($dap,pids) == {} } {
    if { [lsearch $Dap($dap,info) exec-control] != -1 } {
      foreach elem $Dap($dap,info,exec-control) {
        $Viewer($dap,button,$elem) configure -state disabled
      }
    }
  } else {
    if { [lsearch $Dap($dap,info) exec-control] != -1 } {
      foreach elem $Dap($dap,info,exec-control) {
        $Viewer($dap,button,$elem) configure -state normal
      }
    }
  }
  tide-call process-selected $dap $pid
}
proc pl-do-exec-control-button { dap class elem } {
  global Viewer Dap

  tide-exec-control $dap $Viewer($dap,pids) $elem
}

# Global variables

set bitmaps $TB_LIBDIR/bitmaps
set ES(unknown)		$bitmaps/unknown.xbm
set ES(stop)		$bitmaps/stop.xbm
set ES(run)		$bitmaps/run.xbm
set ES(single-step)	$bitmaps/single-step.xbm
set ES(step-over)	$bitmaps/step-over.xbm

set IMG(unknown)	[image create bitmap -file $bitmaps/unknown.xbm]
set IMG(stop)		[image create bitmap -file $bitmaps/stop.xbm]
set IMG(run)		[image create bitmap -file $bitmaps/run.xbm]
set IMG(single-step)	[image create bitmap -file $bitmaps/single-step.xbm]
set IMG(step-over)	[image create bitmap -file $bitmaps/step-over.xbm]

set IMG(selected,1)	[image create bitmap -file $bitmaps/selected.xbm]
set IMG(selected,0)	[image create bitmap -file $bitmaps/unselected.xbm]
