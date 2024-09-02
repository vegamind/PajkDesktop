#include "bmpCreator.hpp"


BMPCreator::BMPCreator(std::string in, std::string out): inputPath(in), outputPath(out){
    SetupStreams();
    ReadGCODEData();

    float maxX = 0;
    float maxY = 0;

    for(uint32_t i = 0; i < gcodeBuff.size(); i += 2){
        maxX = std::max(gcodeBuff[i], maxX);
        maxY = std::max(gcodeBuff[i + i + 1], maxX);
    }

    std::cerr << maxX << " " << maxY << "\n";
}

void BMPCreator::SetupStreams(){
    inStream = std::make_shared<std::fstream>(inputPath, inStream->in | inStream->ate);

    if(!inStream->is_open()){
        throw std::runtime_error("Failed to open file for reading " + inputPath);
    }

    outStream = std::make_shared<std::ofstream>(outputPath);
    if(!outStream->is_open()){
        throw std::runtime_error("Failed to create or truncate a file for writing " + inputPath);
    }
}

void BMPCreator::ReadGCODEData(){
    size_t size = inStream->tellg();
    inStream->seekg(0);

    gcodeBuff.resize((size - size/9) / sizeof(float));

    uint32_t i = 0;
    while(inStream->tellg() < size){
        std::array<uint8_t, 9> buff;

        inStream->read(reinterpret_cast<char*>(buff.data()), buff.size()); 

        std::memcpy(&gcodeBuff[i], buff.data()+1, 8);

        i += 2;
    }
}

BMPCreator::~BMPCreator(){
    std::flush(*outStream);    

    inStream->close();
    outStream->close();
}
