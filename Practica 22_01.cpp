#include <iostream>
#include <string>

using namespace std;

// Estructura auto-referenciada de dominio
struct Persona {
    string nombre;
    int edad;
    Persona* siguientePersona; 

    Persona(string n, int e) {
        nombre = n;
        edad = e;
        siguientePersona = nullptr;
    }
};

// 1. Responsabilidad: Administrar y vincular las relaciones entre objetos 
class GestorRelaciones {
public:
    static void vincular(Persona& p1, Persona& p2) {
        p1.siguientePersona = &p2;
    }
};

//  impresión de las relaciones 
class VisualizadorRelacion {
public:
    static void mostrar(const Persona& p1) {
        cout << "=== EJERCICIO 1: PUNTERO AL MISMO TIPO DE DATO ===" << endl;
        cout << "Persona Principal: " << p1.nombre << " (" << p1.edad << " anos)" << endl;
        
        if (p1.siguientePersona != nullptr) {
            cout << "Vinculada (via puntero): " << p1.siguientePersona->nombre 
                 << " (" << p1.siguientePersona->edad << " anos)" << endl;
        } else {
            cout << "Sin persona vinculada." << endl;
        }
    }
};

int main() {
    Persona p1("Erick", 21);
    Persona p2("Sofia", 20);

    // Vincular usando la clase GestorRelaciones
    GestorRelaciones::vincular(p1, p2);

    // Mostrar resultados usando la clase VisualizadorRelacion
    VisualizadorRelacion::mostrar(p1);

    return 0;
}