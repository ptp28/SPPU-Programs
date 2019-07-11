set val(chan)         Channel/WirelessChannel  ;# channel type
 set val(prop)         Propagation/TwoRayGround ;# radio-propagation model
 set val(ant)          Antenna/OmniAntenna      ;# Antenna type
 set val(ll)           LL                       ;# Link layer type
 set val(ifq)          Queue/DropTail/PriQueue  ;# Interface queue type
 set val(ifqlen)       50                       ;# max packet in ifq
 set val(netif)        Phy/WirelessPhy          ;# network interface type
 set val(mac)          Mac/802_11               ;# MAC type
 set val(nn)           6                        ;# number of mobilenodes
 set val(rp)           AODV                     ;# routing protocol
 set val(x)            800
 set val(y)            800

set ns [new Simulator]
#ns-random 0

set f [open 1_out.tr w]
$ns trace-all $f
set namtrace [open 1_out.nam w]
$ns namtrace-all-wireless $namtrace $val(x) $val(y)
set f0 [open packets_received.tr w]
set f1 [open packets_lost.tr w]
set f2 [open proj_out2.tr w]
set f3 [open proj_out3.tr w]

set topo [new Topography]
$topo load_flatgrid 800 800

create-god $val(nn)

set chan_1 [new $val(chan)]
set chan_2 [new $val(chan)]
set chan_3 [new $val(chan)]
set chan_4 [new $val(chan)]
set chan_5 [new $val(chan)]
set chan_6 [new $val(chan)]

# CONFIGURE AND CREATE NODES

$ns node-config  -adhocRouting $val(rp) \
          -llType $val(ll) \
                 -macType $val(mac) \
                 -ifqType $val(ifq) \
                 -ifqLen $val(ifqlen) \
                 -antType $val(ant) \
                 -propType $val(prop) \
                 -phyType $val(netif) \
                 #-channelType $val(chan) \
                 -topoInstance $topo \
                 -agentTrace OFF \
                 -routerTrace ON \
                 -macTrace ON \
                 -movementTrace OFF \
                 -channel $chan_1  # \
                 #-channel $chan_2   \
                 #-channel $chan_3   \
                 #-channel $chan_4   \ 
                 #-channel $chan_5   \
                 #-channel $chan_6 


proc finish {} {
    global ns f f0 f1 f2 f3 namtrace
    $ns flush-trace
        close $namtrace  
    close $f0
        close $f1
     close $f2
        close $f3
        exec xgraph packets_received.tr packets_lost.tr
                                     # proj_out2.tr proj_out3.tr
        exec nam -r 5m 1_out.nam &
    exit 0
}

proc record {} {
  global sink0 sink1 sink2 sink3 sink4 sink5 f0 f1 f2 f3
   #Get An Instance Of The Simulator
   set ns [Simulator instance]
  
   #Set The Time After Which The Procedure Should Be Called Again
   set time 0.05
   #How Many Bytes Have Been Received By The Traffic Sinks?
   set bw0 [$sink5 set npkts_]
   set bw1 [$sink5 set nlost_]
   #set bw2 [$sink2 set npkts_]
   #set bw3 [$sink3 set npkts_]
  
   #Get The Current Time
   set now [$ns now]
  
   #Save Data To The Files
   puts $f0 "$now [expr $bw0]"
   puts $f1 "$now [expr $bw1]"
   #puts $f2 "$now [expr $bw2]"
   #puts $f3 "$now [expr $bw3]"

   #Re-Schedule The Procedure
   $ns at [expr $now+$time] "record"
  }

# define color index
$ns color 0 blue
$ns color 1 red
$ns color 2 chocolate
$ns color 3 red
$ns color 4 brown
$ns color 5 tan
$ns color 6 gold
$ns color 7 black
                       
set n(0) [$ns node]
#$ns at 0.0 "$n(0) color red"
$n(0) color "0"
$n(0) shape "circle"
set n(1) [$ns node]
$n(1) color "blue"
$n(1) shape "circle"
set n(2) [$ns node]
$n(2) color "tan"
$n(2) shape "circle"
set n(3) [$ns node]
$n(3) color "red"
$n(3) shape "circle"
set n(4) [$ns node]
$n(4) color "tan"
$n(4) shape "circle"
set n(5) [$ns node]
$n(5) color "red"
$n(5) shape "circle"






for {set i 0} {$i < $val(nn)} {incr i} {
    $ns initial_node_pos $n($i) 30+i*100
}

$n(0) set X_ 0.0
$n(0) set Y_ 0.0
$n(0) set Z_ 0.0

$n(1) set X_ 0.0
$n(1) set Y_ 0.0
$n(1) set Z_ 0.0

$n(2) set X_ 0.0
$n(2) set Y_ 0.0
$n(2) set Z_ 0.0

$n(3) set X_ 0.0
$n(3) set Y_ 0.0
$n(3) set Z_ 0.0

$n(4) set X_ 0.0
$n(4) set Y_ 0.0
$n(4) set Z_ 0.0

$n(5) set X_ 0.0
$n(5) set Y_ 0.0
$n(5) set Z_ 0.0

$ns at 0.0 "$n(0) setdest 100.0 100.0 3000.0"
$ns at 0.0 "$n(1) setdest 200.0 200.0 3000.0"
$ns at 0.0 "$n(2) setdest 300.0 200.0 3000.0"
$ns at 0.0 "$n(3) setdest 400.0 300.0 3000.0"
$ns at 0.0 "$n(4) setdest 500.0 300.0 3000.0"
$ns at 0.0 "$n(5) setdest 600.0 400.0 3000.0"

$ns at 2.0 "$n(5) setdest 100.0 400.0 500.0"
#$ns at 1.5 "$n(3) setdest 450.0 150.0 500.0"


# CONFIGURE AND SET UP A FLOW


set sink0 [new Agent/LossMonitor]
set sink1 [new Agent/LossMonitor]
set sink2 [new Agent/LossMonitor]
set sink3 [new Agent/LossMonitor]
set sink4 [new Agent/LossMonitor]
set sink5 [new Agent/LossMonitor]
$ns attach-agent $n(0) $sink0
$ns attach-agent $n(1) $sink1
$ns attach-agent $n(2) $sink2
$ns attach-agent $n(3) $sink3
$ns attach-agent $n(4) $sink4
$ns attach-agent $n(5) $sink5

#$ns attach-agent $sink2 $sink3
set tcp0 [new Agent/TCP]
$ns attach-agent $n(0) $tcp0
set tcp1 [new Agent/TCP]
$ns attach-agent $n(1) $tcp1
set tcp2 [new Agent/TCP]
$ns attach-agent $n(2) $tcp2
set tcp3 [new Agent/TCP]
$ns attach-agent $n(3) $tcp3
set tcp4 [new Agent/TCP]
$ns attach-agent $n(4) $tcp4
set tcp5 [new Agent/TCP]
$ns attach-agent $n(5) $tcp5


proc attach-CBR-traffic { node sink size interval } {
   #Get an instance of the simulator
   set ns [Simulator instance]
   #Create a CBR  agent and attach it to the node
   set cbr [new Agent/CBR]
   $ns attach-agent $node $cbr
   $cbr set packetSize_ $size
   $cbr set interval_ $interval

   #Attach CBR source to sink;
   $ns connect $cbr $sink
   return $cbr
  }

set cbr0 [attach-CBR-traffic $n(0) $sink5 1000 .015]
#set cbr1 [attach-CBR-traffic $n(1) $sink2 1000 .015]
#set cbr2 [attach-CBR-traffic $n(2) $sink3 1000 .015]
#set cbr3 [attach-CBR-traffic $n(3) $sink0 1000 .015]
#set cbr4 [attach-CBR-traffic $n(4) $sink3 1000 .015]
#set cbr5 [attach-CBR-traffic $n(5) $sink0 1000 .015]



$ns at 0.0 "record"
#$ns at 0.5 "$cbr0 start"
#$ns at 0.5 "$cbr2 start"
#$ns at 2.0 "$cbr0 stop"
#$ns at 2.0 "$cbr2 stop"
$ns at 1.0 "$cbr0 start"
#$ns at 4.0 "$cbr3 stop"

$ns at 10.0 "finish"

puts "Start of simulation.."
$ns run
