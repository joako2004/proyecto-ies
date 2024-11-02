// metodos constructores y modificadores (getters y setters)

#include <iostream>

using namespace std;

class Punto {

    private: // atributos
        int x; 
        int y;
    
    public: // metodos
        Punto(); // metodo constructor
        void setPunto(int, int); // declarar el metodo setter
        
        int getPuntoX(); // declarar los metodos getter
        int getPuntoY(); // declarar los metodos getter
};

Punto::Punto() {

}

// establecer valores a los atributos
void Punto::setPunto(int _x, int _y) {
    x = _x;
    y = _y;
}

int Punto::getPuntoX() {
    return x;
}

int Punto::getPuntoY() {
    return y;
}

int main () {

    Punto punto1;

    // punt1.x = 15; al estar declarados de forma "private", los atributos no se pueden acceder de esta forma

    punto1.setPunto(15, 10); // usar el metodo setter

    // cout << punto1.x al estar declarados de forma "private", los atributos no se pueden acceder de esta forma

    cout << "el valor de X es: "<< punto1.getPuntoX() << endl; // usar el metodo getter
    cout << "el valor de Y es: "<< punto1.getPuntoY() << endl; // usar el metodo getter
    
    return 0;

}