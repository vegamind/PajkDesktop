#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>

#include "../glad/glad.h"
#include <GLFW/glfw3.h>

class GLRasterizer{
public:
    GLRasterizer(std::vector<float>& data, uint32_t resX, uint32_t resY);
    ~GLRasterizer();

    GLRasterizer(const GLRasterizer& other) = delete;
    GLRasterizer& operator=(const GLRasterizer& other) = delete;
    GLRasterizer(const GLRasterizer&& other) = delete;
    GLRasterizer& operator=(const GLRasterizer&& other) = delete;

private:
    void CreateContext();
    void CreateBuffer();
    void CompileShader();
    void DrawShape();
    void ReadPixels();

    GLFWwindow* window;

    GLuint VAO, VBO;
    GLuint program;

    uint32_t resX;
    uint32_t resY;
    
    std::vector<float>& data;
};