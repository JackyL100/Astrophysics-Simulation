#include <iostream>
#include <webgpu/webgpu.h>
#include <webgpu/wgpu.h>
#include <GLFW/glfw3.h>
#include <glfw3webgpu.h>
#include <cassert>
#pragma once

class Application {
public:
    // Initialize everything and return true if it went all right
    bool Initialize();

    // Uninitialize everything that was initialized
    void Terminate();

    // Draw a frame and handle events
    void MainLoop();

    // Return true as long as the main loop should keep on running
    bool IsRunning();

private:
    // We put here all the variables that are shared between init and main loop
    WGPUDevice device;
    WGPUQueue queue;
    GLFWwindow* window;
    WGPUSurface surface;

    std::pair<WGPUSurfaceTexture, WGPUTextureView> GetNextSurfaceViewData();
    // WGPUTextureView GetNextSurfaceTextureView();
};