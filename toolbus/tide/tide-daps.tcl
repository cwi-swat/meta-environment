proc dap-connected { dap info procs } {
  global Tide Daps Dap

  puts stderr "dap-connected: $dap $procs"
  set propagate 0
  if { [lsearch $Daps $dap] == -1 } {
      lappend Daps $dap
      set Dap($dap,info) {}
      set Dap($dap,info,multi-process) 0
      set propagate 1
      analyze-port-info $dap {}
      analyze-action-info $dap {}
      analyze-expression-info $dap {}
      analyze-exec-control-info $dap {}
  }

    foreach entry $info {
      set class [lindex $entry 0]
      set options [lindex $entry 1]

      if { [lsearch $Dap($dap,info) $class] == -1 } {
        lappend Dap($dap,info) $class
        puts stderr "class: $class, options: $options"
        set Dap($dap,info,$class) $options
        switch $class {
          ports			{ analyze-port-info $dap $options }
          actions			{ if { $Tide(actions) } {
  				    analyze-action-info $dap $options } }
          expressions		{ analyze-expression-info $dap $options }
          exec-control		{ analyze-exec-control-info $dap $options }
  	multi-process		{ set Dap($dap,info,multi-process) 1 }
        } 
      }
    }

  if { $propagate } {
    # Call any tide-dap-connected* procedures present
    tide-call dap-connected $dap $procs $info
  }
}
proc analyze-port-info { dap options } {
  global Dap

  set Dap($dap,port,exec-state)	0
  set Dap($dap,port,location)	0
  set Dap($dap,port,always)	0
  set Dap($dap,port,call)	0
  set Dap($dap,port,retry)	0
  set Dap($dap,port,fail)	0
  set Dap($dap,port,succeed)	0
  set Dap($dap,port,variable)	0
  set Dap($dap,port,exception)	0
  set Dap($dap,port,send)	0
  set Dap($dap,port,receive)	0
  set Dap($dap,port,process-creation)	 0
  set Dap($dap,port,process-destruction) 0

  foreach port $options {
    set type [lindex $port 0]
    lappend Dap($dap,ports) $type
    set Dap($dap,port,$type) 1
    set Dap($dap,port,$type,when) [lindex $port 1]
    set Dap($dap,port,type,input) [lindex $port 2]
  }
}
proc analyze-action-info { dap acts } {
  global Dap

  set Dap($dap,acts) {}
  foreach action $acts {
    set name  [TCLstring [lindex $action 0]]
    set arity [lindex $action 1]
    set doc   [TCLstring [lindex $action 2]]
    puts stderr "action: $name, $arity, $doc"
    lappend Dap($dap,acts) $name
    set Dap($dap,act$name,arity) $arity
    set Dap($dap,act$name,doc) $doc
  }
}
proc analyze-expression-info { dap options } {
  global Dap

  foreach opt $options {
    set type [lindex $opt 0]
    switch $type {
      functions		{ set Dap($dap,functions) [lindex $opt 2] }
    }
  }
}
proc analyze-exec-control-info { dap options } {
  global Dap

  set Dap($dap,ec,single-step)	0
  set Dap($dap,ec,step-over)	0
  set Dap($dap,ec,run)		0
  set Dap($dap,ec,run-until-parent) 0
  set Dap($dap,ec,stop)		0

  foreach ec $options {
    set Dap($dap,ec,$ec) 1
  }
}
proc dap-disconnected { dap } {
  global Daps Dap

  puts stderr "dap-disconnected: $dap"
  
  # Call any tide-dap-disconnected* procs present
  tide-call dap-disconnected $dap

  set index [lsearch $Daps $dap]
  set Daps [lreplace $Daps $index $index]
  foreach class $Dap($dap,info) {
    unset Dap($dap,info,$class)
  }
  unset Dap($dap,info)
}
proc tide-get-search-paths { dap categorie } {
  global Dap

  foreach paths $Dap($dap,info,search-paths) {
    if {[lindex $paths 0] == $categorie} {
      return [lindex $paths 1]
    }
  }
  return {}
}

global Daps Dap
set Daps {}
