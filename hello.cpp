#include <iostream>
#include <vector>
using namespace std; // hacer esto puede tener complicaciones a futuro, es mejor usar el namespace std::cout, std::cin, etc. para evitar confusiones con otros namespaces
  namespace first{
     int x = 10;
  }
  namespace second{
    int x = 20;
  }
  // typedef std::vector<std::pair<std::string, int>> pairlist;
  typedef std::string cadena;
  typedef int number;
int main(int argc, char const *argv[])
{
    // en las lecciones de tipos de datos
    char letra = 'D';
    bool positivo = true;
    int edad = 17;
    double estatura = 1.75;
    string nombre = "david";// dato curioso al usar using namespace std; no tengo que definir std::string nombre2, 
                             // esto es debido que string pertenece a std, tambien esto << es para concatenar
    cout << nombre << " edad: " << edad << " estatura: " << estatura << " letra incial de nombre "<<letra << " estudiante activo "<<positivo;
     //uso de constantes
     const double PI = 3.1415;
      double radio = 10;
      double circunferencia = 2*PI*radio;
     cout << "circunferencia es: " << circunferencia;  // podemos denotar constantes con const al frente el tipo de dato
     //namespaces  es agrupar codigo, y evitar conflictos de nombres, por ejemplo si tenemos dos variables con el mismo nombre pero en diferentes namespaces, no habrá conflicto
      using namespace first; // esto es para usar el namespace first sin tener que escribir first::x cada vez
     cout << "valor de x en first: " << x << endl; // esto es para imprimir el valor de x en el namespace first
    

     //typedef es para crear un alias de un tipo de dato, por ejemplo si queremos usar un tipo de dato largo como unsigned long long, podemos crear un alias para hacerlo mas facil de usar
        // pairlist lista;
       cadena hola = "hola";
       number uno = 1;
       cout << hola << uno;
    
    // para conversiones es simplemente (double) o el dato que queremos

    // numero par e impar
    

    
    int numero;
    cout << "ingresa un numero";
    cin >> numero;
    if (numero % 2 == 0)
    {
        cout << "el numero es par \n";
    }else{
        cout << "el numero es impar";
    }
    cout << "programa finalizado";
    return 0;
}
