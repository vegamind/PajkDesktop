#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <cstring>
#include <fstream>
#include <exception>
#include <list>

#define POINT_DIST_TRESHOLD 0.2f

class GCODEInterpreter{
public:
    GCODEInterpreter(std::string in);

    GCODEInterpreter(const GCODEInterpreter& other) = delete;
    GCODEInterpreter& operator=(const GCODEInterpreter& other) = delete;
    GCODEInterpreter(const GCODEInterpreter&& other) = delete;
    GCODEInterpreter& operator=(const GCODEInterpreter&& other) = delete;//can't be bothered lmao

    ~GCODEInterpreter();

private:

    void SetupStreams();
    void ReadFile();
    void WriteToFile();

    void InterpretLine(std::string line);
    void InterpretLineSubstr(std::string substr);

    std::shared_ptr<std::fstream> inStream;
    std::shared_ptr<std::ofstream> outStream;

    std::string inputPath;
    std::string outputPath;

    size_t lastGPos;

    std::list<std::list<float>> data;

    uint32_t lastX;
    uint32_t lastY;

    float z;
};