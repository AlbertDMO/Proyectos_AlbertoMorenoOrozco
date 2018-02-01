<?php
	$boleta = $_POST["boleta"];
	
	$conexion = mysqli_connect("localhost","root","","tweb2014a");
	$sql = "DELETE FROM usuarios WHERE boleta = '$boleta'";
	$res = mysqli_query($conexion, $sql);
	if(mysqli_affected_rows($conexion) == 0)
		echo "Hubo problemas";
	else
		echo "Registro eliminado";
?>