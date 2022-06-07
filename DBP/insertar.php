<?php
    include("base_datos.php");
    $BaseDatos = new base_datos("localhost", "root", "", "dbp_2022a_base");
    $BaseDatos->conectar();

    $dni = $_POST["dni"];
    $nom = $_POST["nombre"];
    $apel = $_POST["apellidos"];
    $ema = $_POST["email"];
    $tel = $_POST["telefono"];

    $BaseDatos->insCliente($dni, $nom, $apel, $ema, $tel);

    $BaseDatos->cerrar();
?>