// clases en c++

#include <iostream>
#include <string>
using namespace std;

class Persona {

    private: // atributos
        int edad;
        string nombre;

    public: // metodos
        Persona(int, string); // constructor
        void leer();
        void correr();
};

Persona::Persona(int _edad, string _nombre) { // constructor: inicializa los atributos de la clase
    edad = _edad;
    nombre = _nombre;
}

// declarar los metodos 
void Persona::leer() {
    cout << "soy " << nombre << " y estoy leyendo" << endl;
}

void Persona::correr() {
    cout << "soy " << nombre << " y estoy corriendo" << endl;
}

int main () {

    Persona p1 = Persona(19, "joaquin");

    Persona p2(23, "claudio");

    Persona p3(21, "juan");

    p1.leer();
    p1.correr();

    p2.correr();

    p3.leer();

    return 0;
}