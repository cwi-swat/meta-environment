#
#    ToolBus -- The ToolBus Application Architecture
#    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
#                             The  Netherlands.
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# --------------------------------------------------------------------
# tb.tcl -- fixed interface code for wish <-> wish-adapter communication
#
# TBstring:	encode a tcl string into ToolBus format
# TCLstring:	decode a string in ToolBus format into Tcl format
# TBsend: 	send a tcl string to ToolBus
# TBerror: 	wrap a tcl error message as TB message
# TBrequire:    require that function exists in script

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

# The following function depends on
# LENSPEC = 12
# MIN_MSG_SIZE = 128
# (see utils.[ch])
# THIS SHOULD BE PARAMETERIZED !!!

proc TBsend {txt} {
  set len [expr [string length $txt] + 12]
  set msg "[format "%-.11d:" $len]$txt"
  puts -nonewline stdout [format "%-128s" $msg]
  flush stdout
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

# --------------------------------------------------------------------
