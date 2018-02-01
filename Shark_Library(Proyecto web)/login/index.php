<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html>
	
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<link rel="shortcuticon" type="image/x-icon" href="./Imagenes/icono.ico" />
		<link rel="stylesheet" type="text/css" href="estiloLogIn.css" />
		<title>Shark Library</title>
	</head>
	
	<body>
		
		<div id="fondoNegro">
			
			<div id="contenedorPrincipal">
				
				<div id="header">
					
					<div id="menu">
			
						<ul class="nav">
                        <li><a href="../index.html">Inicio</a></li>
							<li><a href="./../Perfil/perfil.php">Perfil</a></li>
							<li><a href="./../Publicacion/publicacion.php">Publicar</a></li>
							<li><a href="./../final/logout.php">Salir</a></li>
						</ul>
			
					</div>
					
					<div id="Banner">
						<h2>Shark Library</h2>
					</div>
					
					<div id="contenedorLogo"></div>

										
					<div id="Buscar">
						
						<p class="formularioBusqueda"> Buscar</p>
						
						<div id="busquedaCategoria">
							<select name="" class="SO" id="">
								
								<option value=>Categoria</option>
								<option value="cat2"></option>
								<option value="cat3"></option>
								
							</select >
						</div>		

			
						<form class="formularioBusqueda">	
							<input type="text" />
							<input type="submit" value="Enviar" id="Envio" />
						</form>

						
					</div>
				
					
				</div>

				<div id="workArea">
                <div id="formulario">
                <br><br><br><br>
                <form name="form1" method="post" action="../final/login_valid.php">
                <p><br><br>
                      <label>Nombre de usuario</label> 
                      <br><input name="nom_usuario" type="text" value="" maxlength="10">
                      <br><br>
                      <label>Constraseña</label> 
                      <br><input name="pass" type="password" value="" maxlength="10">
                    </p>
                    <p>
                      <input type="submit" name="submit" id="submit" value="Enviar">
                      <input type="reset" name="cancelar" id="cancelar" value="Cancelar">
                    </p>
				  </form>
                </div>
                
					
					
					
				</div>
				
				<div id="footer">
					
					
					
				</div>				
				
			</div>
			
		</div>
		
		
	</body>
</html>

