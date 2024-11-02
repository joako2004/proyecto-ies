// sobrecarga de constructores

#include <iostream>

using namespace std;

class Fecha {
    
    private:
        int dia, mes, anio;
    
    public:
  
        Fecha(int, int, int); // constructor 1
        Fecha(long); // constructor 2
        void mostrar_fecha();

};

// constructor 1
Fecha::Fecha(int _dia, int _mes, int _anio) {
    dia = _dia;
    mes = _mes;
    anio = _anio;
}

// constructor 2
Fecha::Fecha(long fecha) {
    anio = int(fecha / 10000); // extraer el año
    mes = int((fecha - anio * 10000) / 100); // extraer el mes
    dia = int(fecha - anio * 10000 - mes * 100); // extraer el dia
    
}

void Fecha::mostrar_fecha() {
    cout << "la fecha es " << dia << "/" << mes << "/" << anio << endl;
};

int main () {

    Fecha hoy (5, 11, 2024);
    Fecha ayer(2024411);

    hoy.mostrar_fecha();
    ayer.mostrar_fecha();

    return 0;
}