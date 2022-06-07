<?php
    class base_datos{
        private $host;
        private $usua;
        private $pass;
        private $bd;

        private $conexion;
        
        function __construct($host,$usua,$pass,$bd){
            $this->host = $host;
            $this->usua = $usua;
            $this->pass = $pass;
            $this->bd= $bd;
        }
        function conectar(){
            $this->conexion = mysqli_connect($this->host,$this->usua,$this->pass,$this->bd);
            $this->conexion->set_charset("utf8");
            if(mysqli_connect_errno()){
                echo "error al conectarse";
            }
        }
        function getclientes(){
            $resul = mysqli_query($this->conexion, "SELECT * FROM clientes");
            $error = mysqli_error($this->conexion);
            if(empty($error)){
                if(mysqli_num_rows($resul) > 0){
                    return $resul;
                }
            }
            else{
                echo "error al obtener clientes";
            }
            return null;

        }
        //COMPROBACIONES 
        function comprobar($dni, $nom, $apel,$email, $tel){
            $email = trim($email);
            if( (strlen(trim($dni))) == 9 &&  
                (strlen(trim($nom))) >= 3 && 
                (strlen(trim($apel))) >= 3 && 
                (strlen(trim($tel))) == 9 ){
                    $y = 0;
                    $x = 0;
                    for($i=0;$i<strlen($email);$i++){
                        if($email[$i] == '@'){
                            $y++;
                        }
                        if($email[$i] == '.'){
                            $x++;
                        }
                    }
                    if($x >= 1 && $y >= 1){return true;}
                }
            return false;
        }

        function insCliente($dni, $nom, $apel,$email,$tel){
            if($this->comprobar($dni, $nom, $apel,$email, $tel)){
                mysqli_query($this->conexion, "INSERT INTO clientes(dni,nombre,apellido,email,telefono) VALUES ('$dni','$nom','$apel','$email','$tel')");
                $error = mysqli_error($this->conexion);
                if(empty($error)){
                    return true;
                }
                echo "error al ingresar cliente";
                return false;
            }
        }
        
        function getUsuarios(){
            $resul = mysqli_queri($this->conexion, "SELECT * FROM usuario");
            $error = mysqli_error($this->conexion);
            if(empty($error)){
                if(mysqli_num_rows($resul > 0)){
                    return $resul;
                }
            }
            else{
                echo "error al obtener usuario";
            }
            return null;
        }

        function insUsuario($usua,$clav){
            mysqli_query($this->conexion, "INSERT INTO usuario VALUES ('".$usua."','".$clav."')");
            $error = mysqli_error($this->conexion);
            if(empty($error)){
                return true;
            }
            return false;
        }
        function cerrar(){
            mysqli_close($this->conexion);
        }
    }

?>