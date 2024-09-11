#include "bmpCreator.hpp"


BMPGCODECreator::BMPGCODECreator(std::string out, uint32_t xRes, uint32_t yRes): inputPath("tmp.bin"), outputName(out), xRes(xRes), yRes(yRes){
    SetupStreams();
    ReadGCODEData();
    NormalizeCoordinates();

    rasterizer.reset(new GLRasterizer(gcodeBuff, DISPLAY_X, DISPLAY_Y));

    WriteBMP();
    WriteGCODE();
}

void BMPGCODECreator::SetupStreams(){
    inStream = std::make_shared<std::fstream>(inputPath, inStream->in | inStream->ate);

    if(!inStream->is_open()){
        throw std::runtime_error("Failed to open file for reading " + inputPath);
    }

    bmpStream = std::make_shared<std::ofstream>(outputName + ".bmp");
    if(!bmpStream->is_open()){
        throw std::runtime_error("Failed to create or truncate a file for writing " + inputPath);
    }

    gcodeStream = std::make_shared<std::ofstream>(outputName + ".pajk");
    if(!gcodeStream->is_open()){
        throw std::runtime_error("Failed to create or truncate a file for writing " + inputPath);
    }
}
 
void BMPGCODECreator::ReadGCODEData(){
    size_t size = inStream->tellg();
    inStream->seekg(0);


    size_t chunkSize = 0;
    while(inStream->tellg() < size){
        std::array<uint8_t, 9> buff;

        inStream->read(reinterpret_cast<char*>(buff.data()), buff.size()); 

        if(buff[0] == 0){
            gcodeBuff.emplace_back(chunkSize);

            chunkSize = 0;
            continue;
        }

        chunkSize += 2;
    }

    gcodeBuff.emplace_back(chunkSize);

    inStream->seekg(0);

    uint32_t i = 0;
    uint32_t y = 0;
    while(inStream->tellg() < size){
        std::array<uint8_t, 9> buff;

        inStream->read(reinterpret_cast<char*>(buff.data()), buff.size()); 

        if(buff[0] == 0){
            i++;
            y = 0;
            continue;
        }

        
        std::memcpy(&gcodeBuff[i][y], buff.data()+1, 8);

        y += 2;
    }
}

void BMPGCODECreator::NormalizeCoordinates(){
    float maxX = 0;
    float maxY = 0;

    for(uint32_t i = 0; i < gcodeBuff.size(); i++){
        for(uint32_t y = 0; y < gcodeBuff[i].size(); y += 2){
            maxX = std::max(gcodeBuff[i][y], maxX);
            maxY = std::max(gcodeBuff[i][y+1], maxX);
        }
    }

    for(uint32_t i = 0; i < gcodeBuff.size(); i++){
        for(uint32_t y = 0; y < gcodeBuff[i].size(); y += 2){
            gcodeBuff[i][y] /= maxX;
            gcodeBuff[i][y + 1] /= maxY;
        }
    }
}

void BMPGCODECreator::WriteBMP(){
    std::array<uint32_t, 2> displayRes = {DISPLAY_X, DISPLAY_Y}; 
    std::vector<uint16_t>& pixels = rasterizer->GetPixelData();

    bmpStream->write(reinterpret_cast<char*>(pixels.data()), pixels.size() * sizeof(uint16_t));
}

void BMPGCODECreator::WriteGCODE(){
    for(std::vector<float>& buff : gcodeBuff){
        gcodeStream->write(reinterpret_cast<char*>(buff.data()), buff.size() * sizeof(float));
    }
}

BMPGCODECreator::~BMPGCODECreator(){
    std::flush(*bmpStream);    


    inStream->close();
    gcodeStream->close();
    bmpStream->close();
}
