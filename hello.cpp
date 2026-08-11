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
  cout << first::x << endl;
  cout << second::x << endl;
  return 0;
}
