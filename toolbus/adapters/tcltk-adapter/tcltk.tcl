# --------------------------------------------------------------------
# tb.tcl -- fixed interface code for wish <-> wish-adapter communication
#
# TBstring:	encode a tcl string into ToolBus format
# TCLstring:	decode a string in ToolBus format into Tcl format
# TBsend: 	send a tcl string to ToolBus
# TBerror: 	wrap a tcl error message as TB message
# TBrequire:    require that function exists in script

proc TBlist {list} {
  return "\[[join $list ,]\]"
}

# Will be a C function someday...
proc TCLstring {txt} {
  if [regexp {^"[0-9]+:(.*)"$} $txt txt res] {
	return $res
  } elseif [regexp {^"(.*)"$} $txt txt res] {
        regsub -all {\\\\} $res {\\} res
        regsub -all  {\\"} $res {"}  res
        return $res
  } else {
	return $txt
  }	
}

proc sendTB {txt} {  # for compatibility with older versions
  TBsend $txt
}

proc TBevent {txt} {
  TBsend "snd-event($txt)"
}

proc TBpost {event} {
  global TBack 

  regexp {([-a-zA-Z_0-9]+)} $event ev func
  if { ![info exists TBack($func)] || !$TBack($func) } {
    TBevent $event
    set TBack($func) 1 
    set TBack($func,q) {}
  } else {
    lappend TBack($func,q) $event
  }
}

proc TBack {event} {
  global TBack

  regexp {([-a-zA-Z_0-9]+)} $event ev func
  if { [info exists TBack($func)] && $TBack($func) } {
    if { $TBack($func,q) == {} } {
      set TBack($func) 0
    } else {
      TBevent [lindex $TBack($func,q) 0]
      set TBack($func,q) [lrange $TBack($func,q) 1 end]
    } 
  }
}

proc TBrequire {tool name nargs} {
  if { [llength [info procs $name]] != 1 } {
     puts stderr "$tool: *** WARNING: proc $name (with $nargs arguments) is missing\n"
     return;
   }
  if { [llength [info args $name]] != $nargs } {
     puts stderr "$tool: *** WARNING: proc $name should have $nargs arguments\n"
  }
}

proc signature {sigsin sigsout} {
  puts stderr "SIGNATURE: $sigsin $sigsout"
}

# --------------------------------------------------------------------
