proc tide-init-processes { } {
  puts stderr "tide-init-processes called"

  tide-init-modules { daps event-rules }
}
proc tide-dap-connected-processes { dap procs info } {
  global Dap

  set Dap($dap,pids) { }
  foreach proc $procs {
    set pid [lindex $proc 0]
    set name [lindex $proc 1]
    process-created $dap $pid [TBstring $name]
  }
  tide-create-rule pc $dap all {process-creation at} \
				true watch(process-name) persistent
  tide-create-rule pd $dap all {process-destruction at} \
				true watch(process-name) persistent
}
proc tide-dap-disconnected-processes { dap } {
  global Dap

  unset Dap($dap,pids)
}
proc tide-watchpoint-procs { dap pid rid exprs } {
  global Dap

  if { [info exists Dap($dap,pc-rid)] && $Dap($dap,pc-rid) == $rid } {
    process-created $dap $pid [lindex [lindex $exprs 0] 1]
  }
  if { [info exists Dap($dap,pd-rid)] && $Dap($dap,pd-rid) == $rid } {
    process-destroyed $dap $pid
  }
}
proc process-created { dap pid Name } {
  global Dap Daps Proc

  set name [TCLstring $Name]

  # The debugging adapter might not be connected yet!
  if { [lsearch $Daps $dap] == -1 } {
    dap-connected $dap {} {}
  }

  lappend Dap($dap,pids) $pid
  set Proc($dap,$pid,name) $name

  # Call all tide-process-created procedures
  tide-call process-created $dap $pid $name
}
proc process-destroyed { dap pid } {
  global Dap Proc

  puts stderr "proc destroyed: $dap, $pid"

  tide-call process-destroyed $dap $pid

  set index [lsearch $Dap($dap,pids) $pid]
  set Dap($dap,pids) [lreplace $Dap($dap,pids) $index $index]
  unset Proc($dap,$pid,name)
}
proc tide-ack-event-procs { event } {
  global Dap

  if { [regexp {create-rule\(pc,([^,]+),} $event m dap] } {
    set idx [string last "," $event]
    set end [expr [string length $event]-2]
    set Dap($dap,pc-rid) [string trim [string range $event [expr $idx+1] $end]]
  } else {
    if { [regexp {create-rule\(pd,([^,]+),} $event m dap] } {
      set idx [string last "," $event]
      set end [expr [string length $event]-2]
      set Dap($dap,pd-rid) [string trim [string range $event [expr $idx+1] $end]]
    }
  }

}
