#!/usr/local/bin/wish -f					-*- C -*-

wm withdraw .

# --------------------------------------------------------------------
#
# (requires tb.tcl, which is loaded automatically by the wish-adapter)


proc new-bidder {id name} {
   global bidders
   set bidders($id) $name
}

proc rec-ack-event {n} {
    enable_buttons
}

proc rec-terminate {n} {
  destroy .
  exit
}

proc new-bid {bidder bid} {
     global current_bidder current_bid

     set current_bid $bid
     set current_bidder $bidder
}

proc update-highest-bid {bidder bid} {
    global highest_bid highest_bidder bidders

    set highest_bid $bid
    set highest_bidder "$bidders($bidder) ($bidder)"
}

proc mkMaster {} {
  set w .master
  toplevel $w
  wm title $w "Auction Master"
  wm minsize $w 10 10

  frame $w.f1
  pack $w.f1 -side top
  label $w.f1.ldescr -text "Item for sale"
  entry $w.f1.descr -width 30 -relief sunken -textvariable description
  pack $w.f1.ldescr $w.f1.descr -side top

  frame $w.f2
  pack $w.f2 -side top
  label $w.f2.lbid -text "Highest bid"
  entry $w.f2.bid -width 30 -relief sunken -textvariable highest_bid
  pack $w.f2.lbid $w.f2.bid -side top

  frame $w.f3
  pack $w.f3 -side top
  label $w.f3.lhbidder -text "Highest Bidder"
  entry $w.f3.hbidder -width 30 -relief sunken -textvariable highest_bidder
  pack $w.f3.lhbidder $w.f3.hbidder -side top

  frame $w.f5
  pack $w.f5 -side top
  label $w.f5.lamount -text "Current Bid"
  entry $w.f5.amount -width 30 -relief sunken -textvariable current_bid
  pack $w.f5.lamount $w.f5.amount -side top

  frame $w.f4
  pack $w.f4 -side top
  label $w.f4.lbidder -text "Current Bidder"
  entry $w.f4.bidder -width 30 -relief sunken -textvariable current_bidder
  pack $w.f4.lbidder $w.f4.bidder -side top

  frame $w.bot
  pack $w.bot -side top
  button $w.bot.new -text "New" -state normal -command {
    TBsend "snd-event(new-item([TBstring $description],$highest_bid))"
    set current_bid $highest_bid
    set current_bidder  "... Auction Master ..."
    set highest_bidder $current_bidder
    .master.bot.new configure -state disabled    
    .master.bot.quit configure -state disabled
  }    
	       
  button $w.bot.quit -text "Quit" -state normal -command {
    destroy .
#    TBsend "snd-disconnect"
    TBsend "snd-event(quit)"
  }
  pack $w.bot.new $w.bot.quit -side left -padx 10
}

proc enable_buttons { } {
    .master.bot.new configure -state normal
    .master.bot.quit configure -state normal
}


mkMaster
