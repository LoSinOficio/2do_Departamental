#include <iostream>
#include <string>

using namespace std;

// Estructura de datos
struct Producto {
    string nombre;
    float precio;
};

// 1. Responsabilidad: Lógica del algoritmo Merge Sort 
class OrdenadorMerge {
private:
    static void mezclarEnteros(int arr[], int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        int L[50], R[50];
        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

public:
    static void mergeSortEnteros(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSortEnteros(arr, l, m);
            mergeSortEnteros(arr, m + 1, r);
            mezclarEnteros(arr, l, m, r);
        }
    }
};

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
    int numeros[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    // Ordenar con la clase OrdenadorMerge
    OrdenadorMerge::mergeSortEnteros(numeros, 0, n - 1);

    // Mostrar resultados con la clase Visualizador
    cout << "--- Merge Sort ---" << endl;
    Visualizador::mostrarEnteros("Enteros ordenados: ", numeros, n);

    return 0;
}