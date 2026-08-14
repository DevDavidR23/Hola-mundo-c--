#include <iostream>

int Binario(int numero){
    int resultado;
    while (numero > 0){
        resultado = numero % 2;
        std::cout << resultado;
        numero = numero / 2;
    }
    return resultado;
}

int main( int argc, const char *argv[])
{
    std::cout << "Algoritmo Binario" << std::endl;
    std::cout << "ingresa un numero" << std::endl;
    int numero;
    std::cin >> numero;
    Binario(numero);
    return 0;

}