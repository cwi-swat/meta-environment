#!/usr/local/bin/wish -f					-*- C -*-

wm withdraw .

# --------------------------------------------------------------------
#
# (requires tb.tcl, which is loaded automatically by the wish-adapter)

proc get-name {} {
    global me
    TBsend "snd-value([TBstring $me])"
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
     give_msg "No auction going on at the moment"
}

proc any-higher-bid {} {
     give_msg "*** Last chance to bid ***"
}

# ---------------------------------------------------------------------

proc give_msg {txt} {
  global me
   .bidder$me.bot.msg configure -text $txt
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

   set description $descr
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

  frame $w.f1
  pack $w.f1 -side top
  label $w.f1.ldescr -text "Item for Sale"
  entry $w.f1.descr -width 30 -relief sunken -textvariable description -state disabled
  pack $w.f1.ldescr $w.f1.descr -side top

  frame $w.f2
  pack $w.f2 -side top
  label $w.f2.lbid -text "Highest Bid"
  entry $w.f2.bid -width 30 -relief sunken -textvariable highest_bid -state disabled
  pack $w.f2.lbid $w.f2.bid -side top

  frame $w.f5
  pack $w.f5 -side top
  label $w.f5.lamount -text "My Bid"
  entry $w.f5.amount -width 30 -relief sunken -textvariable current_bid
  pack $w.f5.lamount $w.f5.amount -side top

  frame $w.buttons
  pack $w.buttons -side top
  button $w.buttons.bid -text "Bid" -command {
    global my_bid me
    set my_bid $current_bid
    .bidder$me.buttons.quit configure -state disabled
    .bidder$me.buttons.bid configure -state disabled
    TBsend "snd-event(bid($current_bid))"
  } -state disabled

  button $w.buttons.quit -text "Quit" -command {destroy .; TBsend snd-disconnect}
  pack $w.buttons.bid $w.buttons.quit -side left -padx 50

  frame $w.bot
  pack $w.bot -side bottom
  label $w.bot.msg -width 30 -text "No auction going on"
    
  pack $w.bot.msg -side top
}

proc rec-terminate { n } {
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
