#!/usr/local/bin/wish -f

   global tkVersion
   # wm positionfrom . user
   wm sizefrom . ""
   wm maxsize . 1152 900


proc get-name {} {
    global me
    TBsend "snd-value([TBstring $me])"
  }

#
## Set the traffic light 
#

proc light { colour } {
  .mbar configure -background $colour
  .mbar.file  configure -background $colour
}


proc change-colour { j i colour} {
.row$j.button$i configure -background $colour
}

proc winning-line {pos1 pos2 pos3} {

  set colour red
  set i [expr $pos1 - 1]
  set j [expr $i / 3]  
  change-colour $j $i $colour
  set i [expr $pos2 - 1]
  set j [expr $i / 3]  
  change-colour $j $i $colour
  set i [expr $pos3 - 1]
  set j [expr $i / 3]  
  change-colour $j $i $colour
  set tmp bisque 
  light $tmp
}

proc set-type {n} {
 global bitmap Pid
  if {$n == 1} {
    set bitmap "@./bitmap/cross.bmp"
    set Pid 1	
  } else {
    set bitmap "@./bitmap/circle.bmp"
    set Pid 2	
  }
}

proc refresh { } {
  for { set i 0 } {$i <= 8} {incr i} {
    set j [expr $i / 3]
    change-colour $j $i bisque
  }
}

proc init-group { } {
  global group
   for { set i 0 } {$i <= 8} {incr i} {
     set group($i) 1
  }
}

proc initialize { } {
  global group
   for { set i 0 } {$i <= 8} {incr i} {
     set j [expr $i / 3]
     if { $group($i) == 0} {
       .row$j.button$i  configure -bitmap  @./bitmap/empty.bmp
     }
  }
  init-group
  refresh
}



proc enable-all { } {
  global group available
   for { set i 0 } {$i <= 8} {incr i} {
      if { $group($i) == 1} {
        enable $i 
      }
   }
}


proc disable-all { } {
  global group available
   for { set i 0 } {$i <= 8} {incr i} {
     if { $group($i) == 1} {
	disable $i 
     }	
   }
}


proc disable {i} {
   set j [expr $i / 3]
  .row$j.button$i  configure -state  disabled
}

proc enable {i} {
   set j [expr $i / 3]
  .row$j.button$i  configure -state  normal
}

set me Anonymous
for { set i 0 } {$i <= $argc} {incr i} {
  if { [lindex $argv $i] == "-name" } {
    set me [lindex $argv [expr $i + 1]]
      break;
  }
}

proc update-pos {i} {
  global group  Pid
  set i [expr $i - 1]  
  set j [expr $i / 3]
  if {$Pid == 1} {
    .row$j.button$i  configure -bitmap  @./bitmap/circle.bmp
  } else {
    .row$j.button$i  configure -bitmap  @./bitmap/cross.bmp
  }	
    disable $i
    set group($i) 0	
    enable-all	
}


proc rec-ack-event {n} {     
}
  

proc rec-terminate { n } {
  puts stderr "$n\n"
  exit
}


proc build {} {
  frame .row0
  frame .row1
  frame .row2
  for { set i 0 } {$i <= 8} {incr i} {
  set j [expr $i / 3]
  button .row$j.button$i -bitmap @./bitmap/empty.bmp -command "move $i"
   }
}


proc  move { i } {
 global group bitmap Pid

  set j [expr $i / 3]
  .row$j.button$i configure -bitmap $bitmap
  TBsend "snd-event(coord([expr $i + 1]))"	
  disable $i 
  set group($i) 0
  disable-all
}

proc packall {} {
  pack .row0  
  pack .row1  
  pack .row2 
  pack .row0.button0 .row0.button1 .row0.button2  -side left
  pack .row1.button3 .row1.button4 .row1.button5  -side left
  pack .row2.button6 .row2.button7 .row2.button8  -side left
}

proc new { } {
  TBsend "snd-event(new))"
}

proc set-up-menu { } {
  global Pid
  frame .mbar
  pack .mbar  -side top -fill x
  menubutton .mbar.file -text Options -underline 0 -menu .mbar.file.menu
  pack .mbar.file -side left
  menu .mbar.file.menu
  .mbar.file.menu add command -label New -command {new}
  #.mbar.file.menu add command -label Quit -command {destroy .}
  .mbar.file.menu add command -label Quit \
	-command {destroy .; TBsend snd-disconnect}
  focus .mbar
}

proc score-board {name1 name2 score1 score2} { 
.m1 configure -text "$name1:$score1"
.m2 configure -text "$name2:$score2"
}

proc set-up-score-board { } {
  message .m1 -width 8c  -justify left
  message .m2 -width 8c -justify left
  pack .m2 -side bottom 
  pack .m1 -side bottom 
}

#
### main
#

  set bitmap "@./bitmap/empty.bmp" 

  set me Anonymous
  for { set i 0 } {$i <= $argc} {incr i} {
    if { [lindex $argv $i] == "-name" } {
      set me [lindex $argv [expr $i + 1]]
        break;
    }
  }
  wm title . $me

  init-group
  set-up-menu
  build 
  packall
  set-up-score-board

