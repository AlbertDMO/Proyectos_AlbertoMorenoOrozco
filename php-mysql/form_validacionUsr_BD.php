<?php
	session_start();
	$boleta = $_POST["boleta"];
	$contrasena = md5($_POST["contrasena"]);
	
	$conexion = mysqli_connect("localhost","root","","tweb2014a");
	$sql = "SELECT * FROM usuarios WHERE boleta = '$boleta' AND contrasena = '$contrasena'";

	$res = mysqli_query($conexion, $sql);
	
	if(mysqli_num_rows($res)==0){
		echo "Ooops!!! Lo sentimos no estas registrado en nuestro sistema";
		echo "<br /><a href='form_validacionUsr.php'>Regresar</a>";
	}else{
		$_SESSION["valido"] = 987654321;
		header("location:bienvenida.php");
	}
	
	
?>