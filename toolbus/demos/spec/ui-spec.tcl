# #!/usr/local/bin/wish -f					-*- C -*-

# (requires tb.tcl, which is loaded automatically by the wish-adapter)

proc displayError {lino pos trm} {
    .termeditor.top.term.ed1.text tag add error $lino.$pos end
    .termeditor.top.term.ed1.text tag configure error -foreground Red
    .termeditor.top.normal.ed2.text insert 0.0 [TCLstring $trm]
  }

proc displayResult {trm} {
    .termeditor.top.normal.ed2.text insert 0.0 [TCLstring $trm]
  }

proc displayCounter {trm} {
    .termeditor.counter.ed3.text insert 0.0 [TCLstring $trm]
  }

proc rec-ack-event { n } {
    change_state normal
  }

proc rec-terminate { n } {
    withdraw .
    exit
}

# ---------------------------------------------------------------------

proc change_state {new} {
   .termeditor.buttons.reduce configure -state $new
   .termeditor.buttons.quit configure -state $new
 }

proc mkTextEditor {w n file} {

   frame $w.ed$n
   text $w.ed$n.text -bd 2 -relief sunken -yscrollcommand "$w.ed$n.scroll set" -setgrid 1 \
            -width 60 -height 8 -font "-Adobe-Helvetica-Medium-R-Normal-*-120-*"
   scrollbar $w.ed$n.scroll -relief flat -command "$w.ed$n.text yview"
   pack $w.ed$n.scroll -side right -fill y -expand 1
   pack $w.ed$n.text -side left -fill both -expand 1
}

proc mkUI { } { 
  set w .termeditor
  frame $w
  frame $w.top
  frame $w.top.term

  frame $w.buttons
  button $w.buttons.reduce -width 7 -text "Reduce" -command {
    .termeditor.top.normal.ed2.text delete 0.0 end
    .termeditor.top.term.ed1.text tag delete error
    .termeditor.counter.ed3.text delete 0.0 end
    TBsend "snd-event(text([TBstring [.termeditor.top.term.ed1.text get 0.0 end]]))"
   change_state disabled
  }

  button $w.buttons.quit -width 7 -text "Quit" -command {
    TBsend "snd-event(quit)"; destroy .
  }
  pack $w.buttons.reduce $w.buttons.quit -side top -pady 7m

  label $w.top.term.label -relief flat -width 60 -text "Term"	
#  entry $w.term.text -width 60 -relief sunken -textvariable term
  mkTextEditor $w.top.term 1 x
  pack $w.top.term.label $w.top.term.ed1

  frame $w.top.normal
  label $w.top.normal.label -relief flat -width 60 -text "Normal Form"
#  label $w.normal.result -width 60 -relief sunken -text "            "
  mkTextEditor $w.top.normal 2 x
  pack $w.top.normal.label $w.top.normal.ed2

    
  frame $w.counter
  label $w.counter.label -relief flat -width 60 -text "Counter"
#  label $w.normal.result -width 60 -relief sunken -text "            "
  mkTextEditor $w.counter 3 x
  pack $w.counter.label $w.counter.ed3

  pack $w.top.term $w.top.normal $w.counter -side top
  pack $w.buttons $w.top -side left -anchor n -padx 1m
  pack $w

}

mkUI


