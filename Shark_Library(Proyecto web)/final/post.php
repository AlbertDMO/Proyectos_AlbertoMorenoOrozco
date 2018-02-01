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
	$nombre=$_POST['nombre'];
	$descripcion=$_POST['descripcion'];
	$link=$_POST['link'];
	$distribuidor=$_POST['distribuidor'];
	$categoria=$_POST['categoria'];
	$so=$_POST['so'];
	$fecha=date("d/m/Y");
	$idusuario;
	$idcategoria;
	$idsistemas;
	
	if ($nombre == NULL | $descripcion == NULL | $link == NULL | $distribuidor == NULL)
	{
		echo "Error 409: Hay un campo vacío";	
	}
	else {
		if (strlen($nombre)>10) {
			echo "Error 410: Nombre del programa demasiado largo, usa 10 caracteres a lo más";
		}
		else {
			if (strlen($descripcion)>200) {
				echo "Error 411: Descripcion del programa demasiado largo, usa 200 caracteres a lo más";
			}
			else {
				if (strlen($distribuidor)>45) {
					echo "Error 412: Distribuidor del programa demasiado largo, usa 45 caracteres a lo más";
				}
				else {
								$sql = "SELECT idusuario, nom_usuario FROM usuario WHERE nom_usuario = '$usuario'";
								$result = $conn->query($sql);
								if ($result->num_rows > 0) {
								    while($row = mysqli_fetch_assoc($result)) {
										$idusuario = $row["idusuario"];
								  
								    }
								}
								else {
									echo "error";
								}
								$sql2 = "SELECT idcategoria FROM categoria WHERE categoria = '$categoria'";
								$result1 = $conn->query($sql2);
								if ($result1->num_rows > 0) {
								    while($row = mysqli_fetch_assoc($result1)) {
										$idcategoria = $row["idcategoria"];
								  
								    }
								}
								else {
									echo "error";
								}
								$sql0 = "SELECT idsistemas FROM sistemas WHERE so = '$so'";
								$result0 = $conn->query($sql0);
								if ($result1->num_rows > 0) {
								    while($row = mysqli_fetch_assoc($result0)) {
										$idsistemas = $row["idsistemas"];
								  
								    }
								}
								else {
									echo "error";
								}
								$query1 = "INSERT INTO post (idusuario, idcategoria) VALUES('$idusuario','$idcategoria')";
								if ($conn->query($query1) === TRUE) {
								    echo "New record created successfully";
									$last_id = $conn->insert_id;

								} else {
								    echo "Error: " . $query1 . "<br>" . $conn->error;
								}
								$query = "INSERT INTO programa (idpost, nombre, descripcion, link,  distribuidor, idsistema, idcategoria) VALUES('$last_id','$nombre','$descripcion', '$link', '$distribuidor', '$idsistemas', '$idcategoria')";
								if ($conn->query($query) === TRUE) {
										 echo "New record created successfully";
								} else {
								    echo "Error: " . $query . "<br>" . $conn->error;
									}
								echo "El programa ha sido registrado de manera satisfactoria.";
							}
			}
		}
	}
	
	
	
?>