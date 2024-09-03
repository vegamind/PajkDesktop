#include "glRasterizer.hpp"

const std::string vertexSRC = 
"#version 460 core\n"
"layout(location = 0) in vec2 aPos;\n"
"void main(){\n"
"gl_Position = vec4(vec2(aPos.x*2-1, aPos.y*2-1), 0.0, 1.0);\n"
"}\n";

const std::string fragSRC = 
"#version 460 core\n"
"layout(location = 0) out vec4 fragColor;\n"
"void main(){\n"
"fragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
"}\n";


GLRasterizer::GLRasterizer(std::vector<float>& data, uint32_t resX, uint32_t resY): resX(resX), resY(resY), data(data){
    CreateContext();
    CreateBuffer();
    CompileShader();
    DrawShape();
    ReadPixels();
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
//    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    window = glfwCreateWindow(resX, resY, "", nullptr, nullptr);

    if(window == nullptr){
        throw std::runtime_error("Failed to create as GLFW window");
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        throw std::runtime_error("Failed to init glad");
    }

    glViewport(0, 0, resX, resY);
}

void GLRasterizer::CreateBuffer(){
    glCreateVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glCreateBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glEnableVertexAttribArray(0);
}

void GLRasterizer::CompileShader(){
    const char* vertCSrc = vertexSRC.c_str();
    const char* fragCSrc = fragSRC.c_str();
    int success;

    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &vertCSrc, NULL);
    glCompileShader(vertShader);


    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragCSrc, NULL);
    glCompileShader(fragShader);


    program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);


    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
}

void GLRasterizer::DrawShape(){
    glBindVertexArray(VAO);
    glUseProgram(program);


    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, data.size());
        glfwSwapBuffers(window);
    }
    
}

void GLRasterizer::ReadPixels(){
    std::vector<uint8_t> pixels(resX * resY * 4);

    glReadPixels(0, 0, resX, resY, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
}
