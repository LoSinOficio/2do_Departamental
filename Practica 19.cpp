#include <iostream>
#include <string>

using namespace std;

// 1. Responsabilidad: Lógica del Ordenamiento Indirecto por Burbuja 
class OrdenamientoIndirecto {
public:
    static void ordenarPunterosEnteros(int* ptrs[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (*ptrs[j] > *ptrs[j + 1]) {
                    int* temp = ptrs[j];
                    ptrs[j] = ptrs[j + 1];
                    ptrs[j + 1] = temp;
                }
            }
        }
    }
};

class Visualizador {
public:
    static void mostrarOriginal(const string& mensaje, const int arr[], int n) {
        cout << mensaje;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    static void mostrarPunteros(const string& mensaje, int* ptrs[], int n) {
        cout << mensaje;
        for (int i = 0; i < n; i++) {
            cout << *ptrs[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int datos[] = {50, 10, 40, 20, 30};
    int n = 5;
    int* ptrs[5];

    for (int i = 0; i < n; i++) {
        ptrs[i] = &datos[i];
    }

    // Ordenar indirectamente con la clase OrdenamientoIndirecto
    OrdenamientoIndirecto::ordenarPunterosEnteros(ptrs, n);

    // Mostrar resultados usando la clase Visualizador
    cout << "--- Burbuja Indirecta ---" << endl;
    Visualizador::mostrarOriginal("Arreglo original sin modificar: ", datos, n);
    Visualizador::mostrarPunteros("Valores accedidos mediante punteros ordenados: ", ptrs, n);

    return 0;
}