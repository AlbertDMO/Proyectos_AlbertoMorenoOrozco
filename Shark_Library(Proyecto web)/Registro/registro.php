<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"><head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<link rel="shortcuticon" type="image/x-icon" href="./../Imagenes/icono.ico" />
		<link rel="stylesheet" type="text/css" href="estiloRegistro.css" />
        
		<title>Shark Library</title>
	</head>
	
	<body>
		
		<div id="fondoNegro">
			
			<div id="contenedorPrincipal">
				
				<div id="header">
					
					<div id="menu">
			
						<ul class="nav">
							<li><a href="../index.html">Inicio</a></li>
							<li><a href="#">Perfil</a></li>
							<li><a href="#">Publicar</a></li>
							<li><a href="#">Salir</a></li>
						</ul>
			
					</div>
					
					<div id="Banner">
						<h2>Shark Library</h2>
					</div>
					
					<div id="contenedorLogo"></div>
					
				</div>

				<div id="workArea">
					
					<h2 id="tituloRegistro">Registro</h2>
					
					<!-- Los formularios aun no tienen name ni id-->
					<div id="registro">
						<form name="form1" method="post" action="../final/usuario.php">
							<label>Nombre</label>
							<br />
							<input type="text" name="nombre" id="nombre" />
							<br /><br />
							
							<label>Apellidos</label>
							<br />
							<input type="text" name="apellido" id="apellido" />
							<br /><br />
							
							<label>Pa&iacute;s</label>
							<br />
							<input type="text" name="pais" id="pais" />
							<br /><br />
							
							<label>Nombre de Usuario</label>
							<br />
							<input type="text" name="nombre_usuario" id="nombre_usuario" />
							<br /><br />
							
							<label>Contraseña</label>
							<br />
							<input type="password" name="pass" id="pass" />
							<br /><br />
							
							<label>Repetir Contraseña</label>
							<br />
							<input type="password" name="cpass" id="cpass" />
							<br /><br />
                            
                            <label>e-mail</label>
							<br />
							<input type="text" name="mail" id="mail" />
							<br /><br />
                            <label>Fecha de nacimiento</label>
                            <input type="date" name="fecha" id="fecha"/>
                            <br>
                           <br>

							
							<input type="submit" name="" value="Enviar" id="botonEnviar" /><input name="Cancelar" type="reset" value="Cancelar">
								
						</form>
					</div>
												
				</div>
				
				<div id="footer">
					
					
					
				</div>				
				
			</div>
			
		</div>
		
		
	</body>
</html>
