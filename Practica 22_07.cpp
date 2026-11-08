#include <iostream>
#include <string>

using namespace std;

// 1. Responsabilidad: Lógica de la Cola Dinámica con Nodos y Punteros 
class ColaDinamica {
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
        Nodo(int valor, Nodo* sig = nullptr) : dato(valor), siguiente(sig) {}
    };

    Nodo* frente;
    Nodo* final;

public:
    ColaDinamica() : frente(nullptr), final(nullptr) {}

    ~ColaDinamica() {
        while (frente != nullptr) {
            Nodo* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }

    bool estaVacia() const { return frente == nullptr; }

    void encolar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            frente = nuevo;
        } else {
            final->siguiente = nuevo;
        }
        final = nuevo;
        cout << "Elemento " << valor << " agregado a la cola.\n";
    }

    void desencolar() {
        if (estaVacia()) return;
        Nodo* temp = frente;
        frente = frente->siguiente;
        if (frente == nullptr) {
            final = nullptr;
        }
        delete temp;
    }

    int obtenerFrente() const {
        if (estaVacia()) return -1;
        return frente->dato;
    }

    // Método para exponer el frente de manera segura sin romper encapsulamiento
    void recorrer(void (*accion)(int)) const {
        for (Nodo* actual = frente; actual != nullptr; actual = actual->siguiente) {
            accion(actual->dato);
        }
    }
};

class VisualizadorCola {
public:
    static void mostrar(const ColaDinamica& cola) {
        if (cola.estaVacia()) {
            cout << "La cola esta vacia.\n";
            return;
        }
        cout << "\n[FRENTE] -> ";
        cola.recorrer([](int dato) {
            cout << dato << " -> ";
        });
        cout << "[FINAL]\n";
    }
};

class MenuColaPunteros {
public:
    static void ejecutar() {
        ColaDinamica miCola;
        int opcion, valor;

        do {
            cout << "\n=== MENU COLA DINAMICA CON PUNTEROS (POO) ===\n";
            cout << "1. Encolar (push)\n";
            cout << "2. Desencolar (pop)\n";
            cout << "3. Consultar frente\n";
            cout << "4. Mostrar cola\n";
            cout << "0. Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Ingrese el valor a encolar: ";
                    cin >> valor;
                    miCola.encolar(valor);
                    break;
                case 2:
                    if (miCola.estaVacia()) {
                        cout << "La cola esta vacia. No se puede desencolar.\n";
                    } else {
                        cout << "Elemento eliminado del frente: " << miCola.obtenerFrente() << "\n";
                        miCola.desencolar();
                    }
                    break;
                case 3:
                    if (miCola.estaVacia()) {
                        cout << "La cola esta vacia.\n";
                    } else {
                        cout << "Elemento al frente: " << miCola.obtenerFrente() << "\n";
                    }
                    break;
                case 4:
                    VisualizadorCola::mostrar(miCola);
                    break;
                case 0:
                    cout << "Saliendo del programa...\n";
                    break;
                default:
                    cout << "Opcion no valida. Intente de nuevo.\n";
            }
        } while (opcion != 0);
    }
};

int main() {
    MenuColaPunteros::ejecutar();
    return 0;
}