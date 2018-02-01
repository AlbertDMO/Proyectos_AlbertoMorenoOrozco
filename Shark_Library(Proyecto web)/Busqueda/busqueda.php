<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<link rel="shortcuticon" type="image/x-icon" href="./Imagenes/icono.ico" />
		<link rel="stylesheet" type="text/css" href="estiloBusqueda.css" />
		<title>Shark Library</title>
	</head>
	
	<body>
		
		<div id="fondoNegro">
			
			<div id="contenedorPrincipal">
				
				<div id="header">
					
					<div id="menu">
			
						<ul class="nav">
							<li><a href="./Inicio/inicio.html">Inicio</a></li>
							<li><a href="#">Perfil</a></li>
							<li><a href="#">Publicar</a></li>
							<li><a href="#">Salir</a></li>
						</ul>
			
					</div>
					
					<div id="Banner">
						<h2>Shark Library</h2>
					</div>
					
					<div id="contenedorLogo"></div>


					
					<<div id="Buscar">
						
						<p class="formularioBusqueda"> Buscar</p>
						
						<div id="busquedaCategoria">
							<select name="" class="SO" id="" method="POST" action="../Busqueda/busqueda.php" >
								
								<option value=>Categoria</option>
								<option value="cat2"></option>
								<option value="cat3"></option>
								
							</select >
						</div>		

			
						<form class="formularioBusqueda" method="POST" action="../Busqueda/busqueda.php">	
							<input type="text" />
							<input type="submit" id="Envio" value="Enviar" name="buscar" />
						</form>

						
					</div>
					
				</div>

				<div id="workArea">
				
					    <?php
							include('../final/buscador.php');
						?>	
			
					
				</div>
				
				<div id="footer">
					
					
					
				</div>				
				
			</div>
			
		</div>
		
		
	</body>
</html>

