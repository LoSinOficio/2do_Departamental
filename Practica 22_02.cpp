#include <iostream>
#include <string>

using namespace std;

// 1. Responsabilidad: Lógica del Tipo de Dato Abstracto (ADT) Cuenta Bancaria 
class CuentaBancaria {
private:
    string titular;
    double saldo;

public:
    CuentaBancaria(string nombreTitular, double saldoInicial) {
        titular = nombreTitular;
        saldo = (saldoInicial >= 0) ? saldoInicial : 0;
    }

    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito exitoso de: $" << monto << endl;
        } else {
            cout << "Monto no valido.\n";
        }
    }

    string getTitular() const { return titular; }
    double getSaldo() const { return saldo; }
};

class VisualizadorCuenta {
public:
    static void mostrarEncabezado() {
        cout << "=== EJERCICIO 2: TIPO DE DATO ABSTRACTO (ADT) ===" << endl;
    }

    static void mostrar(const CuentaBancaria& cuenta) {
        cout << "Titular: " << cuenta.getTitular() << " | Saldo actual: $" << cuenta.getSaldo() << endl;
    }
};

int main() {
    VisualizadorCuenta::mostrarEncabezado();

    // Instanciamos el ADT
    CuentaBancaria cuenta1("Erick Cruz", 5000.0);

    // Interactuamos a través de la interfaz pública
    VisualizadorCuenta::mostrar(cuenta1);
    
    cuenta1.depositar(1500.0);
    
    VisualizadorCuenta::mostrar(cuenta1);

    return 0;
}