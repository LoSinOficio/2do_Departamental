#include <iostream>
#include <string>

using namespace std;

// 1. Responsabilidad: Lógica de la Pila Estática 
class PilaEstatica {
private:
    static const int MAX = 5;
    int datos[MAX];
    int tope;

public:
    PilaEstatica() : tope(-1) {}

    bool vacia() const { return tope == -1; }
    bool llena() const { return tope == MAX - 1; }

    void push(int valor) {
        if (llena()) {
            cout << "La pila esta llena.\n";
        } else {
            datos[++tope] = valor;
            cout << "Elemento agregado.\n";
        }
    }

    void pop() {
        if (vacia()) {
            cout << "La pila esta vacia.\n";
        } else {
            cout << "Elemento eliminado: " << datos[tope--] << '\n';
        }
    }

    void mostrar() const {
        if (vacia()) {
            cout << "Pila vacia.\n";
            return;
        }
        cout << "Tope -> ";
        for (int i = tope; i >= 0; --i) {
            cout << datos[i] << " ";
        }
        cout << '\n';
    }
};

class MenuPila {
public:
    static void ejecutar() {
        PilaEstatica pila;
        int opcion, valor;

        do {
            cout << "\n=== PILA ESTATICA ===\n";
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