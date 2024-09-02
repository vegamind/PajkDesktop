#pragma once

#include <iostream>
#include <memory>
#include <vector>

class GCODEInterpreter{
public:
    GCODEInterpreter(std::string in, std::string out, uint32_t resX, uint32_t resY);

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

    uint32_t resX;
    uint32_t resY;
};