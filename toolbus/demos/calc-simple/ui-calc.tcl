#!/usr/local/bin/wish -f					-*- C -*-

# --------------------------------------------------------------------
#                
# receiveTB: receive and decode TB message
#
# (requires tb.tcl, which is loaded automatically by the wish-adapter)

proc display-value {trm} {
    show Value "Value is:" $trm 1
}

proc display-log {trm} {
    show Log "Log is:" $trm 1
  }

proc display-time {trm} {
    show Time "Time is:" [TCLstring $trm] 2
  }

proc rec-ack-event {button} {
  enable $button
}

proc rec-terminate { n } { destroy . }

proc disable { button } {
  if { $button == "button(calc)" } {
    .calc configure -state disabled
  }
  if { $button == "button(quit)" } {
    .quit configure -state disabled
  }
}

proc enable { button } {
  if { $button == "button(calc)" } {
    .calc configure -state normal
  }
  if { $button == "button(quit)" } {
    .quit configure -state normal
  }
}

button .calc -text "Calc" -width 10 -command {
  sendTB "snd-event(button(calc))";
  disable "button(calc)"
}

button .quit -text "Quit" -width 10 -command {
  sendTB "snd-event(button(quit))";
  disable "button(quit)"
}

pack .calc .quit

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

