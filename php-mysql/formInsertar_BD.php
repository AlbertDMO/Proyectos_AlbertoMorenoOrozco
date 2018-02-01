<?php
	$boleta = $_POST["boleta"];
	$contrasena = md5($_POST["contrasena"]);
	$nombre = $_POST["nombre"];
	$correo = $_POST["correo"];
	
	$conexion = mysqli_connect("localhost", "root", "", "tweb2014a");
	$sql = "INSERT INTO usuarios  VALUES('$boleta','$contrasena','$nombre','$correo')";
	$res = mysqli_query($conexion, $sql);
	if(mysqli_affected_rows($conexion) == 0)
		echo "Hubo un error";
	else
		echo "Registro guardado";
?>