proc tide-init-exec-state { } {
  tide-init-modules { daps processes }
}
proc tide-process-created-es { dap pid name } {
  global Proc

  if { ![info exists Proc($dap,$pid,es)] } {
    set Proc($dap,$pid,es) unknown
  }
}
proc tide-process-destroyed-es { dap pid } {
  global Proc

  unset Proc($dap,$pid,es)
}

proc tide-watchpoint-es { dap pid rid exprs } {
  global Proc

  if { [llength $exprs] == 1 } {
    set expr [lindex $exprs 0]
    if { [lindex $expr 0] == "exec-state" } {
      set es [lindex $expr 1]
      set Proc($dap,$pid,es) $es
      tide-call exec-state $dap $pid $es
    }
  }
}

proc tide-watch-exec-state { dap } {
  global Dap

  if { ![info exists Dap($dap,es-rid)] } {
    tide-create-rule es $dap all {exec-state at all} "" watch(exec-state) persistent
    set Dap($dap,es-rid) ""
  }
}
proc tide-unwatch-exec-state { dap } {
  global Dap

  if { [info exists Dap($dap,es-rid)] } {
    tide-destroy-rule $dap $Dap($dap,es-rid)
  }
}

proc tide-ack-event-es { event } {
  global Dap

  if { [regexp {create-rule\(es,([^,]+),} $event m dap] } {
    set idx [string last "," $event]
    set end [expr [string length $event]-2]
    set Dap($dap,es-rid) [string trim [string range $event [expr $idx+1] $end]]
  }
}
proc tide-rule-destroyed-es { dap rid } {
  global Dap

  if { [info exists Dap($dap,es-rid)] && Dap($dap,es-rid) == $rid } {
    unset Dap($dap,es-rid)
  }
}
