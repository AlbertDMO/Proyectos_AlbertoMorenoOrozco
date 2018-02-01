<?php
	session_start();
	if($_SESSION["valido"] == 987654321){
?>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>Documento sin título</title>
</head>

<body>
	<p>Seccion protegida</p>
    <a href="cerrarSesion.php?idSesion=valido">Cerrar sesion</a>
</body>
</html>
<?php
	}else{
		header("location:form_validacionUsr.php");
	}
?>