proc create-watchpoint-viewer { dap } {
  global Dap Viewer

  set Dap($dap,viewer) 1
  set w .d$dap
  set Viewer($dap,win) $w

  toplevel $w
  wm positionfrom $w program
  wm sizefrom $w program
  wm title $w "Watchpoints: $dap"
  wm maxsize $w 1152 900

  frame $w.main 
  frame $w.main.labels
  label $w.main.labels.oid -text "OID:" -width 4
  pack $w.main.labels.oid -side left

  label $w.main.labels.expr -text "Expression:" -width 16 -anchor w
  pack $w.main.labels.expr -side left

  label $w.main.labels.value -text "Value:" -width 28 -anchor w
  pack $w.main.labels.value -side left -expand 1 -fill x

  pack $w.main.labels -side top -fill x
  pack $w.main -fill both

  # Add all existing observation points
  foreach oid $Dap($dap,opoints) {
    set pids $OPoint($dap,$oid,pids)
    set port $OPoint($dap,$oid,port)
    set cond $OPoint($dap,$oid,cond)
    set acts $OPoint($dap,$oid,acts)
    tide-observation-point-set-wpv $dap $oid $pids $port $cond $acts
  }
}

proc tide-dap-connected-wpv { dap info } {
  global Dap

  set Dap($dap,viewer) 0
}
proc tide-dap-disconnected-wpv { dap } {
  global Dap Viewer

  foreach oid $Dap($dap,opoints) {
  }
  if { $Dap($dap,viewer) } {
    destroy $Viewer($dap,win)
  }

  unset Dap($dap,viewer)
}

proc tide-observation-point-set-wpv { dap oid pids port cond acts } { 
  global Dap Viewer OPoint

  puts "*** tide-observation-point-set-wpv: $acts"
  set count 0

  set OPoint($dap,$oid,exprs) {}
}
proc tide-observation-point-cleared-wpv { dap oid } {
  global OPoint Viewer

  if { $OPoint($dap,$oid,viewer) == "line" } {
    foreach expr $OPoint($dap,$oid,exprs) {
      set id $oid-$expr
      destroy $Viewer($dap,$id,win)
      unset $Viewer($dap,$id,win)
      unset $Viewer($dap,$id,woid)
      unset $Viewer($dap,$id,wexpr)
      unset $Viewer($dap,$id,wvalue)
    }
  } elseif { $OPoint($dap,$oid,viewer) == "standalone" } {
    destroy $Viewer($dap,$oid,win)
    unset Viewer($dap,$oid,win)
  }
}
proc tide-watchpoint-wpv { dap oid pids expr value } {
  global OPoint

  puts stderr "tide-watchpoint-wpv: $dap $oid $pids $expr $value"
  if { ![info exists OPoint($dap,$oid,exprs)] } {
    set OPoint($dap,$oid,exprs) {}
  }

  if { [lsearch $OPoint($dap,$oid,exprs) $expr] == -1 } {
    add-watchpoint $dap $oid $expr
  }
  set OPoint($dap,$oid-$expr,value) $value
}

proc add-watchpoint { dap oid expr } {
  global OPoint Viewer

  set id $oid-$expr
  lappend OPoint($dap,$oid,exprs) $expr

  set OPoint($dap,$id,viewer) line
  set w $Viewer($dap,win).o$id
  set woid  $w.oid 
  set wexpr $w.expr 
  set wval  $w.val

  frame $w
  label $woid -text $oid -width 4 -anchor e
  label $wexpr -text $expr -width 16 -anchor w
  entry $wval -textvariable OPoint($dap,$id,value)

  pack $w -side top -fill x
  pack $woid -side left
  pack $wexpr -side left
  pack $wval -side left -expand 1 -fill x

  set Viewer($dap,$id,win)    $w
  set Viewer($dap,$id,woid)   $woid
  set Viewer($dap,$id,wexpr)  $wexpr
  set Viewer($dap,$id,wvalue) $wval
}
proc show-watchpoint-viewer { dap } {
  global Viewers Viewer

  if { [lsearch $Viewers $dap] == -1 } {
    lappend Viewers $dap
    create-watchpoint-viewer $dap
  } else {
    raise $Viewer($dap,win)
  }    
}

wm withdraw .
set Viewers {}
source tide-modules.tcl

tide-init "Watchpoint viewer" {
  daps
  observation-points
}

