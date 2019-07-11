<html>
<head>
<style>
td{
	border:solid;
}
tr{
	border:solid;
}
th{
	border:solid;
}
input{
	height : 50px;
}
</style>
<title> Employee Operations </title>
</head>
<body>
<form action="" method="post">
<table style="border:solid" cellspacing=4 cellpadding=2>
	<tr>
		<th colspan=5>
		<h2> Employee Operations </h2>
		</th>
	</tr>
	<tr>
		<td>
		<input type="text" id="1" name="Name" placeholder = "Name" />
		</td>
		<td>
		<input type="text" id="2" name="City" placeholder = "City" />
		</td>
		<td>
		<input type="text" id="3" name="Salary" placeholder = "Salary" />
		</td>
		<td>
		<input type = "submit" id = "b1" name="Submit1" style = "width : 70px"  value = "Insert" />
		</td>
		
		<td rowspan = 3>
			<input type = "submit" name="Submit4" id = "b4" value = "Display" style="width:70px"/> 
		</td>

	</tr>
		<td colspan=3>
			<input type = "text" id="4" name = "deleteName" placeholder = "Employee Name" style="width:100%" oninput="showHint(this.value);"/>
		</td>
		<td>
			<input type = "submit" name="Submit2" id = "b2" style = "width : 70px" value = "Delete" /> 
		</td>
	<tr>
		<td>
		<input type="text" id="5" name="oldName" placeholder = "Existing Name" />
		</td>
		<td colspan=2>
		<input type="text" id="6" name="newName" placeholder = "New Name" style="width:100%"/>
		</td>
		<td>
		<input type = "submit" name="Submit3" id = "b3" value = "Update" style = "width : 70px"/> 
		</td>
	</tr>
</table>
</form>
<div id="txtHint">
</div>
</body>
<script>

	function showHint(str)
	{
		alert(str);
		if(str == null)
		{
			document.getElementById("txtHint").innerHTML = "";
		}
		else
		{
			if(window.XMLHttpRequest)
			{
				ajaxOb = new XMLHttpRequest();
			}
			ajaxOb.onreadystatechange = function()
			{
				if(this.readyState === 4 && this.status == 200)
				{
					document.getElementById("txtHint").innerHTML = this.responseText;
				}
			};
			ajaxOb.open("GET","suggestions.php?str="+str,true);
			ajaxOb.send();
		}
	}

</script>
</html>


<?php

	$conn = mysqli_connect("localhost","root","","WT")
		or die(mysqli_connect_errno());
	if(isset($_POST["Submit1"]))
	{
		$name = $_POST["Name"];
		$sal = $_POST["Salary"];
		$city = $_POST["City"];
		$query = "insert into employee values('".$name."',".$sal.",'".$city."');";
		mysqli_query($conn,$query);
		unset($_POST["Submit1"]);
	}

	if(isset($_POST["Submit2"]))
	{
		$name = $_POST["deleteName"];
		$query = "delete from employee where name = '".$name."';";
		mysqli_query($conn,$query);
		unset($_POST["Submit2"]);
	}

	if(isset($_POST["Submit3"]))
	{
		$name1 = $_POST["oldName"];
		$name2 = $_POST["newName"];
		$query = "UPDATE employee SET name='".$name2."' WHERE name = '".$name1."';";
		mysqli_query($conn,$query);
		unset($_POST["Submit3"]);
	}

	if(isset($_POST["Submit4"]))
	{
		$query = "select * from employee;";
		$resultSet = mysqli_query($conn,$query);
		echo "<table border=1 padding=15>";
       		echo "<tr>";
                echo "<th>"; echo "NAME"; echo "</th>";
                echo "<th>"; echo "SALARY"; echo "</th>";
		echo "<th>"; echo "CITY"; echo "</th>";
            	echo "<tr>";
		while($row = mysqli_fetch_array($resultSet))
		{
			echo "<tr>";
                	echo "<td>"; echo $row["name"]; echo "</td>";
                	echo "<td>"; echo $row["salary"]; echo "</td>";
			echo "<td>"; echo $row["city"]; echo "</td>";
            		echo "</tr>";
		}
		echo "</table>";
		unset($_POST["Submit4"]);
	}

?>