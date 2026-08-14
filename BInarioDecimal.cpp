#include <iostream>
#include <string>
#include <bitset>
int main(int argc, const char *argv){
    int numero;
    std::cout<<"ingresa un numero"<<std::endl;
    std::cin>>numero;
    std::string numeroCadena = std::to_string(numero);
    std::bitset<8> bits(numeroCadena);
    std::cout<<"decimal es:"<<bits.to_ulong()<<std::endl;
    return 0;
}