#
#    ToolBus -- The ToolBus Application Architecture
#    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
#                             The  Netherlands.
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
#!/usr/local/bin/wish -f					-*- C -*-

wm withdraw .
#-------------------------------------------------------------
# Set default options
#-------------------------------------------------------------

option add *Background AntiqueWhite
option add *Foreground DeepPink

option add *Entry.Foreground black

# --------------------------------------------------------------------
#
# (requires tb.tcl, which is loaded automatically by the wish-adapter)

proc get-name {} {
    global me
    TBsend "snd-value(name([TBstring $me]))"
  }

proc accept {a} {
  if { $a == "accepted" } {
    accept-bid
  } else {
    reject-bid
  }
}

proc rec-ack-event {n} {     
   enable_buttons
}

proc no-auction {} {
     give_msg "No sale in progress"
}

proc any-higher-bid {} {
     give_msg "Last chance to bid"
}

# ---------------------------------------------------------------------

proc give_msg {txt} {
  global me
   .bidder$me.buttons.msg configure -text $txt
}

proc accept-bid {} {
     global highest_bid current_bid
     set highest_bid $current_bid
     give_msg "Your bid is accepted"
     enable_buttons
}

proc enable_buttons {} {
    global me
    .bidder$me.buttons.bid configure -state normal
    .bidder$me.buttons.quit configure -state normal
}

proc reject-bid {} {
     give_msg "Your bid is rejected"
     enable_buttons
}

proc new-item {descr amount} {
   global description highest_bid current_bid me my_bid

   set description [TCLstring $descr]
   set highest_bid $amount
   set my_bid 0
   set current_bid ""
   give_msg "New item for sale"
   enable_buttons
 }

proc update-bid {amount} {
   global me
   global highest_bid current_bid
   set highest_bid $amount
   if {$amount > $current_bid } {
      give_msg "Higher Bid made"
    }  
 }

proc sold {amount} {
     global my_bid me
     if {$amount == $my_bid} {set bidder " to you"} else {set bidder ""}
     give_msg "Item is sold for \$$amount$bidder"
     .bidder$me.buttons.bid configure -state disabled
}

proc mkBidder {} {
  global me

  set w .bidder$me
  toplevel $w
  wm title $w "$me"
  wm minsize $w 10 10

  label $w.f0 -text "Bidder $me"
  pack $w.f0 -side top

  frame $w.f1
  pack $w.f1 -side top
  label $w.f1.ldescr -text "Item for Sale" -width 15 -anchor e
  entry $w.f1.descr -width 30 -textvariable description -state disabled
  pack $w.f1.ldescr $w.f1.descr -side left -padx 5

  frame $w.f2
  pack $w.f2 -side top
  label $w.f2.lbid -text "Highest Bid" -width 15 -anchor e
  entry $w.f2.bid -width 30 -textvariable highest_bid -state disabled
  pack $w.f2.lbid $w.f2.bid -side left -padx 5

  frame $w.f5
  pack $w.f5 -side top
  label $w.f5.lamount -text "My Bid" -width 15 -anchor e
  entry $w.f5.amount -width 30 -relief sunken -textvariable current_bid
  pack $w.f5.lamount $w.f5.amount -side left -padx 5
  bind $w.f5.amount <Return> button_bid

  frame $w.buttons
  pack $w.buttons -side top
  button $w.buttons.bid -text "Bid" -command button_bid -state disabled

  button $w.buttons.quit -text "Quit" -command {destroy .; TBsend snd-disconnect}
# pack $w.buttons.bid $w.buttons.quit -side left -padx 70

#  frame $w.bot
#  pack $w.bot -side bottom
  label $w.buttons.msg -width 30 -text "No auction going on" -foreground blue
# pack $w.bot.msg -side top

  pack $w.buttons.bid $w.buttons.quit $w.buttons.msg -side left -padx 10
}

proc button_bid { } {
    global my_bid me current_bid

    set my_bid $current_bid
    .bidder$me.buttons.quit configure -state disabled
    .bidder$me.buttons.bid configure -state disabled
    TBsend "snd-event(bid($current_bid))"
  }

proc rec-terminate { n } {
  global me
  puts stderr "$n\n"
  destroy .bidder$me
  exit 
}

set me Vince

for { set i 0 } {$i <= $argc} {incr i} {
  if { [lindex $argv $i] == "-name" } {
    set me [lindex $argv [expr $i + 1]]
      break;
  }
}

mkBidder
