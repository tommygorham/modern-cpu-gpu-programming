#include "Kokkos_Core.hpp"
#include <iostream> 

int main(int argc, char **argv) {
    Kokkos::initialize(argc, argv); 
    { // start kokkos scope
            

            Kokkos::parallel_for("Init" R, [=](int j)
            {
                for int 

    }//close kokkos scope
    Kokkos::finalize(); 
    return 0; 
} 
