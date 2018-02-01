<?php
	
	$host_name  = "db566868929.db.1and1.com";
					    $database   = "db566868929";
					    $user_name  = "dbo566868929";
					    $password   = "rootroot";
					    $conn = new mysqli($host_name, $user_name, $password, $database);
					    if (mysqli_connect_errno())
					    {
					    echo "Error al conectar con servidor MySQL: " . mysqli_connect_error();
					    }
	if ($_POST['nom_usuario']) {
//Comprobacion del envio del nombre de usuario y password
		$nom_usuario=$_POST['nom_usuario'];
		$pass=$_POST['pass'];
		$pass_cif;
			$pass_cif=md5($pass);
			$sql ="SELECT nom_usuario, pass FROM usuario WHERE nom_usuario = '$nom_usuario'";
			$result = $conn->query($sql);
			if ($result->num_rows > 0) {
			    while($row = mysqli_fetch_assoc($result)) {
			        if($row["pass"] == $pass_cif) {
								$_SESSION["s_username"] = $row["nom_usuario"];
								session_name('s_username');								session_start(); 
								header('Location: ../Perfil/perfil.php');

							}
							else{
									header('Error: Datos incorrectos', false, 301);
									header('Location: ./login/logIn.php');

								}
			    }
			} else {
				header('Error: Datos incorrectos', false, 301);
				header('Location: ./login/logIn.php');
			}
	}
	else {
		echo "Datos no enviados";
		header('Location: ./login/logIn.php');


	}
?>