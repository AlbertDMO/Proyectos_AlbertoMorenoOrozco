					<?php
				    $host_name  = "db566868929.db.1and1.com";
				    $database   = "db566868929";
				    $user_name  = "dbo566868929";
				    $password   = "rootroot";

				    $connect = mysqli_connect($host_name, $user_name, $password, $database);
				    if (mysqli_connect_errno())
				    {
				    echo "Error al conectar con servidor MySQL: " . mysqli_connect_error();
				    }
				?>