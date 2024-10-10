#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    // Obtener el método de la solicitud (GET o POST)
    const char* request_method = getenv("REQUEST_METHOD");
    char* query_string = nullptr;

    if (request_method != nullptr && strcmp(request_method, "GET") == 0) {
        // Si el método es GET, leer la cadena de consulta de la URL
        query_string = getenv("QUERY_STRING");
    } 
    else if (request_method != nullptr && strcmp(request_method, "POST") == 0) {
        // Si el método es POST, leer el contenido de la entrada estándar (stdin)
        const char* content_length_str = getenv("CONTENT_LENGTH");
        int content_length = 0;
        if (content_length_str != nullptr) {
            content_length = atoi(content_length_str); // Convertir a entero
        }
        query_string = new char[content_length + 1];  // Reservar espacio para el contenido POST
        cin.read(query_string, content_length);       // Leer desde stdin
        query_string[content_length] = '\0';          // Asegurarse de que sea una cadena terminada
    }


    // Inicializar variables
    char nombre[50] = "";
    char apellido[50] = "";
    int edad;

    if (query_string != nullptr) {
        // Parsear los parámetros
        char* param = strdup(query_string);  // Hacer una copia de la cadena de consulta
        char* token = strtok(param, "&");    // Separar los parámetros
        while (token != nullptr) {
            if (sscanf(token, "n=%49s", nombre) == 1) {  }
            if (sscanf(token, "a=%49s", apellido) == 1) {  }
            if (sscanf(token, "e=%d", &edad) == 1) {  }
            token = strtok(nullptr, "&");    // Continuar con el siguiente parámetro
        }
        free(param);  // Liberar la memoria
    }

    // Generar la respuesta HTTP
    cout << "Content-Type: text/plain\n\n";
    cout << "Tu nombre es <b>" << nombre << "</b> ";
    cout << "<b>" << apellido << "</b>";
    cout << "<p>Y tienes " << edad << " años.</p>";


    return 0;
}