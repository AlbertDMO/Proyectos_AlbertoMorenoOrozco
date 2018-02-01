<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<link rel="shortcuticon" type="image/x-icon" href="./../Imagenes/icono.ico" />
		<link rel="stylesheet" type="text/css" href="estiloPublicacion.css" />
		<title>Shark Library</title>
	</head>
	
	<body>
		
		<div id="fondoNegro">
			
			<div id="contenedorPrincipal">
				
				<div id="header">
					
					<div id="menu">
			
						<ul class="nav">
							<li><a href="./../Inicio/inicio.html">Inicio</a></li>
							<li><a href="./../Perfil/perfil.html">Perfil</a></li>
							<li><a href="./../hacerPublicacion/publicacion.html">Publicar</a></li>
							<li><a href="./../Principio/principio.html">Salir</a></li>
						</ul>
			
					</div>
					
					<div id="Banner">
						<h2>Shark Library</h2>
					</div>
					
					<div id="contenedorLogo"></div>

					
					<div id="Buscar">
						
						<p class="formularioBusqueda"> Buscar</p>
						
						<form class="formularioBusqueda">	
							<input type="text" />
						</form>
						
					</div>
					
				</div>

				<div id="workArea">
					
					<div id="contenedorSoftware">
						
						<div id="contTextoSoftware">
                        <?php
							include('../final/ver_programa.php');
						?>
							
							
						</div>
						
						<div id="contImagenSoftware"></div>
						
					</div>

					<div id="linksDescarga">
						
						<div id="contTextLink">
							
							<h3 id="textoLinks">Links de Descarga:</h3>
							
						</div>
						
						
					</div>
					<!--IntroducirLinks-->
					<div id="ContenedorLinks">
						
						<div class="Links" id="l1">				</div>
						<div class="Links" id="l2">				</div>
						<div class="Links" id="l3">				</div>
						
					</div>
						
						
					<div id="contTextComentarios">
						
						<h2 id="textoComentarios">Comentarios</h2>
						
					</div>					
					
				</div>
				
				<div id="footer">
					<!--Contenedor Generico de un Comentario-->
					<div id="contComentario">
						
						<div id="usuarioComentario">	<h4>Usuario</h4>	</div>
						
						<div id="comentario">	<p> Comentario</p>	</div>
						
						
					</div>
					
					<!---->
					
					<div id="Comentar">
						
						<div id="contTextComentar">		<h2 id="tituloComentar">Comentar</h2>	</div>
						
						<form>
								
							<input type="text" name="" id="formComentar" value="" maxlength="240"/>	
							
							<input type="submit" value="Enviar" id="botonComentar" />
							
						</form>
						
					</div>
					
					
				</div>				
				
			</div>
			
		</div>
		
		
	</body>
</html>
