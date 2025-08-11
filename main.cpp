#include <iostream>
#include <webgpu/webgpu.h>
#include <webgpu/wgpu.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include "Application.hpp"



int main() 
{

    Application app;

    if (!app.Initialize()) {
        return 1;
    }

    while (app.IsRunning()) {
        app.MainLoop();
    }

    app.Terminate();

    return 0;

}