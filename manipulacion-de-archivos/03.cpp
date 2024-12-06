#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main () {
    
    vector <int> numeros;

    for (int i = 0; i < 5; i++) {
        numeros.push_back(i);
    }

    ofstream archivoPrincipal("archivo_principal.txt", ios::out | ios::app);
    if (archivoPrincipal.is_open()) {

        for (int i = 0; i < 5; i++) {
            archivoPrincipal << i << endl;
    }

        archivoPrincipal.close(); 
    } 

    // Abrir el archivo en modo de salida (ios::out) para sobrescribir
    ofstream archivo("archivo_principal.txt", ios::out);

    if (archivo.is_open()) {
        for (int i = 0; i < 5; i++) {
            archivo << i << endl;
    }
        archivo.close(); // Cerrar el archivo después de escribir
    }

    return 0;
}