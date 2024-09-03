#include "glRasterizer.hpp"

GLRasterizer::GLRasterizer(std::vector<float>& data){
    CreateContext();
}

GLRasterizer::~GLRasterizer(){

}

void GLRasterizer::CreateContext(){
    if(!glfwInit()){
        throw std::runtime_error("Failed to init GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    if(glfwCreateWindow)
}