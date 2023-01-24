#include <string>
#include <iostream>

#include "install.h"

int main(int argc, char const *argv[])
{
   const int& parameters = argc;
   if (parameters == 1) {
      std::cerr << "Requiered parameters not passed. Exiting.\n";
   }
   for (int i = 1; i < parameters; i++) {
      if (argv[i] == std::string("install")){
         bool result = install_all();
         if (result)
            exit(EXIT_SUCCESS);
         else 
            exit(EXIT_FAILURE);
      }
      if (argv[i] == std::string("start")){
         
      }
   }
   return 0;
}
