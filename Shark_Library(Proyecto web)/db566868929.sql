-- phpMyAdmin SQL Dump
-- version 4.1.14.8
-- http://www.phpmyadmin.net
--
-- Servidor: db566868929.db.1and1.com
-- Tiempo de generación: 26-02-2015 a las 20:53:26
-- Versión del servidor: 5.1.73-log
-- Versión de PHP: 5.4.36-0+deb7u3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `db566868929`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `categoria`
--

CREATE TABLE IF NOT EXISTS `categoria` (
  `idcategoria` int(11) NOT NULL,
  `categoria` varchar(45) COLLATE latin1_spanish_ci DEFAULT NULL,
  `descripcion` varchar(200) COLLATE latin1_spanish_ci DEFAULT NULL,
  PRIMARY KEY (`idcategoria`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci;

--
-- Volcado de datos para la tabla `categoria`
--

INSERT INTO `categoria` (`idcategoria`, `categoria`, `descripcion`) VALUES
(0, 'cat1', 'cat1'),
(1, 'cat2', 'cat2'),
(2, 'cat3', 'cat3');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `comentarios`
--

CREATE TABLE IF NOT EXISTS `comentarios` (
  `idpost` int(11) NOT NULL,
  `coment` longtext COLLATE latin1_spanish_ci NOT NULL,
  `idusuario` int(11) NOT NULL,
  `fecha` date DEFAULT NULL,
  `idcomentario` int(11) NOT NULL,
  PRIMARY KEY (`idcomentario`),
  KEY `idpost_idx` (`idpost`),
  KEY `idusuario_idx` (`idusuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `perfil`
--

CREATE TABLE IF NOT EXISTS `perfil` (
  `idperfil` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(10) COLLATE latin1_spanish_ci NOT NULL,
  `apellido` varchar(15) COLLATE latin1_spanish_ci NOT NULL,
  `pais` varchar(10) COLLATE latin1_spanish_ci NOT NULL,
  `mail` varchar(15) COLLATE latin1_spanish_ci NOT NULL,
  `idusuario` int(11) NOT NULL,
  `fecha_nacimiento` date DEFAULT NULL,
  PRIMARY KEY (`idperfil`),
  UNIQUE KEY `idusuario_UNIQUE` (`idperfil`),
  KEY `idusuario_idx` (`idusuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=12 ;

--
-- Volcado de datos para la tabla `perfil`
--

INSERT INTO `perfil` (`idperfil`, `nombre`, `apellido`, `pais`, `mail`, `idusuario`, `fecha_nacimiento`) VALUES
(1, 'b', 'b', 'b', 'b', 0, '2015-02-01'),
(7, 'c', 'c', 'c', 'c', 6, '2015-02-01'),
(9, 'Eric', 'Montes de Oca', 'MÃ©xico', 'eric.mdoj8', 8, '0000-00-00'),
(10, 'aa', 'aa', 'aa', 'oo', 9, '2015-02-01'),
(11, 'aa', 'aa', 'aa', 'aa', 10, '2015-02-01');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `post`
--

CREATE TABLE IF NOT EXISTS `post` (
  `idpost` int(11) NOT NULL AUTO_INCREMENT,
  `idusuario` int(11) NOT NULL,
  `fecha` date NOT NULL,
  `idcategoria` int(11) DEFAULT NULL,
  PRIMARY KEY (`idpost`),
  UNIQUE KEY `idpost_UNIQUE` (`idpost`),
  KEY `idpost_idx` (`idcategoria`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=6 ;

--
-- Volcado de datos para la tabla `post`
--

INSERT INTO `post` (`idpost`, `idusuario`, `fecha`, `idcategoria`) VALUES
(1, 6, '0000-00-00', 0),
(4, 6, '0000-00-00', 0),
(5, 6, '0000-00-00', 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `programa`
--

CREATE TABLE IF NOT EXISTS `programa` (
  `idpost` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(10) COLLATE latin1_spanish_ci NOT NULL,
  `descripcion` varchar(200) COLLATE latin1_spanish_ci NOT NULL,
  `link` varchar(45) COLLATE latin1_spanish_ci NOT NULL,
  `idprograma` int(11) NOT NULL,
  `distribuidor` varchar(45) COLLATE latin1_spanish_ci DEFAULT NULL,
  `idsistema` int(11) DEFAULT NULL,
  `idcategoria` int(11) DEFAULT NULL,
  PRIMARY KEY (`idprograma`),
  KEY `idpost_idx` (`idpost`),
  KEY `idsistema_idx` (`idsistema`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=2 ;

--
-- Volcado de datos para la tabla `programa`
--

INSERT INTO `programa` (`idpost`, `nombre`, `descripcion`, `link`, `idprograma`, `distribuidor`, `idsistema`, `idcategoria`) VALUES
(1, 'a', 'a', 'a', 0, 'a', 3, 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `sistemas`
--

CREATE TABLE IF NOT EXISTS `sistemas` (
  `idsistemas` int(11) NOT NULL,
  `so` varchar(45) COLLATE latin1_spanish_ci DEFAULT NULL,
  `idcategoria` int(11) NOT NULL,
  PRIMARY KEY (`idsistemas`),
  KEY `idcategoria_idx` (`idcategoria`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci;

--
-- Volcado de datos para la tabla `sistemas`
--

INSERT INTO `sistemas` (`idsistemas`, `so`, `idcategoria`) VALUES
(1, 'windows', 1),
(2, 'Mac_OS', 1),
(3, 'Linux', 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuario`
--

CREATE TABLE IF NOT EXISTS `usuario` (
  `idusuario` int(11) NOT NULL AUTO_INCREMENT,
  `pass` varchar(200) COLLATE latin1_spanish_ci NOT NULL,
  `nom_usuario` varchar(10) COLLATE latin1_spanish_ci NOT NULL,
  `tipo_usuario` int(11) NOT NULL,
  PRIMARY KEY (`idusuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=11 ;

--
-- Volcado de datos para la tabla `usuario`
--

INSERT INTO `usuario` (`idusuario`, `pass`, `nom_usuario`, `tipo_usuario`) VALUES
(1, '0cc175b9c0f1b6a', 'a', 1),
(6, '4a8a08f09d37b73795649038408b5f33', 'c', 1),
(8, '26cf2d78b7cdfca7ad9ea45d464676b5', 'Juarez8', 1),
(10, 'ccee5504c9d889922b101124e9e43b71', 'aa', 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `version`
--

CREATE TABLE IF NOT EXISTS `version` (
  `idversion` int(11) NOT NULL,
  `idsistema` int(11) NOT NULL,
  `version` varchar(45) COLLATE latin1_spanish_ci DEFAULT NULL,
  PRIMARY KEY (`idversion`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci;

--
-- Volcado de datos para la tabla `version`
--

INSERT INTO `version` (`idversion`, `idsistema`, `version`) VALUES
(1, 1, 'windows_xp'),
(2, 1, 'windows7'),
(3, 1, 'windows8'),
(4, 2, 'Yosemite'),
(5, 2, 'Mavericks'),
(6, 2, 'Mountan_lion'),
(7, 2, 'Lion'),
(8, 3, 'Fedora20');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
