
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
			$sql = "SELECT categoria, descripcion, idcategoria FROM categoria";
			$result = $conn->query($sql);
			if ($result->num_rows > 0) {
					 echo "<table> \n";
					while($row = mysqli_fetch_assoc($result))
					{
						echo "<tr> \n"; 
						$id=$row['idcategoria'];
						$cate=$row['categoria']; 
						$desc=$row['descripcion'];
			echo "<form name='form1' method='post' action='../programa/index.php'>";			echo "<td>".$id."</td> \n";
			echo "<input type='hidden' name='idcategoria' value='$id'>"; 
	        	echo "<td>".$cate."</td> \n"; 
			echo "<input type='hidden' name='categoria' value='$cate'>"; 
			echo "<td>".$desc."</td> \n";		
			echo "<td>"."<input type='submit' value='Seleccionar' id='boton' />";
			echo "</form>";
		   	echo "</tr> \n";
				$cont=1;
				$cont=$cont + 1; 
					}
							        echo "</table> \n"; 
			}
			

		?>
	
