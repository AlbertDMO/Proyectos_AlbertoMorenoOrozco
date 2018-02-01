<?php
	session_start();
	$sesionOff = $_GET["idSesion"];
	unset($_SESSION[$sesionOff]);
?>