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
					
					<h2 id="tituloAltaSoftware">Alta de Software</h2>
					
					<div id="contendorFormularioAltaSoftware">
						<!-- Agregar name e id's al formulario-->
						<form name="form1" method="post" action="../final/post.php">
							<p>
							  <label>Nombre</label>
							  <br />
							  <input type="text" name="nombre" id="nombre" />
							  <br /><br />
							  
							  <label>Distribuidor</label>
							  <br />
							  <input type="text" name="distribuidor" id="distribuidor" />
							  <br /><br />
							  
							  <label>Descripci&oacute;n</label>
							  <br />
							  <textarea name="descripcion" rows="3" id=""></textarea>
							  <br /><br />
							  
							  <label>Links de Descarga </label>
							  <br />
							  <input type="text" name="link" id="link" value="Link1" />
							  <br />
							  
							  <!--link de descarga 2--><br />
							  <label>Categoria</label>
							  <br />
							  <select name="categoria" size="1" class="categoria" id="">
							    
							    <option value="cat1">cat1</option>
							    <option value="cat2">cat2</option>
							    <option value="cat3">cat3</option>
							    <br>
							    
						      </select >
							  <!--Llenar Sistemas Operativos-->
							  <label><br>
							    <br>
							    Sistemas Operativos</label>
							  <br />
							  <select name="so" class="so" id="">
							    
							    <option value="Linux">Linux</option>
							    <option value="windows">Windows</option>
							    <option value="Mac_OS">Mac OS</option>
							    
						      </select >
							  <!--Validar para que al seleccionar un SO aparezcan las versiones-->
							  <select name="" class="SO" id="">
							    
							    <option value="">Versi&oacute;n</option>
							    
						      </select >
						  </p>
							<p>							  <br />
							  <input type="reset" name="cancelar" id="cancelar" value="Cancelar">
							  <br />
							  
							  <input type="submit" value="Enviar" id="botonEnviarAltaSoftware" />
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