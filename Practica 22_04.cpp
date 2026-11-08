#include <iostream>
#include <string>

using namespace std;

// 1. Responsabilidad: Lógica de la Cola Estática 
class ColaEstatica {
private:
    static const int MAX = 5;
    int datos[MAX];
    int frente, cantidad;

public:
    ColaEstatica() : frente(0), cantidad(0) {}

    bool vacia() const { return cantidad == 0; }
    bool llena() const { return cantidad == MAX; }

    void encolar(int valor) {
        if (llena()) { 
            cout << "La cola esta llena.\n"; 
            return; 
        }
        int final = (frente + cantidad) % MAX;
        datos[final] = valor;
        ++cantidad;
        cout << "Elemento agregado.\n";
    }

    void desencolar() {
        if (vacia()) { 
            cout << "La cola esta vacia.\n"; 
            return; 
        }
        cout << "Elemento eliminado: " << datos[frente] << '\n';
        frente = (frente + 1) % MAX;
        --cantidad;
    }

    void mostrar() const {
        if (vacia()) { 
            cout << "Cola vacia.\n"; 
            return; 
        }
        cout << "Frente -> ";
        for (int i = 0; i < cantidad; ++i) {
            cout << datos[(frente + i) % MAX] << " ";
        }
        cout << "<- Final\n";
    }
};

class MenuCola {
public:
    static void ejecutar() {
        ColaEstatica cola;
        int opcion, valor;

        do {
            cout << "\n=== COLA ESTATICA ===\n";
            cout << "1. Encolar\n2. Desencolar\n3. Mostrar\n0. Salir\nOpcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1: 
                    cout << "Valor: "; 
                    cin >> valor; 
                    cola.encolar(valor); 
                    break;
                case 2: 
                    cola.desencolar(); 
                    break;
                case 3: 
                    cola.mostrar(); 
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
    MenuCola::ejecutar();
    return 0;
}