<?php 
    session_start();

    if(!isset($_SESSION["usuario"])){
        header("Location: portal.php");
        exit();
    }

    include("base_datos.php");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <div class="contenedor">
        <h2>Bienvenido <? echo $_SESSION["usuario"] ?></h2>
        <form id="registro">
            <table class="tabla">
                <tr >
                    <td  colspan="2"><input type="number" id="dni" name="dni" placeholder="DNI"></td>
                </tr>
                <tr>
                    <td><input type="text" id="nombre" name="nombre" placeholder="Nombre..." ></td>
                    <td><input type="text" id="apellido" name="apellido" placeholder="Apellido..."></td>
                </tr>
                <tr>
                    <td><input type="text" id="email" name="email" placeholder="Email..." class="large"> </td>
                    <td><input type="number" id="telefono" name="telefono" placeholder="Telefono..." class="large"></td> 
                </tr>
                
            </table>      
            <input type="button" value="Agregar" id="nuevo" <?php if($_SESSION["usuario"]!=['ehinojosa']) {echo "disabled";} ?>>
        </form>
    </div>


    <div class="registro">
        <h2>Clientes Registrados</h2>
        <table id="tablausers" class="tabla tabla2">
            <thead class="thead">
                <tr>
                    <th class="cabezera">DNI</th>
                    <th class="cabezera">Nombre</th>
                    <th class="cabezera">Apellido</th>
                    <th class="cabezera mail">Email</th>
                    <th class="cabezera">Telefono</th>
                </tr>
            </thead>
            <tbody id="contenido" class="tbody">
                <?php
                $BaseDatos = new base_datos('localhost','root','','dbp_2022_a_base');
                $BaseDatos->conectar();

                $clientes = $BaseDatos->getclientes();
                if(!is_null($clientes)){
                    while($row = mysqli_fetch_assoc($clientes)){
                        echo "<tr class='tr'>";
                        echo "<td class='td'>".$row['dni']."</td>";
                        echo "<td class='td'>".$row['nombre']."</td>";
                        echo "<td class='td'>".$row['apellido']."</td>";
                        echo "<td class='td'>".$row['email']."</td>";
                        echo "<td class='td'>".$row['telefono']."</td>";
                        echo "</tr>";
                    }
                }
                $BaseDatos->cerrar();
                ?>
            </tbody>
        </table>    
    </div>
    
    <script src="prac7.js"></script>
    
</body>
</html>
  