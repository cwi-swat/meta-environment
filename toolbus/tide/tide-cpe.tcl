proc tide-init-cpe { } {
  tide-init-modules { daps processes }
}
proc tide-dap-connected-cpe { dap info procs } {
  global Dap

  set Dap($dap,cpe-rid) ""
}
proc tide-dap-disconnected { dap } {
  global Dap

  unset Dap($dap,cpe-rid)
}
proc tide-process-created-cpe { dap pid name } {
  global Proc

  set Proc($dap,$pid,cpe-port) ""
}
proc tide-process-destroyed-cpe { dap pid } {
  global Proc

  unset Proc($dap,$pid,cpe-port)
}

proc tide-watchpoint-cpe { dap pids rid exprs } {
  global Proc

  if { [llength $exprs] == 1 } {
    set expr [lindex $exprs 0]
    if { [lindex $expr 0] == "cpe" } {
      set val [lindex $expr 1]
      set port [TCLport [concat $val]]

      foreach pid $pids {
        set Proc($dap,$pid,cpe-port) $port

        tide-call cpe $dap $pid $port
      }
    }
  }
}

proc tide-watch-cpe { dap pids port } {
  global Dap

  tide-unwatch-cpe $dap

  tide-create-rule cpe $dap $pids $port true watch(cpe) persistent
}
proc tide-unwatch-cpe { dap } {
  global Dap

  if { $Dap($dap,cpe-rid) != "" } {
    tide-destroy-rule $dap $Dap($dap,cpe-rid)
  }
}
proc tide-ack-event-cpe { event } {
  global Dap

  if { [regexp {create-rule\(cpe,([^,]+),} $event m dap] } {
    set idx [string last "," $event]
    set end [expr [string length $event]-2]
    set Dap($dap,cpe-rid) [string trim [string range $event [expr $idx+1] $end]]
  }
}
