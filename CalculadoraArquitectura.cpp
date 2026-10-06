#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;


double leerNumero(const string& mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            return valor;
        }
        cout << "  Entrada invalida. Intenta de nuevo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void mostrarMenu() {
    cout << "\n===== CALCULADORA =====\n";
    cout << "1. Suma (+)\n";
    cout << "2. Resta (-)\n";
    cout << "3. Multiplicacion (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Potencia (^)\n";
    cout << "6. Raiz cuadrada\n";
    cout << "7. Modulo (%)\n";
    cout << "0. Salir\n";
    cout << "=======================\n";
}

int main() {
    int opcion;
    cout << fixed << setprecision(4);

    do {
        mostrarMenu();
        cout << "Elige una opcion: ";

        if (!(cin >> opcion)) {
            cout << "  Opcion invalida.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (opcion == 0) {
            cout << "Hasta luego!\n";
            break;
        }

        if (opcion < 0 || opcion > 7) {
            cout << "  Opcion fuera de rango.\n";
            continue;
        }

      
        if (opcion == 6) {
            double n = leerNumero("Ingresa el numero: ");
            if (n < 0) {
                cout << "  Error: no existe raiz real de un numero negativo.\n";
            } else {
                cout << "Resultado: sqrt(" << n << ") = " << sqrt(n) << "\n";
            }
            continue;
        }

        double a = leerNumero("Ingresa el primer numero: ");
        double b = leerNumero("Ingresa el segundo numero: ");

        switch (opcion) {
            case 1:
                cout << "Resultado: " << a << " + " << b << " = " << a + b << "\n";
                break;
            case 2:
                cout << "Resultado: " << a << " - " << b << " = " << a - b << "\n";
                break;
            case 3:
                cout << "Resultado: " << a << " * " << b << " = " << a * b << "\n";
                break;
            case 4:
                if (b == 0) {
                    cout << "  Error: no se puede dividir entre cero.\n";
                } else {
                    cout << "Resultado: " << a << " / " << b << " = " << a / b << "\n";
                }
                break;
            case 5:
                cout << "Resultado: " << a << " ^ " << b << " = " << pow(a, b) << "\n";
                break;
            case 7:
                if (b == 0) {
                    cout << "  Error: modulo entre cero no definido.\n";
                } else {
                    cout << "Resultado: " << a << " % " << b << " = " << fmod(a, b) << "\n";
                }
                break;
        }
    } while (true);

    return 0;
}