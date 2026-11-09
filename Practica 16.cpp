#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura de datos
struct Auto {
    string marca;
    int anio;
    double precio;

    bool operator<(const Auto& otro) const {
        if (marca != otro.marca) return marca < otro.marca;
        return anio < otro.anio;
    }
};

ostream& operator<<(ostream& salida, const Auto& a) {
    salida << "[Marca: " << a.marca << ", anio: " << a.anio << ", precio: " << a.precio << "]";
    return salida;
}

// 1. Responsabilidad: Ordenar datos (Principio SOLID: Single Responsibility)
class Ordenador {
public:
    template <typename T>
    static void burbuja(vector<T>& datos) {
        for (size_t i = 0; i < datos.size(); ++i) {
            bool huboCambio = false;
            for (size_t j = 0; j + 1 < datos.size() - i; ++j) {
                if (datos[j + 1] < datos[j]) {
                    T temporal = datos[j];
                    datos[j] = datos[j + 1];
                    datos[j + 1] = temporal;
                    huboCambio = true;
                }
            }
            if (!huboCambio) break;
        }
    }
};

// 2. Responsabilidad: Mostrar datos
class Visualizador {
public:
    template <typename T>
    static void mostrar(const string& mensaje, const vector<T>& datos) {
        cout << mensaje;
        for (const auto& elemento : datos) {
            cout << elemento << " ";
        }
        cout << '\n';
    }
};

int main() {
    vector<int> enteros = {8, 3, 9, 1, 5};
    vector<char> caracteres = {'z', 'a', 'm', 'b', 'c'};
    vector<Auto> autos = {
        {"Toyota", 2018, 180000},
        {"Nissan", 2020, 210000},
        {"Chevrolet", 2016, 150000},
        {"Audi", 2022, 450000}
    };

    // Ordenar usando la clase Ordenador
    Ordenador::burbuja(enteros);
    Ordenador::burbuja(caracteres);
    Ordenador::burbuja(autos);

    // Mostrar usando la clase Visualizador
    Visualizador::mostrar("Enteros ordenados: ", enteros);
    Visualizador::mostrar("Caracteres ordenados: ", caracteres);
    Visualizador::mostrar("Autos ordenados por marca y despues anio:\n", autos);

    return 0;
}