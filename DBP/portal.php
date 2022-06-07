<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <div class="login-page">
        <div class="form">
            <form action="registrar_usuario.php" method="post" enctype="multipart/form-data" class="login-form">
                <input type="text" name="usuario" id="usuario" placeholder="usuario">
                <input type="text" name="clave" placeholder="clave">
                <label>Seleccione una foto: </label>
                <input type="file" name="foto" id="foto">
                <button id="btnRegistrar" class="btn"></button>
                <p class="message"> <a href="portal.php">Regresar a login</a></p>
            </form>
        </div>
    </div>
</body>
</html>