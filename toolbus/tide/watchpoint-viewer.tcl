proc create-wp-dialog { dap vid } {
  global dialogcount Dialog Viewer Dap

  set id $dialogcount
  incr dialogcount

  set w .d$id
  incr dialogcount
  set Dialog($id,vid) $vid
  set Dialog($id,win) $w
  set Dialog($id,dap) $dap
  set Dialog($id,type) existing

  toplevel $w
  wm positionfrom $w program
  wm sizefrom $w program
  wm title $w "Create Watchpoint: $dap"
  wm maxsize $w 1152 900

  label $w.label -textvariable Dialog($id,msg)
  pack $w.label -side top -fill x
  set Dialog($id,msg) "Use an existing rule or create a new one?"
  frame $w.f
  set f $w.f

    frame $f.existing -borderwidth 2 -relief groove
    radiobutton $f.existing.radio -text "Existing rule:" \
  	-variable Dialog($id,type) \
  	-value existing

    set rlw [tide-create-rule-list $dap $id $f.existing]

    pack $f.existing.radio -side top -fill x
    pack $rlw -side top -expand 1 -fill both
    pack $f.existing -side left -expand 1 -fill both

    set Dialog($id,wrules) $rlw.list
    frame $f.new -borderwidth 2 -relief groove
    radiobutton $f.new.rvar -text "New variable watchpoint:" \
  	-variable Dialog($id,type) \
  	-value new-var
    entry $f.new.var -textvariable Dialog($id,var)
    radiobutton $f.new.rexpr -text "New expression watchpoint:" \
  	-variable Dialog($id,type) \
  	-value new-expr
    entry $f.new.expr -textvariable Dialog($id,expr)
    pack $f.new.rvar -side top
    pack $f.new.var -side top -fill x
    pack $f.new.rexpr -side top
    pack $f.new.expr -side top -fill x
    pack $f.new -side left -expand 1 -fill both

  pack $w.f -side top -expand 1 -fill both

  frame $w.button
  button $w.button.ok -text "Ok" -width 10 \
  	-command "do-create-wp-viewer $id"
  button $w.button.cancel -text "Cancel" -width 10 \
  	-command "do-cancel-wp-viewer $id"
  pack $w.button.ok -side left -expand 1
  pack $w.button.cancel -side left -expand 1
  pack $w.button -side top -fill x

  lappend Dap($dap,wpv-dialogs) $id
}
proc create-wp-viewer { dap rid } {
  global Dap Viewer viewercount

  set id $viewercount
  incr viewercount

  lappend Dap($dap,viewers) $id
  # puts stderr "create-wp-viewer $dap $rid"

  set w .wpv$id

  toplevel $w
  wm positionfrom $w program
  wm sizefrom $w program
  wm title $w "Watchpoint: $dap ($id)"
  wm maxsize $w 1152 900

  frame $w.frames -borderwidth 2 -relief groove
  frame $w.frames.title
  label $w.frames.title.rid -text rid -width 3
  label $w.frames.title.pid -text pid -width 4
  label $w.frames.title.type -text type -width 5
  label $w.frames.title.what -text what
  label $w.frames.title.value -text value

  pack $w.frames -side top -expand 1 -fill both
  pack $w.frames.title -side top -fill x
  pack $w.frames.title.rid -side left
  pack $w.frames.title.pid -side left
  pack $w.frames.title.type -side left
  pack $w.frames.title.what -side left
  pack $w.frames.title.value -side left -expand 1 -fill x

  frame $w.buttons

  button $w.buttons.add -text "Add" \
	-command "create-wp-dialog $dap $id" \
	-width 7
  button $w.buttons.update -text "Update" \
	-command "do-update-variables $id" \
	-width 7 \
	-state disabled
  button $w.buttons.revert -text "Revert" \
	-width 7 \
	-state disabled
  button $w.buttons.close -text "Close" \
	-command "do-close-viewer $id" \
	-width 7

  pack $w.buttons.add -side left -expand 1
  pack $w.buttons.update -side left -expand 1
  pack $w.buttons.close -side left -expand 1
  pack $w.buttons -side top -fill x

  set Viewer($id,dap) $dap
  set Viewer($id,win) $w
  set Viewer($id,frames) $w.frames
  set Viewer($id,rules) {}
  set Viewer($id,changed) {}

  add-wp-to-viewer $id $rid
}
proc add-wp-to-viewer { vid rid } {
  global Viewer Rule

  # puts stderr "adding wp to viewer: $vid $rid"
  set w $Viewer($vid,frames).r$rid
  lappend Viewer($vid,rules) $rid
  set dap $Viewer($vid,dap)
  lappend Viewer($vid,rules) $rid
  set Rule($dap,$rid,viewer) $vid

  frame $w
  label $w.rid -text $rid -width 3
  label $w.pid -width 4 -textvariable Rule($dap,$rid,pid)

  pack $w -side top -fill x
  pack $w.rid -side left
  pack $w.pid -side left

  set Viewer($vid,$rid,win) $w
  set Viewer($vid,$rid,exprs) {}
  set Viewer($vid,$rid,expr-count) 0

  if { [info exists Rule($dap,$rid,exprs)] } {
    tide-watchpoint-wp $dap $Rule($dap,$rid,pid) $Rule($dap,$rid,exprs)
  }
}
proc tide-watchpoint-wp { dap pid rid exprs } {
  global Rule Viewer

  # puts stderr "tide-watchpoint-wp: $dap $rid $pid $exprs"
  if { [info exists Rule($dap,$rid,viewer)] } {
    set vid $Rule($dap,$rid,viewer)

    foreach pair $exprs {
      set len [llength $pair]
      set expr [lrange $pair 0 [expr $len-2]]
      set val  [lindex $pair [expr $len-1]]

      set marked { }
      if { [info exists Viewer($vid,$rid,$expr,id)] } {
        set eid $Viewer($vid,$rid,$expr,id)
        set w $Viewer($vid,$rid,$eid,win)
      } else {
        set eid $Viewer($vid,$rid,expr-count)
	incr Viewer($vid,$rid,expr-count)
	set w $Viewer($vid,$rid,win).e$eid
	set Viewer($vid,$rid,$expr,id) $eid
	set Viewer($vid,$rid,$eid,win) $w

	if { [string match "var(*" $expr] } {
	  set type var
	  set end [expr [string length $expr] - 2]
	  set what [TCLstring [string range $expr 4 $end]]
	} elseif { [string match "eval(*" $expr] } {
	  set type expr
	  set end [expr [string length $expr] - 2]
	  set what [TCLstring [string range $expr 5 $end]]
	} else {
	  set type mixed
	  set what $expr
	}

	# puts stderr "added new expressions: $vid, $rid, $eid ($w)"

	lappend Viewer($vid,$rid,exprs) $eid
	frame $w

	label $w.type -text $type -width 5
	label $w.what -text "$what ="

	if { $type == "var" } {
	  entry $w.val -textvariable Viewer($vid,$rid,$eid,val)
	  bind $w.val <KeyPress> "+do-variable-changed $vid $rid $eid"
	} else {
	  label $w.val -textvariable Viewer($vid,$rid,$eid,val) \
		-borderwidth 2 -relief sunken
	}
	pack $w -side top -expand 1 -fill x
	pack $w.type -side left
	pack $w.what -side left
	pack $w.val -side left -expand 1 -fill x

	# We need to remember the window ids in order to change their
	# foreground color when their value changes!
	set Viewer($vid,$rid,$eid,windows) $w.type
	lappend Viewer($vid,$rid,$eid,windows) $w.what
	lappend Viewer($vid,$rid,$eid,windows) $w.val
      }
      set Viewer($vid,$rid,$eid,val) $val
      set Viewer($vid,$rid,$eid,value) $val
      lappend marked $eid
      foreach eid $Viewer($vid,$rid,exprs) {
        if { [lsearch $marked $eid] == -1 } {
          puts stderr "Destroying: $vid, $rid, $eid"
          # Expression is not used anymore!
          destroy $Viewer($vid,$rid,$eid,win)
          unset Viewer($vid,$rid,$eid,win)
          unset Viewer($vid,$rid,$eid,val)
          unset Viewer($vid,$rid,$expr,id)
          set idx [lsearch $Viewer($vid,$rid,exprs) $eid]
          set Viewer($vid,$rid,exprs) [lreplace $Viewer($vid,$rid,exprs) $idx $idx] 
        }
      }
    }
  }
}
proc set-change-mark { vid rid eid changed } {
  global Viewer

  if { $changed } {
    set color grey
  } else {
    set color black
  }
  foreach win $Viewer($vid,$rid,$eid,windows) {
    $win configure -foreground $color
  }
}

proc do-create-wp-viewer { id } {
  global Dialog

  set dap $Dialog($id,dap)
  set vid $Dialog($id,vid)
  set type $Dialog($id,type)
  puts stderr "Ok, creating new viewer."
  puts stderr "dap  = $dap"
  puts stderr "type = $type"
  if { $type == "new-var" } {
    set var $Dialog($id,var)
    tide-create-rule "watch($vid)" $dap all [list exec-state at stop] true \
	watch(var([TBstring $var])) persistent
    do-cancel-wp-viewer $id
  } elseif { $type == "new-expr" } {
    set expr $Dialog($id,expr)
    tide-create-rule "watch($vid)" $dap all [list exec-state at stop] true \
	watch(eval([TBstring $expr])) persistent
    do-cancel-wp-viewer $id
  } else {
    set rid [tide-get-selected-rule $id]
    if { $rid == "" } {
      set Dialog($id,msg) "Select a rule first."
    } else {
      if { $vid == 0 } {
        create-wp-viewer $dap $rid
      } else {
        add-wp-to-viewer $vid $rid
      }
      do-cancel-wp-viewer $id
    }
  }
}
proc do-cancel-wp-viewer { id } {
  global Dap Dialog

  tide-destroy-rule-list $id

  set dap $Dialog($id,dap)

  destroy $Dialog($id,win)
  unset Dialog($id,win)
  unset Dialog($id,dap)
  unset Dialog($id,type)
  unset Dialog($id,expr)
  unset Dialog($id,wrules)

  set idx [lsearch $Dap($dap,wpv-dialogs) $id]
  set Dap($dap,wpv-dialogs) [lreplace $Dap($dap,wpv-dialogs) $idx $idx]
}
proc do-variable-changed { vid rid eid } {
  global Viewer

  lappend Viewer($vid,changed) [list $rid $eid]
  $Viewer($id,win).buttons.update configure -state enabled
  $Viewer($id,win).buttons.revert configure -state enabled   
  set-change-mark $vid $rid $eid 1
}
proc do-revert-variables { vid } {
  global Viewer

  foreach pair $Viewer($vid,changed) {
    set rid [lindex $pair 0]
    set eid [lindex $pair 1]
    set-change-mark $vid $rid $eid 0
    set Viewer($vid,$rid,$eid,val) $Viewer($vid,$rid,$eid,value)
  }
  $Viewer($id,win).buttons.update configure -state disabled
  $Viewer($id,win).buttons.revert configure -state disabled  

  set Viewer($vid,changed) {}
}
proc do-update-variables { vid } {
  global Viewer

  foreach pair $Viewer($vid,changed) {
    set rid [lindex $pair 0]
    set eid [lindex $pair 1]
    puts stderr "change: $Viewer($vid,$rid,$eid,what) = $Viewer($vid,$rid,$eid,val)"
    set-change-mark $vid $rid $eid 0
  }
  $Viewer($id,win).buttons.update configure -state disabled
  $Viewer($id,win).buttons.revert configure -state disabled  
}

proc view-watchpoint { dap } {
  create-wp-dialog $dap 0
}

proc tide-dap-connected-wvp { dap info procs } {
  global Dap Viewers

  set Dap($dap,viewers) {}
}
proc tide-dap-disconnected-bv { dap } {
  global Dap Viewer

  foreach id $Dap($dap,wpv-dialogs) {
    do-cancel-dialog $id
  }

  foreach rid $Dap($dap,viewers) {
    destroy $Viewer($dap,$rid,win)
    unset Viewer($dap,$rid,win)
  }
  unset Dap($dap,viewers)
}
proc tide-rule-destroyed-wpv { dap rid } {
  global Dap Rule Viewer Viewers

  if { [info exists Rule($dap,$rid,viewer)] } {
    set id [$Rule($dap,$rid,viewer)]
    destroy $Viewer($id,$rid,win)
    set idx [lsearch $Viewer($id,rules) $rid]
    set Viewer($id,rules) [lreplace $Viewer($id,rules) $idx $idx] 
    if { [llength $Viewer($id,rules)] == 0 } {
       do-close-viewer $id
    }
  }
}

proc tide-ack-event-wpv { event } {
  global Dap

  if { [regexp {create-rule\(watch\(([0-9]+)\),([^,]+),} $event m vid dap] } {
    set idx [string last "," $event]
    set end [expr [string length $event]-2]
    set rid [string trim [string range $event [expr $idx+1] $end]]
    if { $vid == 0 } {
      create-wp-viewer $dap $rid
    } else {
      add-wp-to-viewer $vid $rid
    }
  }
}

set Viewers { }
set Tide(actions) 1
set dialogcount 1
set viewercount 1

wm withdraw .
source "tide-modules.tcl"
tide-init "Rule viewer" { 
	daps
	processes
	event-rules
	current-port 
	ui-rule-list
}
