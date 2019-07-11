#Create a simulator object
	set ns [new Simulator]
	
	#Create two nodes and a link
	set bs [$ns node]
	set br [$ns node]
	$ns duplex-link $bs $br 100Mb 10ms DropTail
	
	#setup sender side	
	set tcp [new Agent/TCP/Linux]
	$tcp set timestamps_ true
	$tcp set window_ 100000
	#$tcp set windowOption_ 8
	$ns attach-agent $bs $tcp
	
	#set up receiver side
	set sink [new Agent/TCPSink/Sack1]
	$sink set ts_echo_rfc1323_ true
	$ns attach-agent $br $sink
	
	#logical connection
	$ns connect $tcp $sink
	
	#Setup a FTP over TCP connection
	set ftp [new Application/FTP]
	$ftp attach-agent $tcp
	$ftp set type_ FTP
	
	$ns at 0 "$tcp select_ca highspeed"
	
	#Start FTP 
	$ns at 0 "$ftp start"
	$ns at 10 "$ftp stop"
	$ns at 11 "exit 0"
	
	set MonitorInterval 0.1
	set qmonfile [open "queue.trace" "w"]
	close $qmonfile
	set qmon [$ns monitor-queue $bs $br "" $MonitorInterval]
	source "sampling.tcl"
	proc monitor {interval} {
	    global ns tcp qmon
	    set nowtime [$ns now]
	    monitor_tcp $ns $tcp p_simple.trace
	    monitor_queue $ns $qmon queue_simple.trace
	    $ns after $interval "monitor $interval"
	}
	$ns at 0 "monitor $MonitorInterval"
	
	
	$ns run
