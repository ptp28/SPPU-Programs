<?php
    $conn =mysqli_connect("localhost","root","","WT");
    $fname=$_POST['fname'];
    $lname=$_POST['lname'];
    $insert ="INSERT INTO users(fname,lname) VALUES ('$fname','$lname')";
    mysqli_query($conn,$insert);
    echo "Data inserted sucessfully";
?>