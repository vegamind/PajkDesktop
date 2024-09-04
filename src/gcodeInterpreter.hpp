#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

#define POINT_DIST_TRESHOLD 0.2f

class GCODEInterpreter{
public:
    GCODEInterpreter(std::string in, std::string out);

    GCODEInterpreter(const GCODEInterpreter& other) = delete;
    GCODEInterpreter& operator=(const GCODEInterpreter& other) = delete;
    GCODEInterpreter(const GCODEInterpreter&& other) = delete;
    GCODEInterpreter& operator=(const GCODEInterpreter&& other) = delete;//can't be bothered lmao

    ~GCODEInterpreter();

private:

    void SetupStreams();
    void ReadFile();

    void InterpretLine(std::string line);
    void InterpretLineSubstr(std::string substr);

    std::shared_ptr<std::fstream> inStream;
    std::shared_ptr<std::ofstream> outStream;

    std::string inputPath;
    std::string outputPath;

    size_t lastGPos;

    uint32_t lastX;
    uint32_t lastY;

    float z;
};