#!/usr/local/bin/wish -f					-*- C -*-

# --------------------------------------------------------------------
#                
# receiveTB: receive and decode TB message
#
# (requires tb.tcl, which is loaded automatically by the wish-adapter)

option add *Background GhostWhite
option add *Foreground RoyalBlue

proc display-value {trm} {
    show Value "Value is:" $trm 1
}

proc display-expr-error {msg} {
  show Error "Error is: $msg 1
}

proc display-log {trm} {
    show_list Log "Log is:" $trm 1
  }



proc display-time {trm} {
    show Time "Time is:" [TCLstring $trm] 2
  }

proc rec-ack-event {n} {
  global ack
  set ack($n) 1
  enable $n
}

proc rec-terminate { n } { destroy . }

# Manage groups of buttons. Buttons are disabled when pushed
# and enabled when both an acknowledgement (from ToolBus) and an "ok"
# (from the ok button of a show window) have been received.

set groups(1) {.calc .log}
set groups(2) {.time}

# ok or acknowledgement received per group:

set ok(1) 0
set ok(2) 0

set ack(1) 0
set ack(2) 0

proc disable { group } {
  global groups ok ack
  foreach w $groups($group) {
    $w configure -state disabled
  }
  set ok($group) 0
  set ack($group) 0
}

proc enable { group } {
  global groups ok ack
  if {$ok($group) && $ack($group)} {
     foreach w $groups($group) {
        $w configure -state normal
     }
   }
}

button .calc -text "Calc" -command {
  sendTB "snd-event(1,button(calc))";
  disable 1
}

button .log -text "showLog" -command {
  sendTB "snd-event(1,button(showLog))";
  disable 1
}

button .time -text "showTime" -command {
  sendTB "snd-event(2,button(showTime))";
  disable 2
}

button .quit -text "Quit" -command {
  sendTB "snd-event(button(quit))"
}

pack .calc .log .time .quit -fill both

proc get-expr-dialog { } {
  global w oldFocus expr

  set w ".getExprDialog"
  toplevel $w -class Dialog
	wm title $w getExprDialog
	label $w.label1 -width 30 -text "Give expression:"
	entry $w.expr -width 30 -relief sunken -textvariable expr
	pack $w.label1 $w.expr
	bind $w.expr <Return> {		
		sendTB "snd-value(expr([TBstring $expr]))"
		destroy $w
		focus $oldFocus	
	}
	set oldFocus [focus]
	grab $w
	focus $w.expr
	return $expr
}

proc show {name text value group} {
	set w .show$name
	toplevel $w -class Dialog
	wm title $w show$name
	frame $w.top -relief raised -bd 1
	pack $w.top -side top -fill both
	frame $w.bot -relief raised -bd 1
	pack $w.bot -side bottom -fill both
	
	label $w.top.label1 -text $text
	label $w.top.label2 -text $value
	pack $w.top.label1 $w.top.label2 -side left

	button $w.bot.ok -text ok -command "global ok; destroy $w; set ok($group) 1; enable $group"
	pack $w.bot.ok
	bind $w <Return> { destroy $w }
}


proc show_list {name text value group} {
	set w .show$name
	toplevel $w -class Dialog
	wm title $w show$name
	frame $w.top -relief raised -bd 1
	pack $w.top -side top -fill both
	frame $w.bot -relief raised -bd 1
	pack $w.bot -side bottom -fill both
	
	listbox $w.top.list -relief raised -borderwidth 2 -geometry 40x10 -yscrollcommand "$w.top.scroll set"
	pack $w.top.list -side left
        scrollbar $w.top.scroll -command "$w.top.list yview"
        pack $w.top.scroll -side right -fill y

        foreach e $value {
	  if {[llength $e] == 3} {
            $w.top.list insert end "[lindex $e 0] = [lindex $e 1] ([lindex $e 2])"
	  } else {
            $w.top.list insert end "[lindex $e 0] = [lindex $e 1]"
          }
        }

	button $w.bot.ok -text ok -command "global ok; destroy $w; set ok($group) 1; enable $group"
	pack $w.bot.ok
	bind $w <Return> { destroy $w }
}

