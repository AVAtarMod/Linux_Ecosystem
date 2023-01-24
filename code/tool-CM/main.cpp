#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
   const int& parameters = argc;
   if (parameters == 1) {
      std::cerr << "Requiered parameters not passed. Exiting.\n";
   }
   for (int i = 1; i < parameters; i++) {
      }
   return 0;
}

