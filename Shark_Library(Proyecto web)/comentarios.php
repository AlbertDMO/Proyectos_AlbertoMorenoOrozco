<?php
session_cache_limiter();
session_name('s_username');
session_start();
$host_name = "db566868929.db.1and1.com";
$database = "db566868929";
$user_name = "dbo566868929";
$password = "rootroot";
$conn = new mysqli($host_name, $user_name, $password, $database);
if (mysqli_connect_errno()) {
	echo "Error al conectar con servidor MySQL: " . mysqli_connect_error();
}
$usuario = $_SESSION['s_username'];
$idpost = $_POST['idpost'];

$sql = "SELECT nombre, descripcion, link, distribuidor, idsistema FROM programa WHERE idpost=$idpost";
$result = $conn -> query($sql);
if ($result -> num_rows > 0) {
	while ($row = mysqli_fetch_assoc($result)) {
		echo "<h1>Nombre del programa: " . $row["nombre"] . "</h1><br>";
		echo "Descripcion: " . $row["descripcion"] . "<br>";
		echo "Link de descarga: " . $row["link"] . "<br>";
		echo "Distribuidor: " . $row["distribuidor"] . "<br>";
	}
}
$tamaño = 10;
$pag = $_GET["pagina"];

if (!$pag) {
	$comienzo = 0;
	$pag = 1;
} else {
	$comienzo = ($pag - 1) * $tamaño;
}
$resultado = mysql_query("SELECT COUNT(*) FROM comentarios");
$total_registros = mysql_num_rows($resultado);

$sql2 = "SELECT comentarios.coment, comentarios.fecha, usuario.nom_usuario FROM comentarios INNER JOIN post ON comentarios.idpost = post.idpost ORDER BY comentarios.fecha LIMIT $comienzo, $tamaño";
$result1 = $conn -> query($sql2);
$total_paginas = ceil($total_registros / $tamaño);

if ($result1 -> num_rows > 0) {
	echo "<table>";
	while ($row = mysqli_fetch_assoc($result1)) {
		echo "<tr><td>" . $row["coment"] . "</td><td>" . $row["fecha"] . "</td><td></tr>";
	}
	echo "</table>";
}

if (($pag - 1) > 0) {
	echo "<a href='comentarios.php?" . ($pag) . "'><Anterior</a>";
}

for ($i = 1; $i <= $total_paginas; $i++) {
	if ($pag == $i) {
		echo "<b><p>Pagina '.$pag.'</b> ";
	} else {
		echo "<a href='comentarios.php?pagina=$i'>$i</a> ";
	}
	if (($pag + 1) <= $total_paginas) {
		echo "<a href='lista-usuarios.php?pagina=" . ($num_pag + 1) . "'>Siguiente ></a>";
	}
}
?>