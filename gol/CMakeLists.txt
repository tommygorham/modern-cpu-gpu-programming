cmake_minimum_required(VERSION 3.10)

project(gol)

find_package(Kokkos REQUIRED)
#find_package(CUDA REQUIRED)

set(CMAKE_CXX_FLAGS "-Wall ")

add_executable(gol gol.cpp )
target_link_libraries(gol Kokkos::kokkos)

#target_link_libraries(new.cu ${CUDA_LIBRARIES} Kokkos::kokkos)
