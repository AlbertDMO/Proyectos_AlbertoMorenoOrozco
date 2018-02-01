<?php
	$boleta = $_POST["boleta"];
	$conexion = mysqli_connect("localhost", "root", "", "tweb2014a");
	$sql = "SELECT * FROM usuarios WHERE boleta = '$boleta'";
	$res = mysqli_query($conexion, $sql);
	
	$registro = mysqli_fetch_row($res);
?>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>Documento sin título</title>
</head>

<body>
	<form action="formEditar2_BD.php?boleta=<?php echo $registro[0]; ?>" method="post">
    	Boleta:<?php echo $registro[0]; ?>
        Contrase&ntilde;a:
        <input type="password" name="contrasena" value="<?php echo $registro[1]; ?>"<br />
        Nombre:
        <input type="text" name="nombre" value="<?php echo $registro[2]; ?>"><br />
        Correo:
        <input type="text" name="correo" value="<?php echo $registro[3]; ?>"><br />
        <input type="submit" value="Editar" />
    </form>
</body>
</html>