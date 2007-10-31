proc TBstring {txt} {
  regsub -all "\\\\" $txt "\\\\\\" txt
  regsub -all "\"" $txt "\\\"" txt
  return "\"$txt\""
}

proc TBlist {list} {
  return "\[[join $list ,]\]"
}

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

proc TBerror {txt} {
  puts stderr wish-error([TBstring $txt])
}

proc TBsend {txt} {
  puts stdout $txt
  flush stdout
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
    puts stderr "$tool: *** WARNING: proc $name (with $nargs arguments) is missing"
    flush stderr;
    return;
  }
  if { [llength [info args $name]] != $nargs } {
    puts stderr "$tool: *** WARNING: proc $name should have $nargs arguments"
    flush stderr;
  }
}

# --------------------------------------------------------------------
