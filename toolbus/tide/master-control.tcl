proc create-window { } {
  wm positionfrom . program
  wm sizefrom . program
  wm maxsize . 1152 900
  wm title . "T.I.D.E."
  wm geometry . 329x220

    frame .menu -borderwidth 2 -relief flat
    menubutton .menu.tide -menu .menu.tide.m -text "Tide"
    menu .menu.tide.m
    .menu.tide.m add command -label "Shutdown" -command "do-shutdown"
    pack append .menu \
  	.menu.tide {left frame center}  

  frame .middle

    frame .middle.daps -borderwidth 2 -relief groove
    label .middle.daps.label -text "Debug adapters:"
    frame .middle.daps.list -borderwidth 0
    listbox .middle.daps.list.box -borderwidth 2 -relief sunken \
  	  -width 1 \
  	  -height 1 \
  	  -yscrollcommand ".middle.daps.list.vert set" \
  	  -xscrollcommand ".middle.daps.hor.bar set" \
  	  -selectmode single \
  	  -exportselection 0
    bind .middle.daps.list.box <ButtonPress-1> "select-dap %x %y"

    scrollbar .middle.daps.list.vert -command ".middle.daps.list.box yview" -orient vert

    pack append .middle.daps.list \
  	.middle.daps.list.box {left frame center expand fill} \
  	.middle.daps.list.vert {left frame center filly}

    frame .middle.daps.hor -borderwidth 0
    scrollbar .middle.daps.hor.bar -command ".middle.daps.list.box xview" -orient hor
    frame .middle.daps.hor.dummy -width 22 -height 20
   
    pack append .middle.daps.hor \
   	.middle.daps.hor.bar {left frame center expand fill} \
  	.middle.daps.hor.dummy {left frame center}
    
    pack append .middle.daps \
  	.middle.daps.label {top frame center fillx} \
  	.middle.daps.list {top frame center expand fill} \
  	.middle.daps.hor {top frame center fillx}
    frame .middle.tools -borderwidth 2 -relief groove
    label .middle.tools.label -text "Tools:"

    pack append .middle.tools \
  	.middle.tools.label {top frame center fillx}
  
  pack append .middle \
	.middle.daps {left frame center expand fill} \
	.middle.tools {left frame center filly}

  pack append . \
	.menu {top frame center fillx} \
	.middle { top frame center expand fill }
}
proc select-dap { x y } {
  set w .middle.daps.list.box

  set idx [$w nearest $y]
  $w selection clear 0 end
  $w selection set $idx
  update-tool-status  
}
proc get-selected-dap { } {
  global Daps

  set w .middle.daps.list.box

  set sel [$w curselection]
  if { $sel != "" } {
    return [lindex $Daps $sel]
  }
  return ""  
}

proc update-dap-list {daps} {
  global Dap

  set w .middle.daps.list.box

  puts stderr "update-dap-list: $daps"
  set el ""
  set sel [$w curselection]
  if { $sel != "" } {
    set el [$w get [$w curselection]]
  }

  $w delete 0 end
  set i 0
  set idx ""
  foreach dap $daps {
    $w insert end $dap
    if { $dap == $el } {
      set idx $i
    }
    incr i
  }
  if { $idx != "" } {
    $w selection set $idx
  } else {
    if { [llength $daps] != 0 } {
      $w selection set 0
    }
  }
}
proc update-tool-status { } {
  global Tools Tool

  set dap [get-selected-dap]
  foreach tool $Tools {
    if { $dap == "" } {
      $Tool($tool,button) configure -state disabled
    } else {
      $Tool($tool,button) configure -state normal
    }
  }
}
proc new-tool { Name tool event } {
  global Tools Tool

  set name [TCLstring $Name]
  set w .middle.tools

  set Tool($name,event) $event
  set Tool($name,tool) $tool

  foreach tool $Tools {
    destroy $Tool($tool,button)
  }

  lappend Tools $name

  set Tools [lsort $Tools]
  set i 0
  foreach tool $Tools {
    button $w.button$i -text $tool -command "do-activate \{$tool\}"
    pack $w.button$i -fill x
    set Tool($tool,button) $w.button$i
    incr i
  }
  update-tool-status
}
proc do-activate { name } {
  global Tool

  set tool $Tool($name,tool)
  set event $Tool($name,event)
  set dap [get-selected-dap]
  if { $dap != "" } {
    TBpost "button($tool,$event,$dap)"
  }
}
proc do-shutdown {} {
  TBsend "snd-event(tide-shutdown)"
}

proc tide-dap-connected-master { dap info procs } {
  global Daps

  update-dap-list $Daps
  update-tool-status
}
proc tide-dap-disconnected-master { dap } {
  global Daps

  set index [lsearch $Daps $dap]
  set daps [lreplace $Daps $index $index]
  update-dap-list $daps
  update-tool-status
}

# procedure: BindSSL, adjust binding for single selection listbox
proc BindSSL { Box } {
  global tk_version

 bind $Box <1> {updateButtons}
 if { $tk_version == "3.6" } {
    bind $Box <B1-Motion> {%W select from [%W nearest %y]; updateButtons}
    bind $Box <Shift-B1-Motion> {%W select from [%W nearest %y]; updateButtons}
    bind $Box <Shift-Button-1> {%W select from [%W nearest %y]; updateButtons}
  } else {
    $Box configure -selectmode single
  }
}

set Tools {}
source "tide-modules.tcl"
tide-init "Watchpoint viewer" {
	daps
}
create-window
