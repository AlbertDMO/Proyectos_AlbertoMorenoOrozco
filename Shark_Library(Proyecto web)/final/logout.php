<?php
	function logout(&$s_username) {
			session_start();
			$_SESSION = array();
			unset($_SESSION["s_username"]);  
			header("Location: index.php");
	}
	
?>