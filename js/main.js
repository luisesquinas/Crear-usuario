

document.getElementById('registroUsuario').onsubmit = async function (e) {
    e.preventDefault();

    nombre = document.getElementById('usuario').value;
    apellido =  document.getElementById('apellido').value;
    edad =  document.getElementById('edad').value;
    
    response = await fetch(`/cgi-bin/funciones.cgi`,{
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        body: new URLSearchParams({
            'n':nombre,
            'a':apellido,
            'e':edad
        })
    });
    data = await response.text();
    document.getElementById('resultado').innerHTML = decodeURI(data);
};
