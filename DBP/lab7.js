var i = 0;
var getID = () => ++i;
var isEmpty = (str) => str.trim() === '';
var contStr = (str) => {
    if(str.length < 3){ return true;}
    return false;
}

var comprobarEmail = (str) => {
    let x=0;
    let y = 0;
    for(let i=0;i<str.length;i++){
        if(str[i] == "@"){
            y++;
        }
        if(str[i] == "."){
            x++;
        }
    }
    if(x >= 1 && y == 1){return true;}
    return false;
}

function validar(nombreVal, apellidoVal, emailVal, telefonoVal){
    if(isEmpty(nombreVal) || isEmpty(apellidoVal) || isEmpty(emailVal) || isEmpty(telefonoVal)){
        alert("Todos los campos son obligatorios");
        return false;
    }
    if(dniVal < 100000000 || dniVal > 1000000000){
        alert("Numero de DNI inválido");
        return false;
    }
    
    if(contStr(nombreVal) || contStr(apellidoVal)){
        alert("Nombres o apellidos inválidos");
        return false;
    }
    
    if(comprobarEmail(emailVal)){
        alert("Email inválido");
        return false;
    }

    if(telefonoVal < 100000000 || telefonoVal > 1000000000){
        alert("Numero de telefono inválido");
        return false;
    }
    return true;
}

function agregar(){
    
    var nombre  = document.getElementById('nombre');
    var apellido = document.getElementById('apellido');
    var email = document.getElementById('email');
    var telefono = document.getElementById('telefono'); 
    var dni = document.getElementById('dni');

    nombreVal = nombre.value;
    apellidoVal = apellido.value;
    emailVal = email.value;
    telefonoVal = telefono.value;
    dniVal = dni.value;

    if(validar(dniVal , nombreVal,apellidoVal, emailVal, telefono)){

        let xhr = new XMLHttpRequest();
        let data = document.getElementById("registro");
        let form = new FormData(data);

        xhr.open('POST',"insertar.php");
        xhr.onload;
        xhr.send(form);

        /*
        var contenido = document.getElementById("contenido");
        if(window.XMLHttpRequest){
            ajax = new XMLHttpRequest();
        }
        else{
            ajax = new ActiveXObject("Microsoft.XMLHTTP");
        }

        ajax.onreadystatechange = function() {
            if(ajax.readyState == 4 && ajax.status == 2090){
                contenido.innerHTML = ajax.responseText;
            } 
            else{
                contenido.innerHTML = "<img width='50' height='50' src='cargando.gif'>";
            }   

            ajax.open("POST", "insertar.php");
            ajax.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
            ajax.send("dni="+dniVal+ "&nombre=" + nombreVal + "&apellido=" + apellidoVal + "&email=" + emailVal + "&telefono=" + telefonoVal);
        }
        */
    }
}   

function asignar(){
    boton_agr = document.getElementById('nuevo');
    boton_agr.addEventListener("click" , agregar);
    
}

window.addEventListener("load", asignar);