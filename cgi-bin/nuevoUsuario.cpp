#include <iostream>
#include <windows.h>
#include <lm.h>

#pragma comment(lib, "Netapi32.lib")

int main() {
    USER_INFO_1 ui;
    DWORD dwLevel = 1;
    DWORD dwError = 0;

    // Configura los datos del nuevo usuario
    ui.usri1_name = (LPWSTR)L"nuevoUsuario"; // Nombre del usuario
    ui.usri1_password = (LPWSTR)L"contraseñaSegura"; // Contraseña
    ui.usri1_priv = USER_PRIV_USER; // Privilegios del usuario (USER_PRIV_USER para usuario estándar)
    ui.usri1_home_dir = NULL;
    ui.usri1_comment = NULL;
    ui.usri1_flags = UF_SCRIPT | UF_DONT_EXPIRE_PASSWD; // El usuario debe usar script y la contraseña no expira
    ui.usri1_script_path = NULL;

    // Llama a NetUserAdd para crear el usuario
    NET_API_STATUS nStatus = NetUserAdd(NULL, dwLevel, (LPBYTE)&ui, &dwError);

    if (nStatus == NERR_Success) {
        std::wcout << L"Usuario creado con éxito" << std::endl;
    } else {
        std::wcout << L"Error al crear el usuario. Código de error: " << nStatus << std::endl;
    }

    return 0;
}
