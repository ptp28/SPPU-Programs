<?php

$str = $_GET["str"];
$conn = mysqli_connect("localhost","root","","WT") or die(mysqli_connect_errno());
$query = "select * from employee where name LIKE '$str%' ; ";
$resultSet = mysqli_query($conn,$query);
?>

<html>
<body>
<table>
    <?php while($row = mysqli_fetch_array($resultSet))
    {
        ?>
    <tr>
    <td>
        <?php echo $row["name"]; ?>
    </td>
    <td>
        <?php echo $row["salary"]; ?>
    </td>
    <td>
        <?php echo $row["city"]; ?>
    </td>
    </tr>
    <?php
    }
    ?>
    </table>
</body>
</html>