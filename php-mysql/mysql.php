<?php
	$conexion = mysqli_connect("localhost","root","","tweb2014a");
	$sql = "SELECT * FROM usuarios";
	$res = mysqli_query($conexion, $sql);
?>
<!DOCTYPE html>
<html>
<head>
<title>PHP y MySQL</title>
<style>
	tr th{
		background-color:#0099FF;
		color:#FFF;
	}
	
	.cebra{
		background-color:#CCC;
		color:#333333;
		text-align:center;
		font-family:Verdana, Geneva, sans-serif;
	}
	
	#contenedor{
		position:relative;
		width:960px;
		margin:0 auto;
	}
</style>
</head>
<body>
<div id="contenedor">
	<h1>ESCOM</h1>
	<p>
    	Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty Qwerty .
    </p>
    <img src="pixar.jpg" width="320" height="240" />
	<table>
    	<tr><th>Boleta</th><th>Contrase&ntilde;a</th><th>Nombre</th><th>Correo</th></tr>
<?php
	while($filas = mysqli_fetch_array($res, MYSQLI_BOTH)){
		echo "<tr class='cebra'><td>".$filas[0]."</td><td>".$filas[1]."</td><td>".$filas[2]."</td><td><a href='$filas[3]'>".$filas[3]."</a></td></tr>";
	}
?>
</table>
</div>
</body>
</html>
	