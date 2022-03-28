#include "Kokkos_Core.hpp"
#include <iostream> 

#define DEFAULT_INPUT "./kokkosGOL.cpp" 

typedef Kokkos::View<double **, Kokkos::DefaultExecutionSpace> ViewMatrixType; /* since i defined it this way in serialGOL.cpp */ 

void testfunction(ViewMatrixType A);


int main(int argc, char** argv) 
{
    Kokkos::initialize(argc, argv); 
    { // start kokkos scope
	
		std::string filename = DEFAULT_INPUT; /* getting filename for output */ 
		filename = std::string(argv[0]); /* otherwise, filename is first arg*/ 
		const int dim = atoi(argv[1]);  /* square grid dimensions */  
		int generations = 1; /* number of gol iterations */ 
		
		/* checking execution space */ 
		std::cout << "Current execution space: " << 
        typeid(Kokkos::DefaultExecutionSpace).name() << std::endl; 
			
		// use default exe space as policy so can compile time change only 
	
		
		ViewMatrixType A("grid", dim, dim);
		/* for performant host or device access */ 
		ViewMatrixType::HostMirror h_A = Kokkos::create_mirror_view(A); /* this doesn't cost anything if we only compile for cpu, just a ref*/ 
		
		/* if we only compile for cpu, deepcopy is also free */ 
		
		int x = 1; 
		
	 for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
        A(i, j) = x;
      }
	  ++x; 
    }

   
testfunction(A); 
	


 
		
  
/*

		if no layout is specified, default layout for the memory/execution space is used 
            Kokkos::parallel_for("Init" R, [=](int j)
				OR
			Kokkos::parallel_for("Init2", 
				RangePolicy<DefaultExecutionSpace> 
            {
                for int 
*/ 
    }//close kokkos scope
    Kokkos::finalize(); 
    return 0; 
} 


void testfunction(ViewMatrixType A){
	
	 for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
        std::cout << A(i, j);
      }
    }

		std::cout << "made it" << std::endl; 
	}


