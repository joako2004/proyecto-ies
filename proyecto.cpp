// cambios realizados:
    // modifico la documentación
    // se creo un metodo para eliminar vehiculos del vector
    // se agrego la clase camioneta
    // se agregaron espacios entre sentencias

#include <iostream>
#include <string>

using namespace std;

// Clase base Vehiculo
class Vehiculo {
protected:
    string marca;
    string modelo;
    int año;

public:
    // Constructor de Vehiculo
    Vehiculo(string, string, int);
    // Destructor virtual para asegurar destrucción adecuada en clases derivadas
    virtual ~Vehiculo(); 
    // Métodos virtuales puros para definir las funciones en las clases hijas
    virtual void arrancar() const = 0;
    virtual void detener() const = 0;
    virtual void mostrarDetalles() const = 0;
    virtual void mostrarDetallesResumido() const = 0;
};

// Clase Coche derivada de Vehiculo
class Coche : public Vehiculo {
private:
    int num_puertas;

public:
    // Constructor de Coche
    Coche(string, string, int, int);
    // Destructor de Coche
    ~Coche();
    // Métodos sobreescritos de la clase base
    void arrancar() const override;
    void detener() const override;
    void mostrarDetalles() const override;
    void mostrarDetallesResumido() const override;
};

// Clase Moto derivada de Vehiculo
class Moto : public Vehiculo {
private:
    string tipo_moto;

public:
    // Constructor de Moto
    Moto(string, string, int, string);
    // Destructor de Moto
    ~Moto();
    // Métodos sobreescritos de la clase base
    void arrancar() const override;
    void detener() const override;
    void mostrarDetalles() const override;
    void mostrarDetallesResumido() const override;
};

// Clase Camioneta derivada de Vehiculo
class Camioneta : public Vehiculo {
private:
    string traccion;

public:
    // Constructor de Camioneta
    Camioneta(string, string, int, string);
    // Destructor de Camioneta
    ~Camioneta();
    // Métodos sobreescritos de la clase base
    void arrancar() const override;
    void detener() const override;
    void mostrarDetalles() const override;
    void mostrarDetallesResumido() const override;
};

class Bote : public Vehiculo {
private:
    int cantidad_de_personas;

public:
    // Constructor de Bote
    Bote(string, string, int, int);
    // Destructor de Bote
    ~Bote();
    // Métodos sobreescritos de la clase base
    void arrancar() const override;
    void detener() const override;
    void mostrarDetalles() const override;
    void mostrarDetallesResumido() const override;
};

// Clase CocheElectrico derivada de Vehiculo
class CocheElectrico : public Vehiculo {
private:
    int tiempo_carga;

public:
    CocheElectrico(string, string, int, int);
    ~CocheElectrico();
    void arrancar() const override;
    void detener() const override;
    void mostrarDetalles() const override;
    void mostrarDetallesResumido() const override;
};


// Implementación del constructor de Vehiculo
Vehiculo::Vehiculo(string _marca, string _modelo, int _año) : marca(_marca), modelo(_modelo), año(_año) {}
// Implementación del destructor de Vehiculo
Vehiculo::~Vehiculo() {}

// Implementación del constructor de Coche
Coche::Coche(string _marca, string _modelo, int _año, int _num_puertas) : Vehiculo(_marca, _modelo, _año), num_puertas((_num_puertas > 0) ? _num_puertas : 4) {}
// Implementación del destructor de Coche
Coche::~Coche() {}

// Implementación del constructor de Moto
Moto::Moto(string _marca, string _modelo, int _año, string _tipo_moto) : Vehiculo(_marca, _modelo, _año), tipo_moto(_tipo_moto) {}
// Implementación del destructor de Moto
Moto::~Moto() {}

// Implementación del constructor de Camioneta
Camioneta::Camioneta(string _marca, string _modelo, int _año, string _traccion) : Vehiculo(_marca, _modelo, _año), traccion(_traccion) {}
// Implementación del destructor de Camioneta
Camioneta::~Camioneta() {}

// Implementación del constructor de Bote
Bote::Bote(string _marca, string _modelo, int _año, int _cantidad_de_personas) : Vehiculo(_marca, _modelo, _año), cantidad_de_personas(_cantidad_de_personas) {}
// Implementación del destructor de Bote
Bote::~Bote() {}

CocheElectrico::CocheElectrico(string _marca, string _modelo, int _año, int _tiempo_carga) 
    : Vehiculo(_marca, _modelo, _año), tiempo_carga(_tiempo_carga) {}

CocheElectrico::~CocheElectrico() {}

// Métodos de la clase Coche
void Coche::arrancar() const {
    cout << "Coche " << marca << " " << modelo << " arrancando.\n";
}

void Coche::detener() const {
    cout << "Coche " << marca << " " << modelo << " detenido.\n";
}

void Coche::mostrarDetalles() const {
    cout << "Coche:\nMarca: " << marca << "\nModelo: " << modelo << "\nAño: " << año << "\nNumero de puertas: " << num_puertas << "\n";
}

void Coche::mostrarDetallesResumido() const {
    cout << marca << " " << modelo << "\n";
}

// Métodos de la clase Moto
void Moto::arrancar() const {
    cout << "Moto " << marca << " " << modelo << " arrancando.\n";
}

void Moto::detener() const {
    cout << "Moto " << marca << " " << modelo << " detenida.\n";
}

void Moto::mostrarDetalles() const {
    cout << "Moto:\nMarca: " << marca << "\nModelo: " << modelo << "\nAño: " << año << "\nTipo: " << tipo_moto << "\n";
}

void Moto::mostrarDetallesResumido() const {
    cout << marca << " " << modelo << "\n";
}

// Métodos de la clase Camioneta
void Camioneta::arrancar() const {
    cout << "Camioneta " << marca << " " << modelo << " arrancando.\n";
}

void Camioneta::detener() const {
    cout << "Camioneta " << marca << " " << modelo << " detenida.\n";
}

void Camioneta::mostrarDetalles() const {
    cout << "Camioneta:\nMarca: " << marca << "\nModelo: " << modelo << "\nAño: " << año << "\nTracción: " << traccion << "\n";
}

void Camioneta::mostrarDetallesResumido() const {
    cout << marca << " " << modelo << "\n";
}

// Métodos de la clase Bote
void Bote::arrancar() const {
    cout << "Bote " << marca << " " << modelo << " arrancando.\n";
}

void Bote::detener() const {
    cout << "Bote " << marca << " " << modelo << " detenido.\n";
}

void Bote::mostrarDetalles() const {
    cout << "Bote:\nMarca: " << marca << "\nModelo: " << modelo << "\nAño: " << año << "\ncapacidad de tripulantes: " << cantidad_de_personas << "\n";
}

void Bote::mostrarDetallesResumido() const {
    cout << marca << " " << modelo << "\n";
}

// Métodos de la clase CocheElectrico
// Métodos de la clase CocheElectrico
void CocheElectrico::arrancar() const {
    cout << "CocheElectrico " << marca << " " << modelo << " arrancando silenciosamente.\n";
}

void CocheElectrico::detener() const {
    cout << "CocheElectrico " << marca << " " << modelo << " detenido.\n";
}

// Implementación correcta del método mostrarDetalles
void CocheElectrico::mostrarDetalles() const {
    cout << "CocheElectrico:\nMarca: " << marca << "\nModelo: " << modelo << "\nAño: " << año
         << "\nTiempo de carga estimado: " << tiempo_carga << " horas\n";
}

void CocheElectrico::mostrarDetallesResumido() const {
    cout << marca << " " << modelo << "\n";
}

// Función para crear un vehículo según el tipo especificado
Vehiculo* crearVehiculo(string tipo_vehiculo) {
    string marca, modelo, tipo_moto, traccion;
    int año, num_puertas, tiempo_carga, cantidad_personas;

    if (tipo_vehiculo == "Moto" || tipo_vehiculo == "moto") {
        cout << "Ingrese la marca de su moto: ";
        cin >> marca;
        cout << "Ingrese el modelo de su moto: ";
        cin >> modelo;
        cout << "Ingrese el tipo de su moto: ";
        cin >> tipo_moto;
        cout << "Ingrese el año de su moto: ";
        cin >> año;

        return new Moto(marca, modelo, año, tipo_moto);

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

    } else if (tipo_vehiculo == "Camioneta" || tipo_vehiculo == "camioneta") {
        cout << "Ingrese la marca de su camioneta: ";
        cin >> marca;
        cout << "Ingrese el modelo de su camioneta: ";
        cin >> modelo;
        cout << "Ingrese el tipo de tracción de su camioneta: ";
        cin >> traccion;
        cout << "Ingrese el año de su camioneta: ";
        cin >> año;

        return new Camioneta(marca, modelo, año, traccion);
        
    } else if (tipo_vehiculo == "Coche Electrico" || tipo_vehiculo == "coche electrico" || tipo_vehiculo == "cocheelectrico") {
        cout << "Ingrese la marca de su coche: ";
        cin >> marca;
        cout << "Ingrese el modelo de su coche: ";
        cin >> modelo;
        cout << "Ingrese el tiempo estimado de carga de su coche: ";
        cin >> traccion;
        cout << "Ingrese el año de su coche: ";
        cin >> año;

        return new CocheElectrico(marca, modelo, año, tiempo_carga);

    }

    cout << "Tipo de vehiculo no valido.\n";
    return nullptr;
}

// Función para gestionar los vehículos en el garage
void garage_vehiculos(Vehiculo** vector, int cantidad_vehiculos) {
    for (int i = 0; i < cantidad_vehiculos; i++) {
        string tipo_vehiculo;
        cout << "Que tipo de vehiculo desea alojar en su garage: (Coche, Moto, Camioneta, Coche electrico) ";
        cin >> tipo_vehiculo;

        Vehiculo* nuevo_vehiculo = crearVehiculo(tipo_vehiculo);
        if (nuevo_vehiculo) {
            vector[i] = nuevo_vehiculo;
        } else {
            cout << "Vehículo no creado. Intente de nuevo.\n";
            i--; // Reintentar si el tipo es incorrecto
        }
    }

    cout << "\nVamos a recorrer tu garage:\n";
    string opcion;

    for (int i = 0; i < cantidad_vehiculos; i++) {
        cout << i + 1 << ". ";
        vector[i]->mostrarDetallesResumido();
        cout << "¿Deseas ver los detalles del vehiculo? (si/no): ";
        cin >> opcion;

        if (opcion == "si") {
            vector[i]->mostrarDetalles();
            cout << "¿Quieres arrancar el vehiculo? (si/no): ";
            cin >> opcion;
            if (opcion == "si") {
                vector[i]->arrancar();
            }
        }
    }
}

// Función para limpiar el garage de vehículos y liberar memoria
void limpiar_vehiculos(Vehiculo** vector, int cantidad_vehiculos) {
    string opcion;
    int num_vehiculo;

    cout << "\n¿Desea eliminar alguno de los vehículos almacenados? (si/no): ";
    cin >> opcion;

    if (opcion == "si") {
        cout << "Ingrese el número del vehículo que desea eliminar (1-" << cantidad_vehiculos << "): ";
        cin >> num_vehiculo;
        num_vehiculo--;

        if (num_vehiculo >= 0 && num_vehiculo < cantidad_vehiculos && vector[num_vehiculo]) {
            delete vector[num_vehiculo];
            vector[num_vehiculo] = nullptr;
            cout << "Vehículo eliminado del garage.\n";
        } else {
            cout << "Número de vehículo inválido.\n";
        }
    }

    for (int i = 0; i < cantidad_vehiculos; i++) {
        if (vector[i]) {
            delete vector[i];
        }
    }
}

// Función principal
int main() {
    int cantidad_vehiculos;

    cout << "Cuántos vehículos desea almacenar en su garage?: ";
    cin >> cantidad_vehiculos;

    Vehiculo** vector_vehiculos = new Vehiculo*[cantidad_vehiculos];
    for (int i = 0; i < cantidad_vehiculos; i++) {
        vector_vehiculos[i] = nullptr;
    }

    garage_vehiculos(vector_vehiculos, cantidad_vehiculos);
    limpiar_vehiculos(vector_vehiculos, cantidad_vehiculos);

    delete[] vector_vehiculos;

    cout << "Gracias por usar nuestros servicios" << endl;

    return 0;
}
