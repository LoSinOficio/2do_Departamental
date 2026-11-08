#include <iostream>
#include <stack>

using namespace std;

// 1. Responsabilidad: Lógica de la Pila Dinámica con STL 
class PilaDinamicaSTL {
private:
    stack<int> pila;

public:
    void apilar(int valor) {
        pila.push(valor);
        cout << "Elemento " << valor << " apilado en la cima.\n";
    }

    void desapilar() {
        if (!pila.empty()) {
            pila.pop();
        }
    }

    int obtenerCima() const {
        if (pila.empty()) return -1;
        return pila.top();
    }

    bool estaVacia() const {
        return pila.empty();
    }

    // Método seguro para obtener una copia y recorrerla sin romper el encapsulamiento
    stack<int> obtenerCopia() const {
        return pila;
    }
};

class VisualizadorPila {
public:
    static void mostrar(const PilaDinamicaSTL& pilaObj) {
        stack<int> temp = pilaObj.obtenerCopia();
        if (temp.empty()) {
            cout << "La pila esta vacia.\n";
            return;
        }
        cout << "\n[CIMA] -> ";
        while (!temp.empty()) {
            cout << temp.top() << " -> ";
            temp.pop();
        }
        cout << "[BASE]\n";
    }
};

class MenuPilaSTL {
public:
    static void ejecutar() {
        PilaDinamicaSTL miPila;
        int opcion, valor;

        do {
            cout << "\n=== MENU PILA DINAMICA CON STL (POO) ===\n";
            cout << "1. Apilar (push)\n";
            cout << "2. Desapilar (pop)\n";
            cout << "3. Consultar cima (top)\n";
            cout << "4. Mostrar pila\n";
            cout << "0. Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Ingrese el valor a apilar: ";
                    cin >> valor;
                    miPila.apilar(valor);
                    break;
                case 2:
                    if (miPila.estaVacia()) {
                        cout << "La pila esta vacia. No se puede desapilar.\n";
                    } else {
                        cout << "Elemento desapilado de la cima: " << miPila.obtenerCima() << "\n";
                        miPila.desapilar();
                    }
                    break;
                case 3:
                    if (miPila.estaVacia()) {
                        cout << "La pila esta vacia.\n";
                    } else {
                        cout << "Elemento en la cima: " << miPila.obtenerCima() << "\n";
                    }
                    break;
                case 4:
                    VisualizadorPila::mostrar(miPila);
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
    MenuPilaSTL::ejecutar();
    return 0;
}