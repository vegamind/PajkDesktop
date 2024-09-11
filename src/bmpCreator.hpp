#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <exception>
#include <vector>
#include <array>
#include <cstring>
#include <list>
#include <cmath>

#include "glRasterizer.hpp"

#define DISPLAY_X (uint32_t)160
#define DISPLAY_Y (uint32_t)128

#define FLOAT_PRECISION 6 // adjust if needed

class BMPGCODECreator{
public:
    BMPGCODECreator(std::string out, uint32_t xRes, uint32_t yRes);
    ~BMPGCODECreator();

    BMPGCODECreator(const BMPGCODECreator& other) = delete;
    BMPGCODECreator& operator=(const BMPGCODECreator& other) = delete;
    BMPGCODECreator(const BMPGCODECreator&& other) = delete;
    BMPGCODECreator& operator=(const BMPGCODECreator&& other) = delete;
private:

    void SetupStreams();
    void ReadGCODEData();
    void NormalizeCoordinates();
    void WriteBMP();
    void WriteGCODE();

    std::shared_ptr<std::fstream> inStream;
    std::shared_ptr<std::ofstream> bmpStream;
    std::shared_ptr<std::ofstream> gcodeStream;

    std::string inputPath;
    std::string outputName;

    std::vector<std::vector<float>> gcodeBuff;

    uint32_t xRes;
    uint32_t yRes;

    std::shared_ptr<GLRasterizer> rasterizer;
};