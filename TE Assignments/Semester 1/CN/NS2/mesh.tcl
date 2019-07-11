set ns [new Simulator]

set nf [open out.nam w]
$ns namtrace-all $nf

#Define a 'finish' procedure
proc finish {} {
    global ns nf
    $ns flush-trace
    #Close the trace file
    close $nf
    #Executenam on the trace file
    exec nam out.nam &
    exit0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]


$ns duplex-link $n0 $n1 1Mb 2ms DropTail
$ns duplex-link $n0 $n2 1Mb 2ms DropTail
$ns duplex-link $n0 $n3 1Mb 2ms DropTail
$ns duplex-link $n0 $n4 1Mb 2ms DropTail

$ns duplex-link $n1 $n2 1Mb 2ms DropTail
$ns duplex-link $n1 $n3 1Mb 2ms DropTail
$ns duplex-link $n1 $n4 1Mb 2ms DropTail

$ns duplex-link $n2 $n3 1Mb 2ms DropTail
$ns duplex-link $n2 $n4 1Mb 2ms DropTail

$ns duplex-link $n3 $n4 1Mb 2ms DropTail

$ns duplex-link-op $n0 $n4 orient right

$ns duplex-link-op $n1 $n0 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right-down
$ns duplex-link-op $n3 $n4 orient left-down
$ns duplex-link-op $n3 $n2 orient right-down
 

set tcp0 [new Agent/TCP]
set ftp0 [new Application/FTP]

set tcp1 [new Agent/TCPSink]

$ns attach-agent $n1 $tcp0
$ns attach-agent $n4 $tcp1

$ftp0 attach-agent $tcp0

$ns connect $tcp0 $tcp1
#Schedule events for the CBR agents
$ns at 0.5 "$ftp0 start"

$ns at 4.5 "$ftp0 stop"


#Call the finish procedure after 5 seconds of simulation time
$ns at 5.0 "finish"

#Run the simulation
$ns run
