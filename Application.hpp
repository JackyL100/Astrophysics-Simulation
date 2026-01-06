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

    // Initialize pipeline
    void InitializePipeline();

private:
    // We put here all the variables that are shared between init and main loop
    WGPUDevice device;
    WGPUQueue queue;
    GLFWwindow* window;
    WGPUSurface surface;
    WGPUTextureFormat surfaceFormat = WGPUTextureFormat_Undefined;
    WGPURenderPipeline pipeline;
    std::pair<WGPUSurfaceTexture, WGPUTextureView> GetNextSurfaceViewData();

    const char* shaderSource = R"(
    @vertex
    fn vs_main(@builtin(vertex_index) in_vertex_index: u32) -> @builtin(position) vec4f {
        var p = vec2f(0.0, 0.0);
        if (in_vertex_index == 0u) {
            p = vec2f(-0.5, -0.5);
        } else if (in_vertex_index == 1u) {
            p = vec2f(0.5, -0.5);
        } else {
            p = vec2f(0.0, 0.5);
        }
        return vec4f(p, 0.0, 1.0);
    }

    @fragment
    fn fs_main() -> @location(0) vec4f {
        return vec4f(0.0, 0.4, 1.0, 1.0);
    }
    )";
    // WGPUTextureView GetNextSurfaceTextureView();
};