cmake_minimum_required(VERSION 3.0...3.25)
project(Simulation VERSION 0.1.0 LANGUAGES CXX C)

add_executable(simulation main.cpp Application.cpp)

set_target_properties(simulation PROPERTIES 
CXX_STANDARD 17
CXX_STANDARD_REQUIRED ON
CXX_EXTENSIONS OFF)

add_subdirectory(webgpu)
add_subdirectory(glfw3webgpu)

if (NOT EMSCRIPTEN)
    # Add the 'glfw' directory, which contains the definition of a 'glfw' target
    add_subdirectory(glfw)
else()
    # Create a mock 'glfw' target that just sets the `-sUSE_GLFW=3` link option:
    add_library(glfw INTERFACE)
    target_link_options(glfw INTERFACE -sUSE_GLFW=3)
endif()
# In both cases, we can now link to the 'glfw' target


target_link_libraries(simulation PRIVATE webgpu glfw glfw3webgpu)

target_copy_webgpu_binaries(simulation)