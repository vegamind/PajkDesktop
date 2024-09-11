#include "bmpCreator.hpp"


const float TOPLEFT_BORDER[2] {-1, 10};
const float TOPRIGHT_BORDER[2] {5, 10};
const float BOTTOMLEFT_BORDER[2] {-1, 4};
const float BOTTOMRIGHT_BORDER[2] {5, 4};

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

    gcodeStream = std::make_shared<std::ofstream>(outputName + ".pjk");
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

    uint32_t factor = pow(10, FLOAT_PRECISION);

    for(std::vector<float>& buff : gcodeBuff){
        for(int i = 0; i < buff.size(); i += 2){
            buff[i] *= abs(TOPLEFT_BORDER[0]) + abs(TOPRIGHT_BORDER[0]);
            buff[i] +=  TOPLEFT_BORDER[0];

            buff[i+1] *= abs(TOPLEFT_BORDER[1]) + abs(BOTTOMLEFT_BORDER[1]);
            buff[i+1] += BOTTOMLEFT_BORDER[1];
        }

        gcodeStream->write(reinterpret_cast<char*>(buff.data()), buff.size() * sizeof(float));
    }
}

BMPGCODECreator::~BMPGCODECreator(){
    std::flush(*bmpStream);    


    inStream->close();
    gcodeStream->close();
    bmpStream->close();
}
