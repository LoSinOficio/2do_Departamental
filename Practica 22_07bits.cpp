#include <iostream>
#include <string>

using namespace std;

// 1. Responsabilidad: Lógica de la Lista Dinámica con Nodos y Punteros 
class ListaDinamica {
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
        Nodo(int valor, Nodo* sig = nullptr) : dato(valor), siguiente(sig) {}
    };

    Nodo* cabeza;

public:
    ListaDinamica() : cabeza(nullptr) {}

    ~ListaDinamica() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    bool estaVacia() const { return cabeza == nullptr; }

    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            cabeza = nuevo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        cout << "Elemento " << valor << " insertado en la lista.\n";
    }

    bool eliminar(int valor) {
        if (estaVacia()) return false;

        if (cabeza->dato == valor) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return true;
        }

        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato != valor) {
            actual = actual->siguiente;
        }

        if (actual->siguiente != nullptr) {
            Nodo* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            return true;
        }

        return false;
    }

    bool buscar(int valor) const {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) return true;
            actual = actual->siguiente;
        }
        return false;
    }

    // Recorrido seguro mediante un callback para no exponer la estructura interna
    void recorrer(void (*accion)(int)) const {
        for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
            accion(actual->dato);
        }
    }
};

class VisualizadorLista {
public:
    static void mostrar(const ListaDinamica& lista) {
        if (lista.estaVacia()) {
            cout << "La lista esta vacia.\n";
            return;
        }
        cout << "\n[CABEZA] -> ";
        lista.recorrer([](int dato) {
            cout << dato << " -> ";
        });
        cout << "[NULL]\n";
    }
};

class MenuListaPunteros {
public:
    static void ejecutar() {
        ListaDinamica miLista;
        int opcion, valor;

        do {
            cout << "\n=== MENU LISTA DINAMICA CON PUNTEROS (POO) ===\n";
            cout << "1. Insertar elemento\n";
            cout << "2. Eliminar elemento\n";
            cout << "3. Buscar elemento\n";
            cout << "4. Mostrar lista\n";
            cout << "0. Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Ingrese el valor a insertar: ";
                    cin >> valor;
                    miLista.insertar(valor);
                    break;
                case 2:
                    if (miLista.estaVacia()) {
                        cout << "La lista esta vacia.\n";
                    } else {
                        cout << "Ingrese el valor a eliminar: ";
                        cin >> valor;
                        if (miLista.eliminar(valor)) {
                            cout << "Elemento " << valor << " eliminado correctamente.\n";
                        } else {
                            cout << "Elemento no encontrado en la lista.\n";
                        }
                    }
                    break;
                case 3:
                    if (miLista.estaVacia()) {
                        cout << "La lista esta vacia.\n";
                    } else {
                        cout << "Ingrese el valor a buscar: ";
                        cin >> valor;
                        if (miLista.buscar(valor)) {
                            cout << "¡Elemento " << valor << " encontrado en la lista!\n";
                        } else {
                            cout << "El elemento " << valor << " no esta en la lista.\n";
                        }
                    }
                    break;
                case 4:
                    VisualizadorLista::mostrar(miLista);
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
    MenuListaPunteros::ejecutar();
    return 0;
}