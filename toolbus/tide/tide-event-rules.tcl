proc tide-init-event-rules { } {
  tide-init-modules { daps processes }
}
proc tide-dap-connected-event-rules { dap info procs } {
  global Dap

  set Dap($dap,rules) {}
}
proc tide-dap-disconnected-x-event-rules { dap } {
  global Dap

  unset Dap($dap,rules)
}
proc rule-created { dap pids rid port cond acts life } {
  global Dap Rule

  set port [TCLport $port]

  if { $rid != -1 && [lsearch $Dap($dap,rules) $rid] == -1 } {
    lappend Dap($dap,rules)  $rid
    set Rule($dap,$rid,port) $port
    set Rule($dap,$rid,cond) $cond
    set Rule($dap,$rid,acts) $acts
    set Rule($dap,$rid,life) $life
    set Rule($dap,$rid,pids) $pids

    set Rule($dap,$rid,porttype) [lindex $port 0]
    set Rule($dap,$rid,when) [lindex $port 1]

    tide-call rule-created $dap $rid $pids $port $cond $acts $life
  }
}
proc rule-destroyed { dap pid rid } {
  tide-call rule-destroyed $dap $rid

  set idx [lsearch $Dap($dap,rules) $rid]
  set Dap($dap,rules) [lreplace $Dap($dap,rules) $idx $idx]

  unset Rule($dap,$rid,port)
  unset Rule($dap,$rid,cond)
  unset Rule($dap,$rid,acts)
  unset Rule($dap,$rid,life)
  unset Rule($dap,$rid,pids)
  unset Rule($dap,$rid,value)
}
proc rule-modified { dap pids rid port cond acts life } {
  global Dap Rule

  set port [TCLport $port]
  puts stderr "rule-modified: $dap, $rid, $pids, $port, $cond, $acts"

  if { $rid != -1 } {
    if { [lsearch $Dap($dap,rules) $rid] == -1 } {
      lappend Dap($dap,rules)  $rid
    }
    
    set Rule($dap,$rid,port) $port
    set Rule($dap,$rid,cond) $cond
    set Rule($dap,$rid,acts) $acts
    set Rule($dap,$rid,life) $life
    set Rule($dap,$rid,pids) $pids

    tide-call rule-modified $dap $rid $pids $port $cond $acts $life
  }
}
proc watchpoint { dap pid rid exprs } {
  global Dap Rule

  set Rule($dap,$rid,pid) $pid
  set Rule($dap,$rid,exprs) $exprs
  tide-call watchpoint $dap $pid $rid $exprs
}
proc tide-create-rule { type dap pids port cond acts life } {
  set Acts \[$acts\]
  if { $cond == "" } {
    set cond true
  }
  if { $pids == "all" } {
    TBpost "create-rule($type,$dap,all,[TBport $port],$cond,$Acts,$life)"
  } else {
    set Pids [TBlist $pids]
    set Port [TBport $port]
    TBpost "create-rule($type,$dap,$Pids,$Port,$cond,$Acts,$life)"
  }
}
proc tide-destroy-rule { dap rid } {
  TBpost "destroy-rule($dap,all,$rid)"
}
proc tide-modify-rule { rid dap pids port cond acts life } {
  set Acts \[$acts\]
  if { $cond == "" } {
    set cond true
  }
  if { $pids == "all" } {
    TBpost "modify-rule($rid,$dap,all,[TBport $port],$cond,$Acts,$life)"
  } else {
    set Pids [TBlist $pids]
    set Port [TBport $port]
    TBpost "modify-rule($rid,$dap,$Pids,$Port,$cond,$Acts,$life)"
  }
}

global Rule
