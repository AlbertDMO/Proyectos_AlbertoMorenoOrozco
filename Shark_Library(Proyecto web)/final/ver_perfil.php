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
	if(isset($_SESSION['s_username']))
	{
		
		$sql = "SELECT perfil.nombre, perfil.apellido, perfil.pais, perfil.mail, perfil.fecha_nacimiento, usuario.nom_usuario FROM perfil INNER JOIN usuario ON perfil.idusuario = usuario.idusuario WHERE nom_usuario = '$usuario'";
		$result = $conn->query($sql);
		if ($result->num_rows > 0) {
		    while($row = mysqli_fetch_assoc($result)) {
				echo "<h1>Nombre de usuario: ".$row["nom_usuario"]."</h1><br>";
				echo "Nombre: ".$row["nombre"]."<br>";
				echo "Apellido: ".$row["apellido"]."<br>";
				echo "Pais: ".$row["pais"]."<br>";
				echo "Correo: ".$row["mail"]."<br>";
				echo "Fecha nacimiento: ".$row["fecha_nacimiento"]."<br>";
		    }
		} 
	}
	else {
		echo "No a iniciado sesion";
	}
?>