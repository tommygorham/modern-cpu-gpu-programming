# modern-cpu-gpu-programming
Wiki page and code base to support my final project and paper with regards to a MS in Computer Science at the University of Tennessee at Chattanooga. 


#To build for CPU
-DCMAKE_INSTALL_PREFIX = <kokkos install-path>
-DCMAKE_CXX_COMPILER=<path-to-c++_compiler>

#To build for GPU
-DCMAKE_INSTALL_PREFIX = <kokkos install-path>
-DCMAKE_CXX_COMPILER=<path-to-kokkos-nvcc_wrapper>
-DKokkos_ENABLE_CUDA:BOOL=ON 
-DKokkos_ARCH_<MachineArch>=ON     
-DKokkos_ENABLE_CUDA_LAMBDA:BOOL=ON 
-DKokkos_ENABLE_CUDA_RELOCATABLE_DEVICE_CODE:BOOL=ON
  
