<html>
    <head>
        <title> AJAX CODE </title>
    </head>
    <body>
        <div style="display: grid;grid-template-columns: 1fr 1fr;">
        <div style="border:solid;">
        <form method="post" onsubmit="insertData();">
            First Name <input type="text" name="fname">
            <br>
            <br>
            Last Name <input type="text" name="lname">
            <br>
            <br>
        <input type="submit" name="submit" value="submit">
        </form>
        </div>
        <div style="border:solid;">
        <form>
            <b>
                Please Enter Name for Search Profile
            </b>
            <input type="text" name="username" oninput="showUser(this.value)">
        </form>
        </div>
        </div>
        <div id="txtHint">
        </div>
    </body>
    <script> 
        function showUser(str) 
        {
            if (str == "") 
            {
                document.getElementById("txtHint").innerHTML = "";
                return;
            } 
            else 
            {
                if (window.XMLHttpRequest) 
                {
                    xmlhttp = new XMLHttpRequest();
                }        

                xmlhttp.onreadystatechange = function() 
                {
                    if (this.readyState == 4 &&this.status == 200) 
                    {
                        document.getElementById("txtHint").innerHTML = this.responseText;
                    }
                };
                xmlhttp.open("GET","profile.php?enteredName="+str,true);
                xmlhttp.send();
            }
        }

        function insertData()
        {
            <?php
                $conn =mysqli_connect("localhost","root","","WT");
                $fname=$_POST['fname'];
                $lname=$_POST['lname'];
                $insert ="INSERT INTO users(fname,lname) VALUES ('$fname','$lname')";
                mysqli_query($conn,$insert);
                echo "document.write(\"Data inserted sucessfully\")";
            ?>
        }
    </script>
</html>

