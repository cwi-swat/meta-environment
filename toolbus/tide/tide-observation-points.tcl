proc tide-init-observation-points { } {
  tide-init-modules { daps processes }
}
proc tide-dap-connected-observation-points { dap info } {
  global Dap

  set Dap($dap,opoints) {}
}
proc tide-dap-disconnected-x-observation-points { dap } {
  global Dap

  unset Dap($dap,opoints)
}
proc observation-point-set { P oid port cond acts } {
  global Dap OPoint
  global PAT_PROCS PAT_ALL

  set port [TCLport $port]
  if { [regexp $PAT_ALL $P P dap] } {
    set pids all
  } elseif { [regexp $PAT_PROCS $P P dap Pids] } {
      set pids $Pids
  } else {
    puts stderr "*** observation-point-set: wrongly formatted process spec $P"
    return
  }
  puts stderr "observation-point-set: $dap, $oid, $pids, $port, $cond, $acts"

  if { $oid != -1 && [lsearch $Dap($dap,opoints) $oid] == -1 } {
    lappend Dap($dap,opoints)  $oid
    set OPoint($dap,$oid,port) $port
    set OPoint($dap,$oid,cond) $cond
    set OPoint($dap,$oid,acts) $acts
    set OPoint($dap,$oid,pids) $pids

    set count 0
    foreach act $acts {
      set OPoint($dap,$oid,value$count) ""
      set OPoint($dap,$oid,expr$count) ""
      if { [string match watch* $act] } {
        set end [expr [string length $act] -2]
        set OPoint($dap,$oid,expr$count) [string range $act 6 $end]  
      }
      incr count
    }
    set OPoint($dap,$oid,count) $count

    tide-call observation-point-set $dap $oid $pids $port $cond $acts
  } else {
    puts stderr "observation-point failed: $oid, $P, $port, $cond, $acts"
  }
}
proc observation-point-cleared { P oid } {
  global Dap OPoint PAT_ALL PAT_PROCS

  if { [regexp $PAT_ALL $P P dap] } {
    set pids all
  } elseif { [regexp $PAT_PROCS $P P dap Pids] } {
      set pids $Pids
  } else {
    puts stderr "*** observation-point-cleared: wrongly formatted process spec $P"
    return
  }
  puts stderr "observation-point-cleared: $dap, $oid"

  tide-call observation-point-cleared $dap $oid

  set idx [lsearch $Dap($dap,opoints) $oid]
  set Dap($dap,opoints) [lreplace $Dap($dap,opoints) $idx $idx]

  unset OPoint($dap,$oid,port)
  unset OPoint($dap,$oid,cond)
  unset OPoint($dap,$oid,acts)
  unset OPoint($dap,$oid,pids)
  unset OPoint($dap,$oid,value)
}
proc watchpoint { P oid expr val } {
  global Dap OPoint
  global PAT_PROCS PAT_ALL

  if { [regexp $PAT_ALL $P P dap] } {
    set pids all
  } elseif { [regexp $PAT_PROCS $P P dap Pids] } {
      set pids $Pids
  } else {
    puts stderr "*** watchpoint: wrongly formatted process spec $P"
    return
  }
  puts stderr "watchpoint: $dap, $oid, $pids, $expr, $val"

  tide-call watchpoint $dap $oid $pids $expr $val
}
proc tide-set-observation-point { dap pids port cond acts } {
  set Acts \[$acts\]
  if { $cond == "" } {
    set cond always
  }
  if { $pids == "all" } {
    TBpost "set-observation-point(proc($dap,all),[TBport $port],$cond,$Acts)"
  } else {
    set Pids [TBlist $pids]
    set Port [TBport $port]
    TBpost "set-observation-point(proc($dap,$Pids),$Port,$cond,$Acts)"
  }
}
proc tide-clear-observation-point { dap oid } {
  TBpost "clear-observation-point(proc($dap,all),$oid)"
}

global OPoint
