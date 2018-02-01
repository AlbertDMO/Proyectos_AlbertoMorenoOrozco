<?php
	include('./bd.php');
	$nombre=$_POST['nombre'];
	
	mysql_query($query2) or die(mysql_error());
	$query2 = "SELECT nombre, descripcion FROM programa WHERE nombre=$nombre";
	$row = mysql_fetch_array($query2);
	$nombre = $row['categoria'];
	$descripcion = $row['descripcion'];

?>