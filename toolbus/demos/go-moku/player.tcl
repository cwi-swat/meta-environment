
# player.tcl
# Jan Kort
# 8912041

#set bitmaps @/home/kort/ToolBus/go
set bitmaps @.

proc display-message {s} {
  .msg.text yview end
  .msg.text insert end $s
}

proc rec-terminate { n } { destroy . }

proc getx {col} {
  return [expr ($col)*0.5+1.0]c
}

proc gety {row} {
  return [expr ($row)*0.5+1.0]c
}

proc mkhor {col} {
  if {$col < 10} {
    set hor [format "%c" [expr $col+64]]
  } else {
    set hor [format "%c" [expr $col+65]]
  }
  return $hor
}

proc mkver {row} {
  set ver [expr 20-$row]
  return $ver
}

proc display-stone {row col ic} {
global c
global screenx screeny
  if {$ic==0} {
    set color black
  } else {
    set color white
  }
  set x1 [getx $col-0.5]
  set y1 [gety $row-0.5]
  set x2 [getx $col+0.5]
  set y2 [gety $row+0.5]
  $c create oval $x1 $y1 $x2 $y2 -fill $color -tags "stone $row $col"
  set hor [mkhor $col]
  set ver [mkver $row]
  display-message "$color: $hor$ver\n"
}

proc rec-ack-event {n} {
}

set c .frame.c

#wm geometry . +0+0
wm title . "Go-Moku"
wm iconname . "Go-Moku"
wm minsize . 400 400
wm iconbitmap . $bitmaps/go.bm
set c .frame.c

frame .frame
frame .players

canvas $c -width 12c -height 12c

#Draw the 19x19 grid
for {set i 1} {$i <= 19} {incr i} {
  set x1 [getx 1]
  set y1 [gety $i]
  set x2 [getx 19]
  set y2 $y1
  $c create line $x1 $y1 $x2 $y2 -tags ""
  set x1 [getx $i]
  set y1 [gety 1]
  set x2 $x1
  set y2 [gety 19]
  $c create line $x1 $y1 $x2 $y2 -tags ""
}

#Show the 9 "stones ahead" marks 
for {set row 4} {$row <= 19} {incr row 6} {
  for {set col 4} {$col <= 19} {incr col 6} {
  set x1 [getx $col-0.1]
  set y1 [gety $row-0.1]
  set x2 [getx $col+0.1]
  set y2 [gety $row+0.1]
  $c create oval $x1 $y1 $x2 $y2 -fill black -tags ""
  }
}

#Letters and Numbers on the sides of the board
for {set i 1} {$i <= 19} {incr i} {
  set hor [mkhor $i]
  set ver [mkver $i]
#  set font -*-Times-medium-r-*-120-*
  set font -*-Courier-Bold-R-Normal--*-120-*
  $c create text [getx 0] [gety $i] -text $ver -anchor w -font $font
  $c create text [getx 20] [gety $i] -text $ver -anchor e -font $font
  $c create text [getx $i] [gety 0] -text $hor -anchor n -font $font
  $c create text [getx $i] [gety 20] -text $hor -anchor s -font $font
}

#put coordinate tags on all grid points 0 0 = top left, 18 18 = bottom right
for {set row 1} {$row <= 19} {incr row} {
  for {set col 1} {$col <= 19} {incr col} {
    set x1 [getx $col-0.5]
    set y1 [gety $row-0.5]
    set x2 [getx $col+0.5]
    set y2 [gety $row+0.5]
    $c create oval $x1 $y1 $x2 $y2 -fill "" -outline "" -tags "coors $row $col"
  }
}

bind $c <Button-1> {
  set tmp [$c find closest %x %y]
  set tag [$c gettags $tmp]
  set kind [lindex $tag 0]
  if {$kind == "coors"} {
    set row [lindex $tag 1]
    set col [lindex $tag 2]
    TBsend snd-event(push($row,$col))
  }
}

frame .buttons
button .buttons.quit -text "Quit" -command {
  destroy .
  TBsend snd-disconnect;
}
button .buttons.postscript -text "Postscript" -command {
  $c postscript -file "dump.ps"
}

frame .msg
text .msg.text -relief raised -height 8 -width 6 -bd 2 -yscrollcommand ".msg.scroll set"
scrollbar .msg.scroll -command ".msg.text yview"

pack .msg.scroll -side right -fill y
pack .msg.text -side left -expand yes -fill x
pack .msg -side bottom -fill both
pack .buttons.quit .buttons.postscript -side left -fill x -expand yes
pack .buttons -side bottom -fill both
pack .frame -side top -side left -fill both
pack $c -in .frame -expand yes

display-message "This is the Go-Moku, written in ToolBus and tcl/Tk\n"

