#!/usr/local/bin/wish -f

# Programmeeromgevingen II - Eindopdracht
#
# Filename		: tic-tac-toe.tcl
# Last update	: 28-09-1995
#
# Timme Dekker 9212396 tkdekker@fwi.uva.nl

# --------------------------------------------------------------------
#
# (requires tb.tcl, which is loaded automatically by the wish-adapter)

proc you-are {s} {
	global data symbol wake

	# identify yourself as X or O and make sure you can be given a turn
	set symbol $s

	# allow this user interface to be waked up
	set wake true

	# write a message to the user to indicate he has to start or that
	# he is next
	if {$s == "X"} {
		.d itemconfigure msg -text "You have to start the game"
	} else {
		.d itemconfigure msg -text "Your opponent will start"
	}
}

proc wake-up {} {
	global symbol wake

	# if you can be waked up
	if {$wake == "true"} {
		# set a binding appropriate to your symbol
		if {$symbol == "O"} {
			bind .d <1> {
				# find coordinate on the board of current mouse position
				set c [lindex [.d gettags [.d find closest %x %y]] 0]
				# if that coordinate is still unoccupied
				if {$data($c) == ""} {
					# put an O at that coordinate
					put-O $c
					# calculate the state of the game
					set s [check-win]
					# send the pair coordinate,state to the ToolBus
					TBsend "snd-event(game-state([TBstring $c,$s]))"
					# update the messages according to the state
					switch -exact -- $s {
						"O"	{.d itemconfigure msg -text "You win this game !"
						set wake false
						}
						"-"	{.d itemconfigure msg -text "Opponents turn"}
						"!"	{.d itemconfigure msg -text "The game is a draw"
						set wake false
						}
					}
				} else {
					.d itemconfigure msg -text "Coordinate already occupied"
				}
			}
		} else {
		# exactly the same as above but then for symbol = X instead of O
			bind .d <1> {
				set c [lindex [.d gettags [.d find closest %x %y]] 0]
				if {$data($c) == ""} {
					put-X $c
					set s [check-win]
					TBsend "snd-event(game-state([TBstring $c,$s]))"
					switch -exact -- $s {
						"X"	{.d itemconfigure msg -text "You win this game !"
						set wake false
						}
						"-"	{.d itemconfigure msg -text "Opponents turn"}
						"!"	{.d itemconfigure msg -text "The game is a draw"
						set wake false
						}
					}
				} else {
					.d itemconfigure msg -text "Coordinate already occupied"
				}
			}
		}
	}
}

proc sleep {} {
	# remove the binding to simulate a 'disabled' state
	bind .d <1> {}
}

proc update {state} {
	global symbol wake
	
	# split the incoming data up in three items: x-coord, y-coord and state
	scan $state "%d,%d,%s" x y s
	
	# check the state and take appropriate action
	if {$symbol == "O"} {
		put-X $x,$y
		if {$s == "X"} {
			.d itemconfigure msg -text "You lose the game !"
			set wake false
		}
	} else {
		put-O $x,$y
		if {$s == "O"} {
			.d itemconfigure msg -text "You lose the game !"
			set wake false
		}
	}

	switch -exact -- $s {
		"-"	{.d itemconfigure msg -text "Your turn"}
		"!"	{.d itemconfigure msg -text "The game is a draw"
			set wake false
		}
	}
}

# default functions needed for the wish-adapter
proc rec-ack-event {n} {
}

proc rec-terminate {n} {
	destroy .
}

# --------------------------------------------------------------------

proc game {margin1 grid1} {

	global data margin grid

	wm title . "Tic Tac Toe"
	# create a canvas to draw the board upon
	canvas .d -bd 2 -relief sunken

	# calculate the correct size of the board
	set margin [winfo fpixels .d $margin1]
	set grid [winfo fpixels .d $grid1]
	set size [expr 2*[winfo fpixels .d $margin]+3*$grid]

	# adapt the canvas to the correct size
	.d configure -height $size -width $size

	# create a place to display the messages in the canvas
	.d create text [expr $size/2] [expr $size-($margin/2)] -tag msg

	# create the appropriate quit-button
	button .quit   -text "Quit"   -command {
			.quit configure -state disabled
			TBsend "snd-event(quit)"
	}

	# pack 'em and stack 'em
	pack .d .quit -fill x

	# draw the board in the canvas and initialize the twodimensional array data
	for {set y 0} {$y < 3} {incr y} {
		for {set x 0} {$x < 3} {incr x} {
			set data($x,$y) ""

			.d create rectangle [expr $x*$grid+$margin]		\
								[expr $y*$grid+$margin]		\
								[expr ($x+1)*$grid+$margin]	\
								[expr ($y+1)*$grid+$margin] \
								-fill red -outline yellow -tags "$x,$y"
		}
	}
}

# function put-X draws an X on a given coordinate and sets the array data
proc put-X {coord} {
	
	global data margin grid

	scan $coord "%d,%d" x y

	set data($coord) X

	# calculate the exact position of the cross and draw two lines to
	# depict a cross
	.d create line 	[expr $x*$grid+$margin] 	\
					[expr $y*$grid+$margin]		\
					[expr ($x+1)*$grid+$margin]	\
					[expr ($y+1)*$grid+$margin] \
					-fill green -width 2 -tags $coord

	.d create line 	[expr ($x+1)*$grid+$margin]	\
					[expr $y*$grid+$margin]		\
					[expr $x*$grid+$margin]		\
					[expr ($y+1)*$grid+$margin] \
					-fill green -width 2 -tags $coord

}

# function put-O draws an O on a given coordinate and sets the array data
# in the appropriate way
proc put-O {coord} {

	global data margin grid

	scan $coord "%d,%d" x y

	set data($coord) O


	# calculate the exact position and draw the circle there
	.d create oval 	[expr $x*$grid+$margin] 	\
					[expr $y*$grid+$margin]		\
					[expr ($x+1)*$grid+$margin]	\
					[expr ($y+1)*$grid+$margin] \
					-outline blue -width 2 -tags $coord
}

# function check-win checks the state of the game and returns a code to
# indicate that state. the codes are: X if X has won, O if O has won,
# ! if the board is full (to indicate a draw) and - to indicate that no
# special state has occured yet, so the game can continue normally.
proc check-win {} {

	global data

	# check for a possible win due to a full row of X or O
	for {set y 0} {$y < 3} {incr y} {
		set row ""

		for {set x 0} {$x < 3} {incr x} {
			append row $data($x,$y)
		}

		if {$row == "XXX" || $row == "OOO"} {
			return [string index $row 0]
		}
	}

	# check for a possible win due to a full column of X or O
	for {set x 0} {$x < 3} {incr x} {
		set col ""
		for {set y 0} {$y <3} {incr y} {
			append col $data($x,$y)
		}

		if {$col == "XXX" || $col == "OOO"} {
			return [string index $col 0]
		}
	}

	# check for a possible win on the two diagonals
	set str ""

	for {set x 0} {$x < 3} {incr x} {
		append str $data($x,$x)
	}
	if {$str == "XXX" || $str == "OOO"} {
		return [string index $str 0]
	}

	set str ""

	for {set x 0} {$x < 3} {incr x} {
		append str $data($x,[expr 2-$x])
	}
	if {$str == "XXX" || $str == "OOO"} {
		return [string index $str 0]
	}

	# check if the playboard is full
	set str ""

	for {set x 0} {$x < 3} {incr x} {
		for {set y 0} {$y <3} {incr y} {
			append str $data($x,$y)
		}

		if {[string length $str] == 9} {
			return "!"
		}
	}

	# else no special state has occured: return -
	return "-"
}

# print-data is a debug function that prints the contents of the global array
# data (which contains the board) to stderr by printing each row of the two-
# dimensional array
proc print-data {} {

	global data

	for {set y 0} {$y < 3} {incr y} {
		set row ""

		for {set x 0} {$x < 3} {incr x} {
			if {$data($x,$y) != ""} {
				append row $data($x,$y)
			} else {
				append row -
			}
		}

		puts stderr $row
	}
}

# initialize userinterface of player
game 1c 2c
