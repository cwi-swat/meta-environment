proc tide-init { tool modules } {
  global Tide

  set Tide(modules) { }
  set Tide(tool)    $tool
  tide-init-modules $modules
}
proc tide-init-modules { modules } {
    global Tide TB_LIBDIR

    foreach mod $modules {
      # puts stderr "loading module $mod"
      if { [lsearch $Tide(modules) $mod] == -1 } {
        if { [catch "uplevel #0 \"source $TB_LIBDIR/tide/tide-$mod.tcl\"" err] } {
          puts stderr "Error while loading file tide-$mod.tcl: $err"
        } else {
          lappend Tide(modules) $mod
          if { [info proc tide-init-$mod] != "" } {
            tide-init-$mod
          }
        }
      }
    }
}
proc tide-register-handler { type handler } {
  global Handlers

  lappend Handlers($type) $handler
}
proc tide-call { type args } {

  if { [info exists Handlers($type)] } {
    foreach h $Handlers($type) {
      eval $h $args
    }
  }
  set l [info procs tide-$type*]
  set l [lsort $l]
  foreach h $l {
    eval $h $args
  }
}
proc rec-ack-event { event } {
  TBack $event

  foreach p [info procs tide-ack-event*] {
    $p $event
  }
}
proc rec-terminate { arg } {
  foreach p [info procs tide-terminate*] {
    $p $arg
  }
  exit
}

proc TCLport { port } {
  switch [lindex $port 0] {
    location	-
    call	-
    retry	-
    fail	-
    succeed	-
    exception	-
    variable    { set port [lreplace $port 1 1 [TCLstring [lindex $port 1]]] }
  }
  return $port
}
proc TBport { port } {
  switch [lindex $port 0] {
    location	-
    call	-
    retry	-
    fail	-
    succeed	-
    exception	-
    variable    { set port [lreplace $port 2 2 [TBstring [lindex $port 2]]] }
  }

  return [TBlist $port]
}

set PAT_PROC	{proc\(([a-zA-Z()0-9\-]+),([0-9]+)\)}
set PAT_PROCS	{proc\(([a-zA-Z()0-9\-]+),\{([^\}]+)\}\)}
set PAT_ALL	{proc\(([a-zA-Z()0-9\-]+),all\)}

set Daps { }

if { ![info exists Tide(actions)] } {
  set Tide(actions) 0
}

global Handlers
