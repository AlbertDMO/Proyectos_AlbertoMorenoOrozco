<?php
	$boleta = $_REQUEST["boleta"];
	$contrasena = md5($_POST["contrasena"]);
	$nombre = $_GET["nombre"];
	$correo = $_POST["correo"];
	
	$conexion = mysqli_connect("localhost", "root", "", "tweb2014a");
	$sql = "UPDATE usuarios SET contrasena = '$contrasena', nombre = '$nombre', correo = '$correo' WHERE boleta = '$boleta'";
	
	$res = mysqli_query($conexion, $sql);
	
	if(mysqli_affected_rows($conexion) == 0){
		echo "Ooops!!! Hubo problemas";
	}else{
		echo "Registro editado ;)";
	}
?>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>Documento sin título</title>
</head>

<body>
</body>
</html>