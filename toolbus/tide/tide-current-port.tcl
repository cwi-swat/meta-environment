proc tide-dap-connected-current-port { dap info procs } {
  global Dap

  set Dap($dap,current-port) ""
  set Dap($dap,current-pids) all
}
proc tide-dap-disconnected-current-port { dap } {
  global Dap

  unset Dap($dap,current-port)
  unset Dap($dap,current-pids)
}
proc current-port { dap pids port } {
  global Dap Break

  set Dap($dap,current-port) $port
  set Dap($dap,current-pids) $pids

  tide-call current-port $dap $pids $port
}
proc tide-change-current-port { dap pids port } {
  if { $pids == "all" } {
    TBpost "current-port($dap,all,[TBport $port])"
  } else {
    TBpost "current-port($dap,[TBlist $pids],[TBport $port])"
  }
}
