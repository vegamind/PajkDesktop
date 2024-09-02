#pragma once

#include <fstream>
#include <memory>
#include <iostream>
#include <exception>
#include <vector>
#include <array>
#include <cstring>

class BMPCreator{
public:
    BMPCreator(std::string in, std::string out);
    ~BMPCreator();

    BMPCreator(const BMPCreator& other) = delete;
    BMPCreator& operator=(const BMPCreator& other) = delete;
    BMPCreator(const BMPCreator&& other) = delete;
    BMPCreator& operator=(const BMPCreator&& other) = delete;
private:

    void SetupStreams();
    void ReadGCODEData();

    std::shared_ptr<std::fstream> inStream;
    std::shared_ptr<std::ofstream> outStream;

    std::string inputPath;
    std::string outputPath;

    std::vector<float> gcodeBuff;
};