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

option add *Background GhostWhite
option add *Foreground RoyalBlue

option add *Entry.Foreground black

# --------------------------------------------------------------------
#
# (requires tb.tcl, which is loaded automatically by the wish-adapter)


proc new-bidder {id name} {
   global bidders
   set bidders($id) $name
   show_status "New bidder $name connected"
}

proc rec-ack-event {n} {
    global bidders highest_bidder

    enable_buttons
    show_status "Item sold to $highest_bidder!"
    after 4000 {.master.bot.status configure -text "No sale in progress"}
}

proc rec-terminate {n} {
  destroy .
  exit
}

proc show_status {s} {
    .master.bot.status configure -text $s
}

proc new-bid {bidder bid} {
     global current_bidder current_bid bidders

     set current_bid $bid
     set current_bidder "$bidders($bidder) = $bidder"
     show_status "New bid made"
}

proc update-highest-bid {bidder bid} {
    global highest_bid highest_bidder bidders

    set highest_bid $bid
    set highest_bidder "$bidders($bidder)"
}

proc any-higher-bid {n} {
   .master.bot.status configure -text "$n secs remaining"
}

proc mkMaster {} {
  global sale_in_progress

  set sale_in_progress 0

  set w .master
  toplevel $w
  wm title $w "Auction Master"
  wm minsize $w 10 10

  label $w.f0 -text "Auction Master"
  pack $w.f0 -side top

  frame $w.f1
  pack $w.f1 -side top
  label $w.f1.ldescr -text "Item for sale" -width 15 -anchor e
  entry $w.f1.descr -width 30 -relief sunken -textvariable description
  pack $w.f1.ldescr $w.f1.descr -side left -padx 5
  bind $w.f1.descr <Return> "focus $w.f2.bid"

  frame $w.f2
  pack $w.f2 -side top
  label $w.f2.lbid -text "Highest bid" -width 15 -anchor e
  entry $w.f2.bid -width 30 -relief sunken -textvariable highest_bid
  pack $w.f2.lbid $w.f2.bid -side left -padx 5
  bind $w.f2.bid <Return> button_new

  frame $w.f3
  pack $w.f3 -side top
  label $w.f3.lhbidder -text "Highest Bidder" -width 15 -anchor e
  entry $w.f3.hbidder -width 30 -textvariable highest_bidder
  pack $w.f3.lhbidder $w.f3.hbidder -side left -padx 5

  frame $w.f5
  pack $w.f5 -side top
  label $w.f5.lamount -text "Current Bid" -width 15 -anchor e
  entry $w.f5.amount -width 30 -textvariable current_bid
  pack $w.f5.lamount $w.f5.amount -side left -padx 5

  frame $w.f4
  pack $w.f4 -side top
  label $w.f4.lbidder -text "Current Bidder" -width 15 -anchor e
  entry $w.f4.bidder -width 30 -textvariable current_bidder
  pack $w.f4.lbidder $w.f4.bidder -side left -padx 5

  frame $w.bot
  pack $w.bot -side top
  button $w.bot.new -text "New" -state normal -command button_new

  button $w.bot.quit -text "Quit" -state normal -command {
    TBsend "snd-event(quit)"
  }
  label $w.bot.status -text "No sale in progress" -width 40 -foreground red
  pack $w.bot.new $w.bot.quit $w.bot.status -side left -padx 10
}

proc button_new { } {
    global highest_bid current_bid current_bidder highest_bidder description
    global sale_in_progress

    if { $sale_in_progress == 0 } {
      set sale_in_progress 1

      if { $highest_bid == "" } {
         set highest_bid 0
      }
      puts stderr "description: $description -> [TBstring $description]"
      TBsend "snd-event(new-item([TBstring $description],$highest_bid))"
 
      set current_bid $highest_bid
      set current_bidder  ""
      set highest_bidder $current_bidder
      .master.bot.new configure -state disabled    
      .master.bot.quit configure -state disabled
      .master.bot.status configure -text "Sale in progress ..."
    }
}

proc enable_buttons { } {
     global sale_in_progress

    .master.bot.new configure -state normal
    .master.bot.quit configure -state normal
    set sale_in_progress 0
}

mkMaster
