proc create-rule-viewer { dap } {
  global Viewer Dap Rule

  set w .bp$dap
  set Dap($dap,viewer) 1
  set Viewer($dap,win) $w
  set Viewer($dap,pids) all
  set Viewer($dap,cur-rule) ""
  set Viewer($dap,changed) 0

  toplevel $w
  wm positionfrom $w program
  wm sizefrom $w program
  wm title $w "Rule Viewer: $dap"
  wm maxsize $w 1152 900
  
  frame $w.top
  create-rule-frame $dap $w.top.rules
  create-pids-frame $dap $w.top.pids
  create-port-frame $dap $w.port
  create-cond-frame $dap $w.cond
  create-acts-frame $dap $w.acts

  pack $w.top.rules -side left -expand 1 -fill both
  pack $w.top.pids -side left -expand 1 -fill both
  pack $w.top -side top -fill both -expand 1
  pack $w.port -side top -fill both
  pack $w.cond -side top -fill both
  pack $w.acts -side top -expand 1 -fill both

  update-viewer $dap
}
proc create-rule-frame { dap w } {
  global Dap Viewer Rule

  frame $w -relief groove -borderwidth 2
  label $w.label -text "Observation points:"
  frame $w.list
  listbox $w.list.box -width 18 -height 6 \
		-xscrollcommand "$w.list.y set" \
		-yscrollcommand "$w.x set"
  bind $w.list.box <ButtonPress-1> "change-cur-rule $dap %x %y"
  scrollbar $w.list.y -command "$w.list.box yview" -orient vert
  scrollbar $w.x -command "$w.list.box xview" -orient hor

  pack $w.label -fill x
  pack $w.list.box -side left -expand 1 -fill both
  pack $w.list.y -side left -fill y
  pack $w.list -side top -expand 1 -fill both
  pack $w.x -side top -fill x

  set Viewer($dap,wrules) $w.list.box

  foreach rid $Dap($dap,rules) {
    set text [format "%3d %s" $rid [lindex $Rule($dap,$rid,port) 0]]
    $Viewer($dap,wrules) insert end $text
  }

  frame $w.buttons
  button $w.buttons.create \
	-text "Create" \
	-command "do-create-rule $dap" \
	-width 5
  button $w.buttons.modify \
	-text "Modify" \
	-command "do-modify-rule $dap" \
	-width 5
  button $w.buttons.destroy \
	-text "Destroy" \
	-command "do-destroy-rule $dap" \
	-width 5
  pack $w.buttons.create -side left -expand 1
  pack $w.buttons.modify -side left -expand 1
  pack $w.buttons.destroy -side left -expand 1

  set Viewer($dap,wmodify) $w.buttons.modify

  pack $w.buttons -side top -fill x
}
proc create-port-frame { dap w } {
  global Dap Viewer

  frame $w -borderwidth 2 -relief groove

  set type [lindex $Dap($dap,ports) 0]
  set Viewer($dap,port) $type

  frame $w.header
  label $w.header.label -text "Port:"
  pack $w.header.label -side left -expand 1 -fill x
  pack $w.header -fill x

  #  frame $w.when
  #  label $w.when.label -text "When:"
    radiobutton $w.header.at -text "at" \
  	-variable Viewer($dap,port,when) \
  	-value "at" \
  	-command "has-changed $dap"
    radiobutton $w.header.before -text "before" \
  	-variable Viewer($dap,port,when) \
  	-value "before" \
  	-command "has-changed $dap"
    radiobutton $w.header.after -text "after" \
  	-variable Viewer($dap,port,when) \
  	-value "after" \
  	-command "has-changed $dap"

  #  pack $w.when.label -side left
    pack $w.header.at -side left
    pack $w.header.before -side left
    pack $w.header.after -side left
  #  pack $w.when -side top -fill x
  button $w.header.restore -text "Restore" -command "do-restore-rule $dap"
  pack $w.header.restore -side left
  set Viewer($dap,wrestore) $w.header.restore

    if { $Dap($dap,port,exec-state) } {
      frame $w.es
      set Viewer($dap,port,exec-state) stop
      radiobutton $w.es.exec-state -text "Exec state:" \
  		-value exec-state \
  		-variable Viewer($dap,port) \
  		-command "has-changed $dap"
      pack $w.es.exec-state -side left
      radiobutton $w.es.all -text "All" \
  		-value all \
  		-variable Viewer($dap,port,exec-state) \
  		-command "has-changed $dap"
      pack $w.es.all -side left
      if { $Dap($dap,ec,stop) } {
        radiobutton $w.es.stop -text "Stop" \
  		-variable Viewer($dap,port,exec-state) \
  		-value "stop" \
  		-command "has-changed $dap"
        pack $w.es.stop -side left
      }
      if { $Dap($dap,ec,single-step) } {
        radiobutton $w.es.single-step -text "Single step" \
  		-variable Viewer($dap,port,exec-state) \
  		-value "single-step" \
  		-command "has-changed $dap"
        pack $w.es.single-step -side left
      }
      if { $Dap($dap,ec,step-over) } {
        radiobutton $w.es.step-over -text "Step over" \
  		-variable Viewer($dap,port,exec-state) \
  		-value "step-over" \
  		-command "has-changed $dap"
        pack $w.es.step-over -side left
      }
      if { $Dap($dap,ec,run) } {
        radiobutton $w.es.run -text "Run" \
  		-variable Viewer($dap,port,exec-state) \
  		-value "run" \
  		-command "has-changed $dap"
        pack $w.es.run -side left
      }
      if { $Dap($dap,ec,run-until-parent) } {
        radiobutton $w.es.run-until-parent -text "Run until parent" \
  		-variable Viewer($dap,port,exec-state) \
  		-value "run-until-parent" \
  		-command "has-changed $dap"
        pack $w.es.run-until-parent -side left
      }
      pack $w.es -side top -fill x
    }
  if { $Dap($dap,port,always) } {
    radiobutton $w.always -text "Always" \
  	-variable Viewer($dap,port) \
  	-value always \
  	-command "has-changed $dap"
    pack $w.always -anchor w
  }
    if { $Dap($dap,port,location) } {
      frame $w.loc
      frame $w.loc.top
      frame $w.loc.bottom

      radiobutton $w.loc.top.radio -text "Location:" \
  		-variable Viewer($dap,port) \
  		-value location \
  		-command "has-changed $dap"
      entry $w.loc.top.module -textvariable Viewer($dap,port,module)

      label $w.loc.bottom.l1 -text "From:"
      entry $w.loc.bottom.sl -textvariable Viewer($dap,port,start-line) -width 5
      entry $w.loc.bottom.sc -textvariable Viewer($dap,port,start-col) -width 3
      label $w.loc.bottom.l2 -text "To:"
      entry $w.loc.bottom.el -textvariable Viewer($dap,port,end-line) -width 5
      entry $w.loc.bottom.ec -textvariable Viewer($dap,port,end-col) -width 3

      bind $w.loc.top.module <KeyPress> "+has-changed $dap"
      bind $w.loc.bottom.sl <KeyPress> "+has-changed $dap"
      bind $w.loc.bottom.sc <KeyPress> "+has-changed $dap"
      bind $w.loc.bottom.el <KeyPress> "+has-changed $dap"
      bind $w.loc.bottom.ec <KeyPress> "+has-changed $dap"

      pack $w.loc.top.radio -side left
      pack $w.loc.top.module -side left -expand 1 -fill x
      pack $w.loc.top -side left -expand 1 -fill x
      pack $w.loc.bottom.l1 -side left
      pack $w.loc.bottom.sl -side left -expand 1 -fill x 
      pack $w.loc.bottom.sc -side left -expand 1 -fill x
      pack $w.loc.bottom.l2 -side left
      pack $w.loc.bottom.el -side left -expand 1 -fill x
      pack $w.loc.bottom.ec -side left -expand 1 -fill x
      pack $w.loc.bottom -side left -expand 1 -fill x
      pack $w.loc -fill x
    }
    if { $Dap($dap,port,call) || $Dap($dap,port,retry) ||
         $Dap($dap,port,fail) || $Dap($dap,port,succeed) } {
      frame $w.fp
      frame $w.fp.top
      frame $w.fp.bottom

      label $w.fp.top.label -text "Function/predicate:"
      entry $w.fp.top.entry -textvariable $Dap($dap,port,fp)

      set f $w.fp.bottom
      if { $Dap($dap,port,call) } {
        radiobutton $w.call -text "Call" \
  		-value call \
  		-variable Viewer($dap,port) \
  		-command "has-changed $dap"
        pack $w.call -side top -anchor w
      }
      if { $Dap($dap,port,retry) } {
        radiobutton $w.retry -text "Retry/backtrack" \
  		-value retry \
  		-variable Viewer($dap,port) \
  		-command "has-changed $dap"
        pack $w.retry -side top -anchor w
      }
      if { $Dap($dap,port,fail) } {
        radiobutton $w.fail -text "Fail" \
  		-value fail \
  		-variable Viewer($dap,port) \
  		-command "has-changed $dap"
        pack $w.fail -side top -anchor w
      }
      if { $Dap($dap,port,succeed) } {
        radiobutton $w.succeed -text "Succeed" \
  		-value succeed \
  		-variable Viewer($dap,port) \
  		-command "has-changed $dap"
        pack $w.succeed -side top -anchor w
      }
      pack $w.fp.top.label -side left
      pack $w.fp.top.entry -side left
      pack $w.fp.top -side top -expand 1 -fill x
      pack $w.fp.bottom -side top -expand 1 -fill x
      pack $w.fp -side top -fill x
    }
  if { $Dap($dap,port,variable) } {
    frame $w.var
    radiobutton $w.var.radio -text "Variable change:" \
  	-variable Viewer($dap,port) \
  	-value "variable" \
  	-command "has-changed $dap"
    entry $w.var.entry -textvariable Viewer($dap,port,variable)
    bind $w.var.entry <KeyPress> "+has-changed $dap"
    pack $w.var.radio -side left
    pack $w.var.entry -side left
    pack $w.var -side top -fill x
  }
  if { $Dap($dap,port,exception) } {
    frame $w.exception
    radiobutton $w.exception.radio -text "Exception:" \
  	-variable Viewer($dap,port) \
  	-value exception \
  	-command "has-changed $dap"
    entry $w.exception.entry -textvariable Viewer($dap,port,exception)
    bind $w.exception.entry <KeyPress> "+has-changed $dap"
    pack $w.exception.radio -side left
    pack $w.exception.entry -side left
    pack $w.exception -side top -fill x
  }
  if { $Dap($dap,port,send) } {
    frame $w.send
    radiobutton $w.send.radio -text "Send:" \
  	-variable Viewer($dap,port) \
  	-value send \
  	-command "has-changed $dap"
    entry $w.send.entry -textvariable Viewer($dap,port,send)
    bind $w.send.entry <KeyPress> "+has-changed $dap"
    pack $w.send.radio -side left
    pack $w.send.entry -side left
    pack $w.send -side top -fill x
  }
  if { $Dap($dap,port,receive) } {
    frame $w.receive
    radiobutton $w.receive.radio -text "Receive:" \
  	-variable Viewer($dap,port) \
  	-value receive \
  	-command "has-changed $dap"
    entry $w.receive.entry -textvariable Viewer($dap,port,receive)
    bind $w.receive.entry <KeyPress> "+has-changed $dap"
    pack $w.receive.radio -side left
    pack $w.receive.entry -side left
    pack $w.receive -side top -fill x
  }
  if { $Dap($dap,port,process-creation) } {
    frame $w.pc
    radiobutton $w.pc.radio -text "Process Creation" \
  	-variable Viewer($dap,port) \
  	-value process-creation \
  	-command "has-changed $dap"
    pack $w.pc.radio -side left
    pack $w.pc -side top -fill x
  }
  if { $Dap($dap,port,process-destruction) } {
    frame $w.pd
    radiobutton $w.pd.radio -text "Process Destruction" \
  	-variable Viewer($dap,port) \
  	-value process-destruction \
  	-command "has-changed $dap"
    pack $w.pd.radio -side left
    pack $w.pd -side top -fill x
  }
}
proc create-cond-frame { dap f } {
  global Dap Viewer

  frame $f -borderwidth 2 -relief groove
  label $f.label -text "Condition:"
  pack $f.label -side top -fill x

  frame $f.expr
#  frame $f.expr.dummy -width 24
  entry $f.expr.e  -textvariable Viewer($dap,cond)

#  pack $f.expr.dummy -side left
  pack $f.expr.e -side left -expand 1 -fill x
  pack $f.expr -side top -expand 1 -fill both
}
proc create-acts-frame { dap w } {
  global Dap Viewer

  frame $w -borderwidth 2 -relief groove
  label $w.label -text "Actions:"
  pack $w.label -side top -fill x

  set Viewer($dap,acts) ""
  frame $w.f
  text $w.f.acts \
	-xscrollcommand "$w.x set" \
	-yscrollcommand "$w.f.y set" \
	-borderwidth 2 -relief sunken \
	-width 24 -height 8

  scrollbar $w.f.y -orient vert -command "$w.f.acts yview"
  scrollbar $w.x -orient hor -command "$w.f.acts xview"
  set Viewer($dap,wacts) $w.f.acts

  pack $w.f -side top -expand 1 -fill both
  pack $w.f.acts -side left -expand 1 -fill both
  pack $w.f.y -side left -fill y
  pack $w.x -side top -fill x
}
proc create-pids-frame { dap w } {
  tide-ui-process-list-create $dap $w
}
proc update-viewer { dap } {
  global Dap Viewer Rule

  set cur $Viewer($dap,cur-rule)
  if { $cur != "" } {
    set Viewer($dap,when) $Rule($dap,$cur,when)
      set port $Rule($dap,$cur,port)

      puts stderr "update port widgets: $port"

      set type [lindex $port 0]
      set when [lindex $port 1]

      set Viewer($dap,port) $type
      set Viewer($port,when) $when

      switch $type {
         exec-state	{ set Viewer($dap,port,exec-state) [lindex $port 2] 
    		}
         location	{ set Viewer($dap,port,module) [lindex $port 2]
    		  set Viewer($dap,port,start-line) [lindex $port 3]
    		  set Viewer($dap,port,start-col)  [lindex $port 4]
    		  set Viewer($dap,port,end-line)   [lindex $port 5]
    		  set Viewer($dap,port,end-col)	   [lindex $port 6]
    		}
         call	-
         retry	-
         fail	-
         succeed	{ set Viewer($dap,port,fp) [lindex $port 2]
    		}
         variable	{ set Viewer($dap,port,var) [lindex $port 2]
    		}
         exception	{ set Viewer($dap,port,exception) [lindex $port 2] 
    		}
         send	{ set Viewer($dap,port,send) [lindex $port 2]
    		}
         receive	{ set Viewer($dap,port,receive) [lindex $port 2]
    		}
      }
      set cond $Rule($dap,$cur,cond)

      if { $cond == "always" } {
        set Viewer($dap,cond) "always"
      } else {
        set Viewer($dap,cond) $cond
      }
      set acts $Rule($dap,$cur,acts)

      $Viewer($dap,wacts) delete 1.0 end
      $Viewer($dap,wacts) insert 1.0 $acts  
    tide-ui-select-processes $dap $Rule($dap,$cur,pids)
  }
  update-buttons $dap
}
proc update-buttons { dap } {
  global Viewer

  if { $Viewer($dap,changed) && $Viewer($dap,cur-rule) != "" } {
    $Viewer($dap,wmodify) configure -state normal
    $Viewer($dap,wrestore) configure -state normal     
  } else {
    $Viewer($dap,wmodify) configure -state disabled
    $Viewer($dap,wrestore) configure -state disabled   
  }
}
proc get-port { dap } {
  global Viewer

  set port $Viewer($dap,port)
  set when $Viewer($dap,when)
  set data {}

  set mod  $Viewer($dap,port,module)
  if { $mod == {} } {
    set mod ""
  }

  set line $Viewer($dap,port,line)
  set col  $Viewer($dap,port,col)

  switch $port {
    exec-state		{ set data $Viewer($dap,port,exec-state) }
    location		{ set data [list $Viewer($dap,port,module) \
			$Viewer($dap,port,start-line) $Viewer($dap,start-col)
			$Viewer($dap,port,end-line)   $Viewer($dap,end-col)]
			}
    call		-
    retry		-
    fail		-
    succeed		{ set data $Viewer($dap,port,fp) }
    variable		{ set data $Viewer($dap,port,variable) }
    exception		{ set data $Viewer($dap,port,exception) }
    send		{ set data $Viewer($dap,port,send) }
    receive		{ set data $Viewer($dap,port,receive) }
  }
  return $port
}
proc get-cond { dap } {
  global Viewer

  return [string trim $Viewer($dap,cond)]
}
proc get-acts { dap } {
  global Viewer

  set acts {}
  return [string trim [$Viewer($dap,wacts) get 1.0 end]]
}
proc get-selected-procs { dap } {
  global Viewer

  return $Viewer($dap,pids)
}
proc get-selected-rule { dap } {
  global Dap Viewer

  if { $Dap($dap,viewer) } {
    return [$Viewer($dap,wrules) curselection]
  }
  return ""
}
proc clear-rule-selection { dap } {
  global Dap Viewer

  if { $Dap($dap,viewer) } {
    $Viewer($dap,wrules) selection clear 0 end
  }
}
proc change-cur-rule { dap x y } {
  global Dap Viewer

  set w $Viewer($dap,wrules)
  set idx [$w nearest $y]
  $w selection clear 0 end
  $w selection set $idx

  set rid [lindex $Dap($dap,rules) $idx]
  if { $Viewer($dap,cur-rule) != $rid } {
    set Viewer($dap,changed) 0
    set Viewer($dap,cur-rule) $rid
    update-viewer $dap
  }
}
proc has-changed { dap } {
  global Viewer

  if { $Viewer($dap,changed) == 0 } {
    set Viewer($dap,changed) 1
    update-buttons $dap
  }
}

proc do-process-selected-bv { dap args } {
  # clear-rule-selection $dap  
}
proc do-create-rule { dap } {
  set procs [get-selected-procs $dap]
  set port [get-port $dap]
  set cond [get-cond $dap]
  set acts [get-acts $dap]
  set lifetime persistent

  if { $procs != {} } {
    tide-create-rule rule $dap $procs $port $cond $acts $lifetime
  }
}
proc do-modify-rule { dap } {
  set rid [get-selected-rule $dap]
  set procs [get-selected-procs $dap]

  if { $rid != "" && $procs != {} } {
    set port [get-port $dap]
    set cond [get-cond $dap]
    set acts [get-acts $dap]
    set lifetime persistent

    tide-modify-rule $rid $dap $procs $port $cond $acts $lifetime
  }
}
proc do-destroy-rule { dap } {
  set rid [get-selected-rule $dap]

  if { $rid != "" } {
    tide-destroy-rule $dap $rid
  }
}
proc do-restore-rule { dap } {
  set rid [get-selected-rule $dap]

  if { $rid != "" } {
    update-viewer $dap
  }
}

proc view-rules { dap } {
  global Dap Viewers Viewer

  if { [lsearch $Viewers $dap] == -1 } {
    lappend Viewers $dap
    set Viewer($dap,pid-selection)	"all"
    set Viewer($dap,port)		"line"
    create-rule-viewer $dap
    if { $Dap($dap,current-port) != "" } {
      tide-current-port-bv $dap $Dap($dap,current-pids) $Dap($dap,current-port)
    }
  } else {
    raise $Viewer($dap,win)
  }
}

proc tide-dap-connected-bv { dap info procs } {
  global Dap

  set Dap($dap,viewer) 0
}
proc tide-dap-disconnected-bv { dap } {
  global Dap Viewers Viewer

  set index [lsearch $Viewers $dap]
  if { $index != -1 } {
    unset Dap($dap,viewer)
    set Viewers [lreplace $Viewers $index $index]
    destroy $Viewer($dap,win)
    unset Viewer($dap,win)
  }
}
proc tide-rule-created-bv { dap rid pids port cond acts life } {
  global Dap Viewer

  if { $Dap($dap,viewer) } {
    $Viewer($dap,wrules) insert end "[format "%3d: %s" $rid [lindex $port 0]]"    
    if { $Viewer($dap,cur-rule) == $rid } {
      update-viewer $dap
    }
  }  
}
proc tide-rule-destroyed-bv { P rid } {
  global Dap Viewer

  if { $Dap($dap,viewer) } {
    set idx $Dap($dap,rules) $rid 
    if { $idx != "" } {
      $Viewer($dap,wrules) delete $idx $idx
    }
  }
}
proc tide-current-port-bv { dap pids port } {
  global Dap Viewer

  set type [lindex $port 0]
  set Viewer($dap,port) $type
  set Viewer($dap,port,when) [lindex $port 1]

  if { $Dap($dap,viewer) } {
    switch $type {
      exec-state	{ set Viewer($dap,port,exec-state) [lindex $port 2] }
      location		{ set Viewer($dap,port,module)	   [lindex $port 2]
			  set Viewer($dap,port,start-line) [lindex $port 3]
			  set Viewer($dap,port,start-col)  [lindex $port 4]
			  set Viewer($dap,port,end-line)   [lindex $port 5]
			  set Viewer($dap,port,end-col)	   [lindex $port 6]
			}
      call		-
      retry		-
      fail		-
      succeed		{ set Viewer($dap,port,fp) [lindex $port 2] }
      variable		{ set Viewer($dap,port,variable) [lindex $port 2] }
      exception		{ set Viewer($dap,port,exception) [lindex $port 2] }
      send		{ set Viewer($dap,port,send) [lindex $port 2] }
      receive		{ set Viewer($dap,port,receive) [lindex $port 2] }
    }
    # Viewer changed
  }
}

set TOOL "rule-viewer"
set Viewers { }
set Tide(actions) 1

wm withdraw .
source "tide-modules.tcl"
tide-init "Rule viewer" { 
	daps
	processes
	event-rules
	current-port 
	ui-process-list
}
