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
$nombre_usuario = $_POST['nombre_usuario'];
$pass = $_POST['pass'];
$cpass = $_POST['cpass'];
$tipo_usuario = $_POST['tipo_usuario'];
$nombre = $_POST['nombre'];
$apellido = $_POST['apellido'];
$pais = $_POST['pais'];
$mail = $_POST['mail'];
$fecha_nacimiento = $_POST['fecha'];

if ($nombre_usuario == NULL | $pass == NULL | $nombre == NULL | $apellido == NULL | $pais == NULL | $mail == NULL) {
	echo "Error 401: Hay un campo vacío";
} else {
	if (strlen($nombre_usuario) > 10) {
		echo "Error 403: Nombre de usuario demasiado largo, usa 10 caracteres a lo más";
	} else {
		if (strlen($pass) > 15) {
			echo "Error 404: Contraseña demasiado larga, usa 15 caracteres a lo más";
		} else {
			if (strlen($nombre) > 10) {
				echo "Error 405: Nombre demasiado largo, usa 10 caracteres a los más";
			}
			if (strlen($apellido) > 15) {
				echo "Error 406: Apellido demasiado largo, usa 15 caracteres a lo más";
			} else {
				if (strlen($pais) > 10) {
					echo "Error 407: Pais demasiado largo, usa 10 caracteres a lo más";

				} else {
					if (strlen($mail) > 15) {
						echo "Error 408: Mail demasiado largo, usa 15 caracteres a lo más";

					} else {
						if ($pass != $cpass) {
							echo "Error 402: Las contraseñas no coinciden";
						} else {
							$checkuser = mysqli_query("SELECT nom_usuario FROM usuario WHERE nom_usuario='$nombre_usuario'");
							$username_exist = mysqli_num_rows($checkuser);
							$checkemail = mysqli_query("SELECT mail FROM usuario WHERE mail='$mail'");
							$email_exist = mysqli_num_rows($checkemail);
							if ($email_exist > 0 | $username_exist > 0) {
								echo "EL nombre de usuario o la cuenta de correo estan ya en uso";
							} else {
								$pass=md5($pass);
								$query = "INSERT INTO usuario (nom_usuario, pass, tipo_usuario) VALUES('$nombre_usuario','$pass','1')";
								if ($connect->query($query) === TRUE) {
								    echo "New record created successfully";
									$last_id = $connect->insert_id;

								} else {
								    echo "Error: " . $query . "<br>" . $connect->error;
								}
								$query1 = "INSERT INTO perfil (nombre, apellido, pais, mail, idusuario, fecha_nacimiento) VALUES('$nombre','$apellido','$pais', '$mail','$last_id', '$fecha_nacimiento')";
								if ($connect->query($query1) === TRUE) {
										echo "El usuario $usuario ha sido registrado de manera satisfactoria.";
								} else {
									    echo "Error: " . $query1 . "<br>" . $connect->error;
								}
							}
						}
					}
				}

			}
		}

	}

}
?>