#include "iostream"
#include <string>

int main(int argc, const char *argv){
    int numero;
    std::string nombre;
    std::cout << "ingresa un numero"<<std::endl;
    std::cin>>numero;
    std::cout<<"tu numero es "<<numero<<std::endl;
    if (numero > 18)
    {
        std::cout<< "eres mayor de edad";
        std::cout<< "Ingresa tu nombre";
        std::cin>>nombre;
        std::cout<<" tu nombre es "<< nombre<<std::endl;
    }else{
        std::cout<<"no puedes entrar eres menor de edad";
    }
    
}