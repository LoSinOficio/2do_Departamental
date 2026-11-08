#include <iostream>
#include <queue>

using namespace std;

// 1. Responsabilidad: Lógica de la Cola Dinámica con STL 
class ColaDinamicaSTL {
private:
    queue<int> cola;

public:
    void encolar(int valor) {
        cola.push(valor);
        cout << "Elemento " << valor << " agregado a la cola.\n";
    }

    bool estaVacia() const {
        return cola.empty();
    }

    int obtenerFrente() const {
        if (cola.empty()) return -1;
        return cola.front();
    }

    void desencolar() {
        if (!cola.empty()) {
            cola.pop();
        }
    }

    // Método seguro para obtener una copia y recorrerla sin romper el encapsulamiento
    queue<int> obtenerCopia() const {
        return cola;
    }
};

// 2. Responsabilidad: Menú e Interacción con el Usuario
class MenuCola {
public:
    static void ejecutar() {
        ColaDinamicaSTL miCola;
        int opcion, valor;

        do {
            cout << "\n=== MENU COLA DINAMICA CON STL (POO) ===\n";
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
                        cout << "Elemento eliminado del frente: " << miCola.obtenerFrente() << '\n'; 
                        miCola.desencolar(); 
                    }
                    break;
                case 3:
                    if (miCola.estaVacia()) {
                        cout << "La cola esta vacia.\n";
                    } else {
                        cout << "Elemento al frente de la cola: " << miCola.obtenerFrente() << '\n';
                    }
                    break;
                case 4: {
                    if (miCola.estaVacia()) { 
                        cout << "La cola esta vacia.\n"; 
                        break; 
                    }
                    queue<int> copia = miCola.obtenerCopia();
                    cout << "\n[FRENTE] -> ";
                    while (!copia.empty()) { 
                        cout << copia.front() << " -> "; 
                        copia.pop(); 
                    }
                    cout << "[FINAL]\n";
                    break;
                }
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
    MenuCola::ejecutar();
    return 0;
}