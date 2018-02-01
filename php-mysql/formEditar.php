<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Documento sin título</title>
</head>

<body>
	<form action="formEditar2.php" method="post">
    	Boleta:<select name="boleta">
        <?php
			$conexion = mysqli_connect("localhost", "root", "", "tweb2014a");
			$sql = "SELECT boleta FROM usuarios";
			$res = mysqli_query($conexion, $sql);
			while($registros = mysqli_fetch_array($res,MYSQLI_BOTH)){
				echo "<option value='".$registros[0]."'>".$registros[0]."</option>";
			}
		?>
        </select>
        <input type="submit" value="Editar" />
    </form>
</body>
</html>