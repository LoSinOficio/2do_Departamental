#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// 1. Responsabilidad: Lógica de la Lista Dinámica con STL 
class ListaDinamicaSTL {
private:
    list<int> elementos;

public:
    void agregarAlFinal(int valor) {
        elementos.push_back(valor);
        cout << "Elemento " << valor << " agregado al final.\n";
    }

    void agregarAlFrente(int valor) {
        elementos.push_front(valor);
        cout << "Elemento " << valor << " agregado al frente.\n";
    }

    void eliminar(int valor) {
        elementos.remove(valor);
        cout << "Se eliminaron las ocurrencias de " << valor << " (si existian).\n";
    }

    bool buscar(int valor) const {
        auto it = find(elementos.begin(), elementos.end(), valor);
        return it != elementos.end();
    }

    bool estaVacia() const {
        return elementos.empty();
    }

    // Método seguro para obtener una copia y recorrerla sin romper el encapsulamiento
    list<int> obtenerCopia() const {
        return elementos;
    }
};

// 2. Responsabilidad: Visualización e impresión de datos 
class VisualizadorLista {
public:
    static void mostrar(const ListaDinamicaSTL& listaObj) {
        list<int> temp = listaObj.obtenerCopia();
        if (temp.empty()) {
            cout << "La lista esta vacia.\n";
            return;
        }
        cout << "\n--- Lista STL ---\n";
        cout << "Elementos de la lista: ";
        for (int v : temp) {
            cout << v << " ";
        }
        cout << endl;
    }
};

class MenuListaSTL {
public:
    static void ejecutar() {
        ListaDinamicaSTL miLista;
        int opcion, valor;

        do {
            cout << "\n=== MENU LISTA DINAMICA CON STL (POO) ===\n";
            cout << "1. Agregar al final (push_back)\n";
            cout << "2. Agregar al frente (push_front)\n";
            cout << "3. Eliminar elemento\n";
            cout << "4. Buscar elemento\n";
            cout << "5. Mostrar lista\n";
            cout << "0. Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Ingrese el valor a agregar al final: ";
                    cin >> valor;
                    miLista.agregarAlFinal(valor);
                    break;
                case 2:
                    cout << "Ingrese el valor a agregar al frente: ";
                    cin >> valor;
                    miLista.agregarAlFrente(valor);
                    break;
                case 3:
                    if (miLista.estaVacia()) {
                        cout << "La lista esta vacia.\n";
                    } else {
                        cout << "Ingrese el valor a eliminar: ";
                        cin >> valor;
                        miLista.eliminar(valor);
                    }
                    break;
                case 4:
                    if (miLista.estaVacia()) {
                        cout << "La lista esta vacia.\n";
                    } else {
                        cout << "Ingrese el valor a buscar: ";
                        cin >> valor;
                        if (miLista.buscar(valor)) {
                            cout << "¡El elemento " << valor << " se encuentra en la lista!\n";
                        } else {
                            cout << "El elemento " << valor << " no esta en la lista.\n";
                        }
                    }
                    break;
                case 5:
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
    MenuListaSTL::ejecutar();
    return 0;
}