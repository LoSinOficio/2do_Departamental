#include <iostream>
#include <string>

using namespace std;

// 1. Responsabilidad: Lógica del algoritmo Merge Sort Indirecto 
class MergeSortIndirecto {
private:
    static void mezclar(int* ptrs[], int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        int* L[20];
        int* R[20];
        for (int i = 0; i < n1; i++) L[i] = ptrs[l + i];
        for (int j = 0; j < n2; j++) R[j] = ptrs[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (*L[i] <= *R[j]) ptrs[k++] = L[i++];
            else ptrs[k++] = R[j++];
        }
        while (i < n1) ptrs[k++] = L[i++];
        while (j < n2) ptrs[k++] = R[j++];
    }

public:
    static void ordenar(int* ptrs[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            ordenar(ptrs, l, m);
            ordenar(ptrs, m + 1, r);
            mezclar(ptrs, l, m, r);
        }
    }
};

class Visualizador {
public:
    static void mostrarPunteros(const string& mensaje, int* ptrs[], int n) {
        cout << mensaje;
        for (int i = 0; i < n; i++) {
            cout << *ptrs[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int datos[] = {100, 25, 75, 12, 50};
    int n = 5;
    int* ptrs[5];

    for (int i = 0; i < n; i++) {
        ptrs[i] = &datos[i];
    }

    // Ordenar mediante la clase MergeSortIndirecto
    MergeSortIndirecto::ordenar(ptrs, 0, n - 1);

    // Mostrar resultados usando la clase Visualizador
    cout << "--- Merge Sort Indirecto ---" << endl;
    Visualizador::mostrarPunteros("Orden mediante punteros: ", ptrs, n);

    return 0;
}