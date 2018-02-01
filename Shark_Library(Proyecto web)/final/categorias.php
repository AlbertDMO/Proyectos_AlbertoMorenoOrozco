<?php
	session_cache_limiter();
	session_name('s_username');
	session_start();
	 $host_name  = "db566868929.db.1and1.com";
	 $database   = "db566868929";
     $user_name  = "dbo566868929";					 $password   = "rootroot";
	 $conn = new mysqli($host_name, $user_name, $password, $database);
			if (mysqli_connect_errno())
		    {	
				echo "Error al conectar con servidor MySQL: " . mysqli_connect_error();
			}
			$usuario = $_SESSION['s_username'];
			$idcategoria=$_POST['idcategoria'];
			$categoria=$_POST['categoria'];
			echo $idcategoria;
			echo "<br>".$categoria;
	$sql = "SELECT idprograma, nombre, descripcion FROM programa WHERE idcategoria = '$idcategoria'";
	$result = $conn->query($sql);
	if ($result->num_rows > 0) {
			 echo "<table> \n";
								while($row = mysqli_fetch_assoc($result))
								{
									echo "<tr> \n"; 
									$id=$row['idprograma'];
									$nombre=$row['nombre']; 
									$desc=$row['descripcion'];
						echo "<form name='form1' method='post' action='../Publicacion/publicacion.php'>";						echo "<td>".$id."</td> \n";
						echo "<input type='hidden' name='idprograma' value='$id'>";  
				        	echo "<td>".$nombre."</td> \n";
						echo "<input type='hidden' name='nombre' value='$nombre'>";   
					    	echo "<td>".$desc."</td> \n";
					    	echo "<td>".$categoria."</td> \n";
						echo "<td>"."<input type='submit' value='Seleccionar' id='boton' />";
						echo "</form>";
					    echo "</tr> \n";

								}
										        echo "</table> \n"; 
	}
	else {
		echo "No hay registros";
	}
	

?>