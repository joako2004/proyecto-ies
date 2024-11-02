// polimorfismo

#include <iostream>

using namespace std;

class Persona {

    private: // atributos
        string nombre; 
        int edad;
    
    public: // metodos
        Persona(string, int); // constructor
        virtual void mostrar(); // la palabra virtual hace referencia a que se trata de un metodo que aplica polimorfismo, solo se pone en la superclase
};

class Alumno: public Persona {
    private: // atributos
        float notaFinal;
    
    public: // metodos
        Alumno(string, int, float);
        void mostrar(); // aqui se aplica polimorfismo ya que si se muestra desde persona mostrara una cosa y si se muestra desde alumno mostrara otra
};

class Profesor: public Persona {
    private:
        string materia;

    public:
        Profesor(string, int, string);
        void mostrar();
};

Persona::Persona(string _nombre, int _edad) { // inicializar el constructor de la clase Persona
    nombre = _nombre;
    edad = _edad;
}

void Persona::mostrar() { // declarar el metodo "mostrar"
    cout << "nombre: " << nombre << endl;
    cout << "edad: " << edad << endl;
}

Alumno::Alumno(string _nombre, int _edad, float _notaFinal) : Persona(_nombre, _edad) { // declarar que Alumno hereda de Persona
    notaFinal = _notaFinal;
}

Profesor::Profesor(string _nombre, int _edad, string _materia) : Persona(_nombre, _edad) { // declarar que Profesor hereda de Persona
    materia = _materia;
}

void Alumno::mostrar() {  // declarar el metodo "mostrar"
    Persona::mostrar();
    cout << "nota final: " << notaFinal << endl;
}

void Profesor::mostrar() {  // declarar el metodo "mostrar"
    Persona::mostrar();
    cout << "materia: " << materia << endl;
}

int main () {

    // Persona persona1 ("joaquin", 19);
    // Alumno alumno1 ("claudio", 23, 10.0);
    // Profesor profesor1 ("ricardo", 24, "programacion");

    // persona1.mostrar();
    // alumno1.mostrar();
    // profesor1.mostrar();

    // crear objetos de tipo puntero

    Persona *vector[3];

    vector[0] = new Persona ("joaquin", 19);
    vector[1] = new Alumno ("claudio", 23, 10.0);
    vector[2] = new Profesor ("ricardo", 24, "programacion");

    vector[0] -> mostrar(); // sintaxis para mostrar objetos desde punteros
    vector[1] -> mostrar(); // sintaxis para mostrar objetos desde punteros
    vector[2] -> mostrar(); // sintaxis para mostrar objetos desde punteros

    return 0;
}