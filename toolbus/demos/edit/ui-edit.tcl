#!/usr/local/bin/wish -f        			    -*- C -*-

# --------------------------------------------------------------------
#
# (requires tb.tcl, which is loaded automatically by the wish-adapter)

proc rec-ack-event { n } { }

proc rec-terminate { n } {
   destroy .
   exit
 }

proc displayError { n } { puts stderr "*** displayError not implemented\n" }

set auto_path "$tk_library/demos $auto_path"

proc mkEditor {w edInstance} {
   global clipboard filename edState

   frame $w.menu -relief raised -bd 2
   pack $w.menu -side top -fill x -expand 1
   text $w.text -relief raised -bd 2 -yscrollcommand "$w.scroll set" -setgrid 1 \
            -width 60 -height 28 -font "-Adobe-Helvetica-Medium-R-Normal-*-120-*"
   scrollbar $w.scroll -relief flat -command "$w.text yview"
   pack $w.scroll -side right -fill y -expand 1
   pack $w.text -side left -fill both -expand 1

   bind $w.text <Button-2> "textMousePoint $edInstance %W %x %y"

   #Create Tree menu
   menubutton $w.menu.tree -text "Tree" -underline 0 -menu $w.menu.tree.t
   menu $w.menu.tree.t
   $w.menu.tree.t add command -label "Up" -underline 0 -command "treeUp $edInstance"
   $w.menu.tree.t add command -label "Down" -underline 0 -command "treeDown $edInstance"
   $w.menu.tree.t add command -label "Next" -underline 0 -command "treeNext $edInstance"

   pack $w.menu.tree -side left
   tk_menuBar $w.menu.tree

   set edState($edInstance,filename) ""
   set edState($edInstance,frame) $w	
}

proc textMousePoint {instance w x y} {
   set xy [$w index @$x,$y];
   regexp {([0-9]+)\.([0-9]+)} $xy cxy cx cy;
   TBsend "snd-event([TBstring $instance],mouse($cx,$cy))"
}

proc treeUp {instance} {
   TBsend "snd-event([TBstring $instance],tree-up)"
}

proc treeDown {instance} {
   TBsend "snd-event([TBstring $instance],tree-down)"
}

proc treeNext {instance} {
   TBsend "snd-event([TBstring $instance],tree-next)"
}

proc setFocus {instance begin end} {
   global edState

   set text $edState($instance,frame).text
   $text tag delete focus
   $text tag add focus $begin $end
   $text tag configure focus -foreground Red
}

proc mk-text-editor { filename } {
   global edState

   set edInstance $filename
   # replace "." in filename
   regsub -all {\.} $filename "_" edInstance
   set f .editor$edInstance	
   toplevel $f
   wm title $f $filename
   wm minsize $f 10 10
   mkEditor $f $filename
   set ind 1
   set file [open "tst.text" r]
   while {[gets $file line] >= 0} {
     $f.text insert $ind.0 $line\n
     set ind [incr ind]
   }
   $f.text tag add focus 0.0 end
   $f.text tag configure focus -foreground Red
   TBsend "snd-value(ok)"
}

proc close-editor { filename } {
   global edState
   destroy $edState($filename,frame)
}

################ Toplevel

proc mkToplevel {} {
   global filename

   frame .top
   button .top.edit -text "Edit" -command {
	  getFileName
	  TBsend "snd-event(edit([TBstring $filename]))"
   }
   button .top.close -text "Close" -command {
	  global filename
	  getFileName
	  TBsend "snd-event(close([TBstring $filename]))"
   }
   button .top.quit -text "Quit" -command {
          .top.edit configure -state disabled
         .top.close configure -state disabled
         .top.quit configure -state disabled
	  TBsend "snd-event(quit)"
   }	
   pack .top.edit .top.close .top.quit
   pack .top
}

proc getFileName {} {
   global oldFocus filename w

   set w ".getFileName"
   toplevel $w
   wm title $w "getFileName"
   label $w.label -width 30 -text "Give FileName:"
   entry $w.filename -width 30 -relief sunken -textvariable filename
   pack $w.label $w.filename
   bind $w.filename <Return> {
                destroy $w
                focus $oldFocus
   }
   set oldFocus [focus]
   grab $w
   focus $w.filename
   tkwait window $w
}

proc shutdown {} {
   destroy .top
}

mkToplevel

