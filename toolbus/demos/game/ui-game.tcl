#
# requires tb.tcl (loaded automatically by wish-adapter
#

set colorOccupied(playerA)  SlateBlue4
set colorActive(playerA)  SlateBlue4

set colorOccupied(playerB)  red
set colorActive(playerB)  red

set colorOccupied(playerC) SpringGreen
set colorActive(playerC) PaleGreen

proc mk-board {player n} {
  global colorActive thePlayer colorOccupied

  set player [TCLstring $player]
  set thePlayer $player
  set f .board
  frame .board -background $colorOccupied($player) -borderwidth 5
  set rcom {pack}
  set i 0
  while {$i < $n} { 
    frame .board.$i
    set pcom {pack}
    set j 0
    while {$j < $n} {
      button .board.$i.$j  -width 3 -height 1 \
	-activebackground $colorActive($player) \
	-command "TBsend snd-event(push($i,$j))"
      lappend pcom .board.$i.$j
      incr j
    }
    lappend pcom -side left
    eval $pcom
    lappend rcom  .board.$i
    incr i
  }
  lappend rcom -side top
  eval $rcom
    pack .board
}

proc occupy {player row col} {
  global colorOccupied
  set player [TCLstring $player]
  .board.$row.$col configure -state disabled -text "x" \
    -disabledforeground  $colorOccupied($player)\
    -background $colorOccupied($player)
}

proc rec-ack-event {n} { }

proc error {n} {}

proc draw { } { puts stderr "*** draw not implemented\n" }

proc wins { n } { puts stderr "*** wins not implemented\n" }

proc rec-terminate { n } {
   destroy .
   exit
}
