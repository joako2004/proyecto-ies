#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // Escribir en el archivo
    ofstream archivo("archivo.txt", ios::out | ios::app); // Modo app para agregar contenido
    if (archivo.is_open()) {
        archivo << "Hola mundo \n";
        archivo.close(); // Cerrar archivo después de escribir
    } else {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }

    // Leer el archivo
    ifstream archivoLectura("archivo.txt", ios::in); // Modo in para leer
    if (archivoLectura.is_open()) {
        string linea;
        while (getline(archivoLectura, linea)) {
            cout << linea << endl; // Muestra la línea en consola
        }
        archivoLectura.close(); // Cerrar archivo después de leer
    } else {
        cout << "No se pudo abrir el archivo para leer." << endl;
    }

    return 0;
}
