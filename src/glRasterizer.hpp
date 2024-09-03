#pragma once

#include <vector>
#include <stdexcept>

#include <GLFW/glfw3.h>

#include "../glad/glad.h"

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

    GLFWwindow* window;
};