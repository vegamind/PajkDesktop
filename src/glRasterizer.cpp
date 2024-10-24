#include "glRasterizer.hpp"

const std::string vertexSRC = 
"#version 460 core\n"
"layout(location = 0) in vec2 aPos;\n"
"layout(location = 1) out float vertexID;\n"
"void main(){\n"
"gl_Position = vec4(vec2(aPos.x*2-1, aPos.y*2-1), 0.0, 1.0);\n"
"vertexID = gl_VertexID;"
"}\n";

const std::string fragSRC = 
"#version 460 core\n"
"layout(location = 0) out vec4 fragColor;\n"
"layout(location = 1) in float vertexID;\n"
"void main(){\n"
"fragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
"}\n";


GLRasterizer::GLRasterizer(std::vector<std::vector<float>>& data,
 uint32_t resX, uint32_t resY): resX(resX), resY(resY), data(data){
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
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

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
    VAO.resize(data.size());
    VBO.resize(data.size());

    for(uint32_t i = 0; i < data.size(); i++){
        if(data[i].empty()){
            continue;
        }

        glCreateVertexArrays(1, &VAO[i]);
        glBindVertexArray(VAO[i]);

        glCreateBuffers(1, &VBO[i]);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);

        glBufferData(GL_ARRAY_BUFFER, data[i].size() * sizeof(float), data[i].data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

        glEnableVertexAttribArray(0);

    }
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
}

void GLRasterizer::DrawShape(){

    glUseProgram(program);


    for(uint32_t i = 0; i < data.size(); i++){
        if(data[i].empty()){
            continue;
        }

        glBindVertexArray(VAO[i]);
        glDrawArrays(GL_LINE_LOOP, 0, data[i].size()/2);
    }

    glfwSwapBuffers(window);
    while(!glfwWindowShouldClose(window)){glfwPollEvents();}
}

void GLRasterizer::ReadPixels(){
    std::vector<uint8_t> buff;
    buff.resize(resX * resY);
    pixels.reserve(resX * resY);

    glReadPixels(0, 0, resX, resY, GL_RED, GL_UNSIGNED_BYTE, buff.data());

    for(uint32_t x = 0; x < resX; x++){
        for(uint32_t y = 0; y < resY; y++){
            uint8_t p = buff[x + y * resX];

            if(!p){
                continue;
            }

            pixels.push_back(x);           
            pixels.push_back(y);           
        }
    }

    pixels.shrink_to_fit();

}

std::vector<uint16_t>& GLRasterizer::GetPixelData(){
    return pixels;
}
