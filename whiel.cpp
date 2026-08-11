#include <iostream>
int sumar(int a, int b)
{
    return a + b;
}
int restar(int a, int b)
{
    return a - b;
}
int multiplicar(int a, int b)
{
    return a * b;
}
int division(int a, int b)
{
    return a / b;
}
void mostrar()
{
    std::cout << "elige una opcion" << std::endl;
    std::cout << "1. Sumar" << std::endl;
    std::cout << "2. Restar" << std::endl;
    std::cout << "3. Multiplicar" << std::endl;
    std::cout << "4. dividir" << std::endl;\
    std::cout << "5. salir" << std::endl;
}
int main(int argc, const char *argv)
{
    std::cout << "While" << std::endl;
    // uso break con while easy calculator
    std::cout << "bienvenido" << std::endl;
    int numero1, numero2;
    int opcion;
    int resultado = 0;
    bool salir = false;
    while (!salir)
    {

        std::cout << "ingresa tus numeros" << std::endl;
        std::cin >> numero1 >> numero2;
        mostrar();
        std::cin >> opcion;
        switch (opcion)
        {
        case 1:
            resultado = sumar(numero1, numero2);
            break;
        case 2:
            resultado = restar(numero1, numero2);
            break;
        case 3:
            resultado = multiplicar(numero1, numero2);
            break;
        case 4:
        {
            if (numero1 < 1)
            {
                std::cout << "numero invalido vuelve a intentarlo" << std::endl;
            }
            else
            {
                resultado = division(numero1, numero2);
            }
            break;
        }
        case 5:
           salir = true;
           break;
        default:
           std::cout<<"numero invalido vuelve a intentarlo";
        }
        std::cout << "el resultado es: " << resultado << std::endl;
    }

    return 0;
}
