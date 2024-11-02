// herencia POO

#include <iostream>

using namespace std;

class Persona { // clase padre

    private: // atributos
        string nombre;
        int edad;
    
    public: // metodos
        Persona(string, int); // constructor
        void mostrarPersona(); // declarar el metodo

};

// crear una clase Alumno que herede de Persona
class Alumno: public Persona { // public se refiere a que la clase hija va a poder acceder a los metodos publicos de la clase Persona
    
    private: // atributos
        string codigoAlumno;
        float notaFinal;
    
    public: // metodos
        Alumno(string, int, string, float); // constructor: en los parentesis se ponen primero las referencias a los atributos de la superclase y despues las referencias a los atributos de la clase hija
        void mostrarAlumno();
};

Persona::Persona(string _nombre, int _edad) { // inicializar el constructor

    nombre = _nombre;
    edad = _edad;

}

Alumno::Alumno(string _nombre, int _edad, string _codigoAlumno, float _notaFinal): Persona(_nombre, _edad) { // constructor de Alumno, "Persona(_nombre, _edad)" se usa para heredar los atributos declarados en persona

    codigoAlumno = _codigoAlumno; // se declaran solo los atributos que no se heredan de la superclase
    notaFinal = _notaFinal; // se declaran solo los atributos que no se heredan de la superclase

} 

void Persona::mostrarPersona() { // declarar el metodo

    cout << "nombre: " << nombre << endl;
    cout << "edad: " << edad << endl;

}

void Alumno::mostrarAlumno() { // declarar el metodo

    mostrarPersona(); // heredar el metodo mostrar persona

    cout << "codigo alumno: " << codigoAlumno << endl;
    cout << "nota final: " << notaFinal << endl;

}

int main () {

    Alumno alumno1("joaquin", 20, "1231431", 10.0);

    alumno1.mostrarAlumno();

    return 0;
}