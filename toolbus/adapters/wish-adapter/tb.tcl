# --------------------------------------------------------------------
# tb.tcl -- fixed interface code for wish <-> wish-adapter communication
#
# TBstring:	encode a tcl string into ToolBus format
# TCLstring:	decode a string in ToolBus format into Tcl format
# TBsend: 	send a tcl string to ToolBus
# TBerror: 	wrap a tcl error message as TB message
# TBrequire:    require that function exists in script

proc TBstring {txt} {
  regsub -all "\\\\"" $txt "\\\\\\" txt
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
	return $res
  } else {
	return $txt
  }	
}

proc TBerror {txt} {
  puts stderr wish-error([TBstring $txt])
}

# The following function depends on
# LENSPEC = 8
# MIN_MSG_SIZE = 128
# (see utils.[ch])
# THIS SHOULD BE PARAMETERIZED !!!

proc TBsend {txt} {
  set len [expr [string length $txt] + 8]
  set msg "[format "%-.7d:" $len]$txt"
  puts -nonewline stdout [format "%-128s" $msg]
  flush stdout
}

proc sendTB {txt} {  # for compatibility with older versions
  TBsend $txt
}

proc TBevent {txt} {
  TBsend "snd-event($txt)"
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

# --------------------------------------------------------------------
