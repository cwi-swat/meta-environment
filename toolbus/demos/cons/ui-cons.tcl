#!/usr/local/bin/wish -f        			    -*- C -*-

# --------------------------------------------------------------------
#
# (requires tb.tcl, which is loaded automatically by the wish-adapter)

# Perform a list of moves of the form [move(<str>,<int>,<int>),...]
proc moves { Moves } {
   regexp {^\[(.*)\]$} $Moves Moves Moves
   set Moves ",$Moves"

   while { [ regexp {^,move\(("[^"]*"),([0-9]+),([0-9]+)\)(.*)$} \
                    $Moves Moves name x y tail] } {

           move [TCLstring $name] $x $y
           set Moves $tail
           set tail ""

           if { [string length $Moves] == 0} {
              return
           }
	 }
}

proc rec-ack-event { n } {
}

proc rec-terminate { n } {
  exit
}

# ---------------------------------------------------------------------

proc ball {name color x y} {
	global c

        set name  [TCLstring $name]
        set color [TCLstring $color]
    	$c create oval [expr $x - 20] [expr $y - 20 ] \
	               [expr $x + 20] [expr $y + 20] \
		       -outline black -fill $color -tags $name
	$c bind $name <Motion> {
		global curTag
		set curTag [lindex [%W gettags current] 0]
		%W coords $curTag [expr %x - 20] [expr %y - 20 ] \
	                          [expr %x + 20] [expr %y + 20]}
	$c bind $name <1> {
	global curTag
	TBsend "snd-event(move([TBstring $curTag],%x,%y))";
	after 500}
}

proc move {name x y} {
	global c
   	$c coords $name [expr $x - 20] [expr $y - 20 ] \
	                [expr $x + 20] [expr $y + 20]
}

	frame .w
	set c .w.c
	canvas $c -relief raised -width 500 -height 400
	pack $c
        pack .w

