#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <exception>
#include <vector>
#include <array>
#include <cstring>
#include <list>

#include "glRasterizer.hpp"

class BMPCreator{
public:
    BMPCreator(std::string in, std::string out, uint32_t xRes, uint32_t yRes);
    ~BMPCreator();

    BMPCreator(const BMPCreator& other) = delete;
    BMPCreator& operator=(const BMPCreator& other) = delete;
    BMPCreator(const BMPCreator&& other) = delete;
    BMPCreator& operator=(const BMPCreator&& other) = delete;
private:

    void SetupStreams();
    void ReadGCODEData();
    void NormalizeCoordinates();

    std::shared_ptr<std::fstream> inStream;
    std::shared_ptr<std::ofstream> outStream;

    std::string inputPath;
    std::string outputPath;

    std::vector<std::vector<float>> gcodeBuff;

    uint32_t xRes;
    uint32_t yRes;

    std::shared_ptr<GLRasterizer> rasterizer;
};