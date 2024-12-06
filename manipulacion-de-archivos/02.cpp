#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // Paso 1: Crear el archivo principal vacío si no existe
    ofstream archivoPrincipal("archivo_principal.txt", ios::out | ios::app);
    if (archivoPrincipal.is_open()) {
        archivoPrincipal.close(); // Cerrarlo inmediatamente si se puede abrir
    } else {
        cout << "No se pudo crear el archivo principal." << endl;
        return 1; // Salir si no se puede crear
    }

    // Paso 2: Crear un archivo secundario con información
    ofstream archivoSecundario("archivo_secundario.txt", ios::out); // Modo out para sobrescribir
    if (archivoSecundario.is_open()) {
        archivoSecundario << "Linea 1 del archivo secundario.\n";
        archivoSecundario << "Linea 2 del archivo secundario.\n";
        archivoSecundario << "Linea 3 del archivo secundario.\n";
        archivoSecundario.close();
    } else {
        cout << "No se pudo crear el archivo secundario." << endl;
        return 1; // Salir si no se puede crear el secundario
    }

    // Paso 3: Leer la información del archivo secundario
    ifstream lecturaArchivoSecundario("archivo_secundario.txt", ios::in);
    if (!lecturaArchivoSecundario.is_open()) {
        cout << "No se pudo abrir el archivo secundario para lectura." << endl;
        return 1;
    }

    // Paso 4: Sobrescribir el archivo principal con la información del secundario
    archivoPrincipal.open("archivo_principal.txt", ios::out); // Sobrescribir contenido
    if (archivoPrincipal.is_open()) {
        string linea;
        while (getline(lecturaArchivoSecundario, linea)) {
            archivoPrincipal << linea << "\n"; // Copiar cada línea del secundario al principal
        }
        archivoPrincipal.close();
        lecturaArchivoSecundario.close();
    } else {
        cout << "No se pudo abrir el archivo principal para sobrescribir." << endl;
        return 1;
    }

    cout << "El archivo principal se ha sobrescrito con éxito.\n";

    return 0;
}
