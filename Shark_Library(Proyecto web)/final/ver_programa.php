<?php
		session_cache_limiter();
		session_name('s_username');
		session_start();
	 	$host_name  = "db566868929.db.1and1.com";
	 	$database   = "db566868929";
	    	$user_name  = "dbo566868929";				
	 	$password   = "rootroot";
	    	$conn = new mysqli($host_name, $user_name, $password, $database);
		if (mysqli_connect_errno())
	    {	
			echo "Error al conectar con servidor MySQL: " . mysqli_connect_error();
		}
		$usuario = $_SESSION['s_username'];
		$idprograma=$_POST['idprograma'];
		$sql = "SELECT nombre, descripcion, link, distribuidor, idsistema FROM programa WHERE idprograma='$idprograma'";
		$result = $conn->query($sql);
		if ($result->num_rows > 0) {
	    		while($row = mysqli_fetch_assoc($result)) {
				echo "<h2 class='textoSoftware'>Nombre Software</h2> "."<h2>".$row["nombre"]."</h2>";
				echo "<h3>Descripci&oacute;n</h3>"."<h3>".$row["descripcion"]."</h3>";
				echo "Link de descarga: ".$row["link"]."<br>";
				echo "Distribuidor: ".$row["distribuidor"]."<br>";
	    		}
		} 
	
	$sql2 = "SELECT comentarios.coment, comentarios.fecha, usuario.nom_usuario FROM comentarios INNER JOIN post ON comentarios.idpost = post.idpost";
	$result1 = $conn->query($sql2);
	if ($result1->num_rows > 0) {
	    while($row = mysqli_fetch_assoc($result1)) {

	    }
	} 	

?>