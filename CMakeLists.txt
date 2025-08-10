cmake_minimum_required(VERSION 3.0...3.25)
project(Simulation VERSION 0.1.0 LANGUAGES CXX C)

add_executable(simulation main.cpp)

set_target_properties(simulation PROPERTIES 
CXX_STANDARD 17
CXX_STANDARD_REQUIRED ON
CXX_EXTENSIONS OFF)

add_subdirectory(webgpu)


target_link_libraries(simulation PRIVATE webgpu)

target_copy_webgpu_binaries(simulation)