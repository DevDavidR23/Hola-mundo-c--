#include <iostream>
#include <bitset>
int main(int argc, const char *argv){
 std::cout<<"bienvenido al programa binarios"<<std::endl;
 std::cout<<"ingresa un numero"<<std::endl;
  int numero;
 std::cin >> numero;
 std::bitset<8> binario(numero);
 std::cout<<binario<<std::endl;
}