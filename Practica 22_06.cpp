#include <iostream>
#include <string>

using namespace std;

// 1. Responsabilidad: Lógica de la Pila Dinámica con Nodos y Punteros 
class PilaDinamica {
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
        Nodo(int valor, Nodo* sig = nullptr) : dato(valor), siguiente(sig) {}
    };
    
    Nodo* tope;

public:
    PilaDinamica() : tope(nullptr) {}
    
    ~PilaDinamica() {
        while (tope != nullptr) {
            Nodo* temp = tope;
            tope = tope->siguiente;
            delete temp;
        }
    }

    bool vacia() const { return tope == nullptr; }

    void push(int valor) {
        tope = new Nodo(valor, tope);
        cout << "Elemento agregado.\n";
    }

    void pop() {
        if (vacia()) {
            cout << "La pila esta vacia.\n";
            return;
        }
        Nodo* temp = tope;
        cout << "Elemento eliminado: " << temp->dato << '\n';
        tope = tope->siguiente;
        delete temp;
    }

    void mostrar() const {
        if (vacia()) {
            cout << "Pila vacia.\n";
            return;
        }
        cout << "Tope -> ";
        for (Nodo* actual = tope; actual != nullptr; actual = actual->siguiente) {
            cout << actual->dato << " ";
        }
        cout << '\n';
    }
};

class MenuPila {
public:
    static void ejecutar() {
        PilaDinamica pila;
        int opcion, valor;

        do {
            cout << "\n=== PILA DINAMICA ===\n";
            cout << "1. Push\n2. Pop\n3. Mostrar\n0. Salir\nOpcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Valor: ";
                    cin >> valor;
                    pila.push(valor);
                    break;
                case 2:
                    pila.pop();
                    break;
                case 3:
                    pila.mostrar();
                    break;
                case 0:
                    cout << "Saliendo...\n";
                    break;
                default:
                    cout << "Opcion no valida.\n";
            }
        } while (opcion != 0);
    }
};

int main() {
    MenuPila::ejecutar();
    return 0;
}