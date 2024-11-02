#include <iostream>

using namespace std;

// declarar la clase padre Vehiculo
class Vehiculo {
protected: // atributos de la clase
    string marca;
    string modelo;
    int año;

public: // metodos de la clase 
    Vehiculo(string, string, int); // constructor de la clase Vehiculo
    virtual ~Vehiculo(); // destructor de la clase Vehiculo
    virtual void arrancar() const = 0; // const = 0 indica que se trata de metodos abstractos, por lo que las clases hijas deben contar con una implementación del mismo 
    virtual void detener() const = 0;
    virtual void mostrarDetalles() const = 0;
    virtual void mostrarDetallesResumido() const = 0;
};

// Declarar la clase Coche que hereda de la clase Vehiculo
class Coche : public Vehiculo {
private:
    int num_puertas; // agregar atributos a la clase hija 

public:
    Coche(string, string, int, int); // constructor de la clase Coche
    ~Coche(); // destructor de la clase Coche
    void arrancar() const override; // const override indica que la clase hija sobreescribirá los metodos de la clase padre
    void detener() const override;
    void mostrarDetalles() const override;
    virtual void mostrarDetallesResumido() const override;
};

// Declarar la clase Moto que hereda de la clase Vehiculo
class Moto : public Vehiculo {
private:
    string tipo_moto; // añadir atributos a la clase hija

public:
    Moto(string, string, int, string); // constructor de la clase Moto
    ~Moto(); // destructor de la clase Moto
    void arrancar() const override; // const override indica que la clase hija sobreescribirá los metodos de la clase padre
    void detener() const override;
    void mostrarDetalles() const override;
    virtual void mostrarDetallesResumido() const override;
};

// Implementar constructores y destructores 
Vehiculo::Vehiculo(string _marca, string _modelo, int _año) {
    marca = _marca;
    modelo = _modelo;
    año = _año;
}

Vehiculo::~Vehiculo() {}

Coche::Coche(string _marca, string _modelo, int _año, int _num_puertas) : Vehiculo(_marca, _modelo, _año) { // constructor de la clase Coche
    num_puertas = (_num_puertas > 0) ? _num_puertas : 4;
}

Coche::~Coche() { // destructor de la clase Coche
}

Moto::Moto(string _marca, string _modelo, int _año, string _tipo_moto) : Vehiculo(_marca, _modelo, _año) { // constructor de la clase Moto
    tipo_moto = _tipo_moto;
}

Moto::~Moto() { // destructor de la clase Moto
}

// Implementar funciones para las clases hijas
void Coche::arrancar() const {
    cout << "Coche " << marca << " " << modelo << " arrancando." << endl;
}

void Coche::detener() const {
    cout << "Coche " << marca << " " << modelo << " detenido." << endl;
}

void Coche::mostrarDetalles() const {
    cout << "Coche - Marca: " << marca << "\n, Modelo: " << modelo << "\n, Año: " << año 
         << "\n, Numero de puertas: " << num_puertas << endl;
}

void Coche::mostrarDetallesResumido() const {
    cout << marca << " " << modelo;
}

void Moto::arrancar() const {
    cout << "Moto " << marca << " " << modelo << " arrancando." << endl;
}

void Moto::detener() const {
    cout << "Moto " << marca << " " << modelo << " detenida." << endl;
}

void Moto::mostrarDetalles() const {
    cout << "Moto - Marca: " << marca << "\n, Modelo: " << modelo << "\n, Año: " << año 
         << "\n, Tipo: " << tipo_moto << endl;
}

void Moto::mostrarDetallesResumido() const {
    cout << marca << " " << modelo;
}

// Función para crear un vehículo
Vehiculo* crearVehiculo(string tipo_vehiculo) {
    string marca, modelo, tipo_moto; // declarar los atributos que tomaran los objetos
    int año, num_puertas; // declarar los atributos que tomaran los objetos

    if (tipo_vehiculo == "Moto" || tipo_vehiculo == "moto") { // pedirle los atributos al usuario
        cout << "Ingrese la marca de su moto: ";
        cin >> marca;
        cout << "Ingrese el modelo de su moto: ";
        cin >> modelo;
        cout << "Ingrese el tipo de su moto: ";
        cin >> tipo_moto;
        cout << "Ingrese el año de su moto: ";
        cin >> año;

        return new Moto(marca, modelo, año, tipo_moto); // crear el objeto con los atributos ingresados por el usuario

    } else if (tipo_vehiculo == "Coche" || tipo_vehiculo == "coche") {
        cout << "Ingrese la marca de su coche: ";
        cin >> marca;
        cout << "Ingrese el modelo de su coche: ";
        cin >> modelo;
        cout << "Ingrese el numero de puertas de su coche: ";
        cin >> num_puertas;
        cout << "Ingrese el año de su coche: ";
        cin >> año;

        return new Coche(marca, modelo, año, num_puertas);
    }

    cout << "Tipo de vehiculo no valido." << endl;
    return nullptr; // Retorna nullptr si el tipo es inválido
}

void garage_vehiculos(int cantidad_vehiculos) {
    Vehiculo** vector = new Vehiculo*[cantidad_vehiculos];

    for (int i = 0; i < cantidad_vehiculos; i++) {
        string tipo_vehiculo;
        cout << "Que tipo de vehiculo desea alojar en su garage: (Coche, Moto) ";
        cin >> tipo_vehiculo;

        // verificar si el tipo de vehiculo es valido
        Vehiculo* nuevo_vehiculo = crearVehiculo(tipo_vehiculo);
        if (nuevo_vehiculo) {
            vector[i] = nuevo_vehiculo;
        } else {
            cout << "Vehículo no creado. Intente de nuevo." << endl;
            i--; // Reintentar si el tipo es incorrecto
        }
    }

    cout << "vamos a recorrer tu garage: " << endl;

    string opcion;

    // recorrer el garage
    for (int i = 0; i < cantidad_vehiculos; i++) {
    cout << i + 1 << ". ";
    vector[i]->mostrarDetallesResumido();
    cout << "\n";

    cout << "¿Deseas ver los detalles del vehiculo? (si/no): ";
    cin >> opcion;

    if (opcion == "si") {
        vector[i]->mostrarDetalles();
        opcion.clear(); // Limpia la variable opcion para reutilizarla

        cout << "¿Quieres arrancar el vehiculo? (si/no): ";
        cin >> opcion; // Recibe nuevamente el valor para la opción

        if (opcion == "si") {
            vector[i]->arrancar(); // Arranca el vehículo
        } 
    }
    }
    delete[] vector; // liberar el espacio de memoria del vector
}


int main() {
    int cantidadVehiculos; // declarar la cantidad de vehiculo ha almacenar

    cout << "Vamos a construir el garage de tus sueños." << endl;   
    cout << "Ingrese la cantidad de vehiculos que quiere para su garage: ";
    cin >> cantidadVehiculos; // leer la cantidad de vehiculos por consola

    garage_vehiculos(cantidadVehiculos); // hacer la llamada a la función

    return 0;
}

//! PARA EL FINAL CREAR CLASES COMO CAMIONETA, PUEDE TENER COMO ATRIBUTOS EL TIPO DE TRACCIÓN O COCHE ELECTRICO QUE PUEDE TENER COMO ATRIBUTO EL TIEMPO DE CARGA
//! probar agregar interface grafica
//! crear un metodo para eliminar vehiculos