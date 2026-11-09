#include <iostream>
#include <string>

using namespace std;

// 1. Responsabilidad: Lógica del algoritmo Quick Sort 
class OrdenadorQuick {
private:
    static int particion(int arr[], int low, int high) {
        int pivote = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivote) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return (i + 1);
    }

public:
    static void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = particion(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};

// 2. Responsabilidad: Visualización e impresión de datos 
class Visualizador {
public:
    static void mostrarEnteros(const string& mensaje, const int arr[], int n) {
        cout << mensaje;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int datos[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    // Ordenar con la clase OrdenadorQuick
    OrdenadorQuick::quickSort(datos, 0, n - 1);

    // Mostrar resultados con la clase Visualizador
    cout << "--- Quick Sort ---" << endl;
    Visualizador::mostrarEnteros("Enteros ordenados: ", datos, n);

    return 0;
}