#!/usr/local/bin/wish -f

# Information on ships. Full name, width, colour and default amount.
set ships(sweeper)    [list "Mine Sweeper" 2 "ForestGreen" 1 ]
set ships(destroyer)  [list "Destroyer"    3 "Sienna1"     2 ]
set ships(submarine)  [list "Submarine"    3 "RoyalBlue"   2 ]
set ships(cruiser)    [list "Cruiser"      4 "Orange"      2 ]
set ships(carrier)    [list "Carrier"      5 "Maroon"      1 ]
set ships(battleship) [list "Battleship"   5 "Firebrick"   1 ]
set sizes(widest)     [lindex $ships(battleship) 1]

proc rec-ack-event {trm} {
}

proc rec-terminate {n} {
	exit
}

# Activate a player so he can fire his shot.
proc activate {} {
	global board gameover incoming

	set incoming "Select enemy target to bomb."
	if {[info exists gameover] == 1} {return}

	$board(foe) configure -cursor cross
	$board(foe) bind all <Button-1> {fireShot}
	$board(foe) itemconf header -fill red\
			-text "Your turn - Click to fire!"
}

# Deactivate a player so he can't shoot anymore.
proc deactivate {} {
	global board incoming

	set incoming "Waiting for other player..."

	$board(foe) configure -cursor watch
	$board(foe) bind all <Button-1> {}
	$board(foe) itemconf header -fill black -text "Enemy Forces"
}

# Notify player where other player has shot.
proc notifyShot {x y last} {
	global board gameover
	set colour [lindex [$board(ally) itemconf $x,$y -fill] 4]
	$board(ally) itemconf $x,$y -fill red
	after 500 "$board(ally) itemconf $x,$y -fill $colour -stipple @grey.25"
	if {$last == 3} {
		set gameover 1
		$board(ally) itemconf header -text "YOU ARE DEFEATED!" -fill red
		$board(ally) configure -cursor pirate
		$board(foe) itemconf header -text "YOU ARE DEFEATED!" -fill red
		$board(foe) bind all <Button-1> {}
		$board(foe) configure -cursor pirate
	}
}

# Send a chat to the ToolBus.
proc sendChat {} {
	global outgoing

	TBsend "snd-event(chat([TBstring $outgoing]))"
	set outgoing "Message sent"
	.chatout conf -state disabled
	after 1000 {global outgoing; set outgoing ""; .chatout conf -state normal}
}

# Receive a chat from the ToolBus.
proc receiveChat {msg} {
	global incoming

	set incoming [TCLstring $msg]
	.chatin conf -fg red
	after 500 {.chatin conf -fg black}
}

# Draw a grid for one player.
proc drawBoard {c x y {rows 14}} {
	global sizes

	set size 8c
	set width [expr [winfo fpixels $c $size]/$rows]

	set sizes(rows)  $rows
	set sizes(board) $size
	set sizes(width) $width

	set x [winfo fpixels $c $x]
	set y [winfo fpixels $c $y]

	# Draw the squares, add coordinates as tag.
	for {set i 0} {$i < $rows} {incr i} {
		set x1 [expr $x + $i * $width]
		set x2 [expr $x1 + $width]
		for {set j 0} {$j < $rows} {incr j} {
			set y1 [expr $y + $j * $width]
			set y2 [expr $y1 + $width]
			$c create rect $x1 $y1 $x2 $y2 -tags $i,$j -fill white
		}
	}
}

# Draw the Selector. This is the square on the leftside where the
# ships are shown. Player can click on the ship to change it from
# a horizontal to a vertical position and vice versa.
proc drawSelector {w} {
	global sizes selector board incoming

	set c ${w}.c
	set width [expr $sizes(width) * ($sizes(widest) + 2)]

	canvas $c			\
		-width  $width	\
		-height $width	\
		-cursor watch	\
		-relief ridge
	pack $c -in $w

	set selector(canvas) $c

	set lbl ${w}.lbl
	message $lbl										\
		-font -Adobe-Helvetica-bold-r-normal--*-180*	\
		-width 5c -pady 5m								\
		-text "Ship"
	pack $lbl -in $w

	set selector(label) $lbl
	set selector(hor)   0

	set but ${w}.but
	button $but -text "Done"							\
		-font -Adobe-Helvetica-bold-r-normal--*-180*	\
		-activeforeground red							\
		-command "removeSelector $w"					\
		-state disabled -cursor watch
	pack $but -side bottom -fill x -pady 2m
	set selector(button) $but

	set msg ${w}.msg
	message $msg	\
		-width 5c	\
		-text "- Click on ship to rotate.\n-\
				Click on grid to place.\n-\
				Right button to remove."
	pack $msg -pady 3m

	set incoming "Place your ships."

	handleSelector init
}

# After all ships are placed, the selector is removed with removeSelector.
proc removeSelector {w} {
	global board incoming

	destroy $w

	$board(ally) bind all <Button-1> {}
	$board(ally) bind all <Button-3> {}
	$board(ally) configure -cursor watch

	TBsend "snd-event(done)"
	pack .foe -side left -pady 1m
	set board(foe) .foe
	deactivate
}

# The selector handler. Depending on the player's actions,
# this handler is called with "done" (player clicks done-button),
# or "init" (player places a ship, or removes one from the board).
proc handleSelector {{status ""}} {
	global ships sizes allowed selector board

	set c $selector(canvas)

	if {$status == "done"} {
		$c delete $selector(rect)
		$selector(label) config -text "No more ships"
		$selector(button) config -state normal -cursor hand2
		$c configure -cursor watch
		bind $c <Button-1> {}
		$board(ally) bind all <Button-1> "	\
			$selector(label) conf -fg red;	\
			after 500 $selector(label) conf -fg black"
		return
	}

	if {$status == "init"} {
		set selector(hor) 1
		$c configure -cursor exchange
		$selector(button) config -state disabled -cursor watch
		bind $c <Button-1> "handleSelector"
		$board(ally) bind all <Button-1> {placeShip .ally}
		$board(ally) bind all <Button-3> {removeShip .ally}
	} else {
		set selector(hor) [expr 1-$selector(hor)]
	}

	set ship   [lindex $allowed 0]
	set name   [lindex $ships($ship) 0]
	set length [lindex $ships($ship) 1]
	set colour [lindex $ships($ship) 2]
	set width  [expr $sizes(width) * ($sizes(widest) + 2)]
	set swidth [expr $sizes(width) * $length]

	set x1 [expr ($width - $swidth)/2]
	set x2 [expr $x1 + $swidth]
	set y1 [expr ($width - $sizes(width))/2]
	set y2 [expr $y1 + $sizes(width)]

	if {$selector(hor) == 0} {
		set tmp $y1; set y1 $x1; set x1 $tmp
		set tmp $y2; set y2 $x2; set x2 $tmp
	}

	# Remove old ship in selector and draw a new one.
	catch {$c delete $selector(rect)}
	set selector(rect)	\
		[$c create rect $x1 $y1 $x2 $y2 -fill $colour -width 1.5]

	$selector(label) config -text $name
}

# Procedure to draw a ship on the grid.
proc placeShip canvas {
	global selector allowed ships uniq

	if {[info exists selector] == 0} {return}
	if {[info exists uniq] == 0} {set uniq 0}

	set ship   [lindex $allowed 0]
	set name   [lindex $ships($ship) 0]
	set length [lindex $ships($ship) 1]
	set colour [lindex $ships($ship) 2]

	set id     [$canvas find withtag current]
	set coords [lindex [$canvas gettags $id] 0]
	set comma  [string first , $coords]
	if {$comma == -1} {return}

	set x [string range $coords 0 [expr $comma-1]]
	set y [string range $coords [expr $comma+1] end]

	set ok [checkShip $canvas $x $y $length $selector(hor)]
	if {$ok != 1} {return}

	TBsend "snd-event(place([TBstring $ship.$uniq], $x, $y, $selector(hor)))"
	for {set i 0} {$i < $length} {incr i} {
		$canvas itemconfigure "$x,$y" -fill $colour
		$canvas addtag $ship.$uniq withtag $x,$y
		if {$selector(hor)} {incr x} else {incr y}
	}
	incr uniq

	set allowed [lreplace $allowed 0 0]
	if {$allowed == ""} {
		handleSelector done
	} else {
		handleSelector init
	}
}

# Couldn't find min/max routines for Tcl,
# so I had to write them myself :-|.
proc max {a b} {
	return [expr $a > $b ? $a : $b]
}

proc min {a b} {
	return [expr $a < $b ? $a : $b]
}

# Check if a location is suitable for a specific ship. This means
# that it will not cross the border of the grid, nor will it come
# into the collision-range of another ship. Each ship must have all
# its surrounding squares on the grid be empty (`water').
# Conflicting ships will be greyed for 500 ms to show why the ship
# cannot be placed there.
proc checkShip {c x y length hor} {
	global sizes ships selector allowed

	set grid $sizes(rows)

	# Check if ship's position would exceed grid size.
	if {$hor} {set coord $x} else {set coord $y}
	if {$coord + $length > $grid} {
		set name [lindex $ships([lindex $allowed 0]) 0]
		$selector(label) config -text "Won't fit" -fg red
		after 600 "$selector(label) config -text \"$name\" -fg black"
		return 0
	}

	# Check possible collision with other ships.
	set x1 [max 0 [expr $x - 1]]
	set y1 [max 0 [expr $y - 1]]

	if {$hor} {
		set x2 [min $grid [expr $x + $length]]
		set y2 [min $grid [expr $y + 1]]
	} else {
		set x2 [min $grid [expr $x + 1]]
		set y2 [min $grid [expr $y + $length]]
	}

	set ok 1
	for {set x $x1} {$x <= $x2} {incr x} {
		for {set y $y1} {$y <= $y2} {incr y} {
			set id [$c find withtag "$x,$y"]
			set tags [$c gettags $id]
			foreach ship [array names ships] {
				if {[set ind [lsearch -glob $tags "$ship*"]] != -1} {
					set it [lindex $tags $ind]
					set colour [lindex $ships($ship) 2]
					$c itemconfigure $it -fill grey
					after 500 "$c itemconfigure $it -fill $colour"
					set ok 0
					break
				}
			}
		}
	}
	
	return $ok
}

# Procedure to remove a ship from the grid.
proc removeShip canvas {
	global ships allowed

	set id [$canvas find withtag current]
	set tags [$canvas gettags $id]

	foreach i [array names ships] {
		if {[set ind [lsearch -glob $tags "$i*"]] != -1} {
			set tag [lindex $tags $ind]
			$canvas itemconfigure $tag -fill white
			TBsend "snd-event(remove([TBstring $tag]))"
			$canvas dtag $tag $tag
			set allowed [linsert $allowed 0 $i]
			handleSelector init
		}
	}
}

# Procedure to fire a shot when it is this player's turn.
proc fireShot {} {
	global board

	set c      $board(foe)
	set id     [$c find withtag current]
	set coords [lindex [$c gettags $id] 0]
	set comma  [string first , $coords]
	if {$comma == -1} {return}

	set x [string range $coords 0 [expr $comma-1]]
	set y [string range $coords [expr $comma+1] end]

	TBsend "snd-event(hit($x, $y))"
	deactivate
}

# This procedure shows the result of the player's shot.
# If a ship is sunk as a result of the last shot, it is now
# given the appropriate colour, so the player can see what kind
# of ship he has sunk. Water is shown as blue, and a check is
# made to see if the player has won.
proc showResult {x y res name} {
	global board ships gameover

	set c $board(foe)
	set id [$c find withtag $x,$y]
	if {$res == -1} {
		$c itemconf $id -fill blue
	}
	if {$res == 0} {
		$board(foe) itemconf header -text "Location was already HIT"
		after 2000 "$board(foe) itemconf header\
			-text {Enemy Forces}"
	}
	if {$res == 1} {
		$c itemconf $id -fill red
		$c addtag $name withtag $id
	}
	if {$res >= 2} {
		set ship   [string range $name 0 [expr [string first . $name] -1]]
		set colour [lindex $ships($ship) 2]
		$c addtag $name withtag $id
		$c itemconf $name -fill $colour
	}
	if {$res == 3} {
		set gameover 1
		$board(ally) itemconf header -text "YOU ARE VICTORIOUS!" -fill red
		$board(ally) configure -cursor man
		$board(foe) itemconf header -text "YOU ARE VICTORIOUS!" -fill red
		$board(foe) bind all <Button-1> {}
		$board(foe) configure -cursor man
	}
}

# Procedure to draw the initialization screen. This is the screen
# where players can configure the amount of ships and the board-size.
proc drawInit {} {
	global ships amount boardsize grab

	set grab(amount) 0
	set grab(size) 0

	set w .init
	frame $w -relief ridge -bd 2
	pack $w -padx 2m -pady 2m -fill x -expand true

	button $w.ok -text "Initialization Done"	\
		-command {init-done}
	pack $w.ok -side bottom -pady 1m -fill x -expand true

	frame $w.label
	frame $w.amount
	frame $w.button
	frame $w.size

	pack $w.label -side left -fill x
	pack $w.amount -side left
	pack $w.button -side left
	pack $w.size -side right -fill x -padx 1m

	# Create the buttons used for configuring the amount of ships.
	foreach type [array names ships] {
		global nr_$type
		eval "set nr_$type [lindex $ships($type) 3]"
		label  $w.lbl$type -text "[lindex $ships($type) 0]s"
		entry  $w.num$type -width 4 -relief ridge	\
				-textvariable nr_$type -state disabled
		button $w.but$type -text "Change"	\
			-command "try-lock $type"
		pack $w.lbl$type -in $w.label -anchor w
		pack $w.num$type -in $w.amount -pady 1
		pack $w.but$type -in $w.button -padx 1m
		bind $w.num$type <Return> "updateAmount $type"
	}

	# Create the radiobuttons for the boardsize.
	set boardsize 150	;# Default size
	radiobutton $w.s0 -text "Tiny"   -variable boardsize -value 100	\
		-anchor w -command "sndSize"
	radiobutton $w.s1 -text "Small"  -variable boardsize -value 125	\
		-anchor w -command "sndSize"
	radiobutton $w.s2 -text "Normal" -variable boardsize -value 150	\
		-anchor w -command "sndSize"
	radiobutton $w.s3 -text "Large"  -variable boardsize -value 175	\
		-anchor w -command "sndSize"
	radiobutton $w.s4 -text "Huge"   -variable boardsize -value 200	\
		-anchor w -command "sndSize"
	radiobutton $w.s5 -text "Insane" -variable boardsize -value 400	\
		-anchor w -command "sndSize"
	pack $w.s0 $w.s1 $w.s2 $w.s3 $w.s4 $w.s5 -in $w.size	\
			-side top -fill x -expand true
}

# When player clicks to inform he is done configuring, his
# buttons are disabled.
proc init-done {} {
	global ships

	set w .init

	# Disable radiobuttons
	for {set i 0} {$i < 6} {incr i} {
		$w.s$i conf -state disabled
	}

	# Disable amount changing buttons
	foreach ship [array names ships] {
		$w.but$ship conf -state disabled
	}

	# Disable done-button
	.init.ok conf -state disabled
	TBsend "snd-event(init-done)"
}

# Receive message from the ToolBus that the other player is done
# with his configuration.
proc rec-done {} {
	global incoming
	set incoming "Other player is done."
	.chatin conf -fg red
	after 500 {.chatin conf -fg black}
}



# Some ToolBus interface code here.
proc sndSize {} {
	global boardsize
	TBsend "snd-event(boardsize($boardsize))"
}

proc try-lock {type} {
	TBsend "snd-event(lock([TBstring $type]))"
}

proc not-locked {type} {
	puts stderr "not-locked: $type"
}

proc changeAmount {type ok} {
	global nr_$type ships

	set w .init

	if {$ok == "false"} {
		global incoming
		set type [lindex $ships($type) 0]
		set incoming "Other player is already changing\
			the amount of ${type}s!"
		.chatin conf -fg red
		after 500 {.chatin conf -fg black}
		return
	}

	grab amount
	$w.lbl$type conf -fg red
	$w.num$type conf -relief sunken -state normal
	foreach ship [array names ships] {
		$w.but$ship conf -state disabled
	}

}

proc updateAmount {type} {
	global nr_$type ships

	set w .init

	release amount
	$w.lbl$type conf -fg black
	$w.num$type conf -relief ridge -state disabled
	foreach ship [array names ships] {
		$w.but$ship conf -state normal
	}

	set var nr_$type
	eval "set amount $$var"
	if ![regexp {^[0-9]+$} $amount] {
		set amount [lindex $ships($type) 3]
		set nr_$type $amount
	}
	TBsend "snd-event(set-amount([TBstring $type], $amount))"
}

proc rec-amount {type amount} {
	global nr_[TCLstring $type]
	eval "set nr_[TCLstring $type] $amount"
	release
}

proc rec-size {size} {
	global boardsize
	set boardsize $size
	release
}

proc grab {type} {
	global grab
	set grab($type) 1
	.init.ok conf -state disabled
}

proc release {{type ""}} {
	global grab ships
	if {$type != ""} {set grab($type) 0}
	if {$grab(amount) || $grab(size)} {return}

	set w .init
	for {set i 0} {$i < 6} {incr i} {
		$w.s$i conf -state normal
	}
	foreach ship [array names ships] {
		$w.but$ship conf -state normal
	}
	$w.ok conf -state normal
}

# Procedure to calculate the gridsize according to the configured
# size, and draw the setup-screen.
proc doSetup {} {
	global board ships allowed boardsize

	destroy .init

	frame .info
	pack .info -side left

	set total 0
	set allowed ""
	foreach type [array names ships] {
		global nr_$type
		eval "set nr \$nr_$type"
		incr total [expr ([lindex $ships($type) 1] + 2) * 3 * $nr]
		for {set i 0} {$i < $nr} {incr i} {
			lappend allowed $type
		}
	}

	set gridsize [expr ceil(sqrt( ($total*$boardsize)/100 ))]

	# Setup and pack Allied Forces.
	canvas .ally -width 9c -height 9.5c -cursor cross -relief ridge
	.ally create text 4.5c .5c -text "Allied Forces"\
		-font -Adobe-Helvetica-bold-r-normal--*-180* -tags header
	drawBoard .ally .5c 1c $gridsize
	pack .ally -side left -pady 1m
	set board(ally) .ally

	# Setup, but do NOT pack the Enemy forces.
	canvas .foe -width 9c -height 9.5c -relief ridge
	.foe create text 4.5c .5c -text "Enemy Forces"\
		-font -Adobe-Helvetica-bold-r-normal--*-180* -tags header
	drawBoard .foe .5c 1c $gridsize

	drawSelector .info
}

#------------------------------------------------------------------------------
wm geometry . +50+150
wm title . "Battleships"
wm iconname . "XBattle"
# ------------------------------------------------------------------------------

drawInit

button .quit -text "Quit" -command {
	TBsend "snd-event(quit)"
}
pack .quit -side bottom -pady 1m -anchor center -fill x -expand true

frame .chatfrm
pack .chatfrm -side bottom -pady 1m -fill both -expand true

set incoming "<No incoming message>"
set outgoing ""

message .chatin  -width 8c -relief ridge -textvariable incoming	\
		-font -Adobe-Times-medium-r-normal--*-180*

entry .chatout -width 40 -relief sunken -textvariable outgoing	\
		-font -Adobe-Times-medium-r-normal--*-180*
pack .chatout .chatin -in .chatfrm -pady 1m

bind .chatout <Return> "sendChat"
