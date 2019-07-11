<?php
    $conn = mysqli_connect("localhost", "root", "","WT");
    $user_search = $_GET['enteredName'];
    $result=mysqli_query($conn, "select * from users where fname LIKE '$user_search%'");
    // $row = mysqli_fetch_array($result);
?>

<html>
    <head>
    </head>
    <body>
        <center>
            <table>

            <?php
                while($row = mysqli_fetch_array($result))
                {
            ?>

                <tr>
                    <b>
                        <td>Id :
                        </td>
                        <i>
                        <td>
                            <?php echo $row['id']; ?>
                        </td>
                        </i>
                    </b>
                </tr>
                <tr>
                    <b>
                        <td>First Name :
                        </td>
                        <i>
                        <td>
                            <?php echo $row['fname']; ?>
                        </td>
                        </i>
                    </b>
                </tr>
                <tr>
                    <b>
                        <td>Last Name :
                        </td>
                        <i>
                        <td>
                            <?php echo $row['lname']; ?>
                        </td>
                        </i>
                    </b>
                </tr>

                <?php
                }
                ?>
                
            </table>
        </center>
    </body>
</html>


