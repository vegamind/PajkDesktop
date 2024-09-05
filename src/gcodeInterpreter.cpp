#include "gcodeInterpreter.hpp"

#include <fstream>
#include <exception>

GCODEInterpreter::GCODEInterpreter(std::string inputPath, std::string outputPath): inputPath(inputPath), outputPath(outputPath),
lastX(-1), lastY(-1), z(0){
    SetupStreams();
    ReadFile();
}

void GCODEInterpreter::SetupStreams(){
    inStream = std::make_shared<std::fstream>(inputPath);

    if(!inStream->is_open()){
        throw std::runtime_error("Failed to open " + inputPath);
    }

    std::string line;
    std::streampos prev = inStream->tellg();

    while(std::getline(*inStream, line)){
        if(line[0] == 'G'){
            inStream->seekg(prev);
            break;
        }
        prev = inStream->tellg();
    }

    outStream = std::make_shared<std::ofstream>(outputPath);

    if(!outStream->is_open()){
        throw std::runtime_error("Failed to create/truncate file " + outputPath);
    }
}

void GCODEInterpreter::ReadFile(){
    std::string line;
    while(std::getline(*inStream, line)){
        if(line[0] == 'G'){
            InterpretLine(line);
        }
    }
    std::flush(*outStream);//just in case idk
}

void GCODEInterpreter::InterpretLine(std::string line){
    std::vector<std::string> substrs;

    for(uint32_t i = 0; i < line.size();){
        std::size_t substrEnd = line.find(' ', i);

        if(substrEnd == std::string::npos){
            substrEnd = line.size()-1;
        }

        std::string substr = line.substr(i, substrEnd - i);

        if(substr[0] == 'Z'){
            InterpretLineSubstr(substr);
            return;
        }

        i = substrEnd + 1;

        substrs.push_back(substr);

    }


    bool suitableFormat = false;

    if(substrs.size() < 2){
        return;
    }

    if(!(substrs[0][0] == 'G' && substrs[1][0] == 'X' && substrs[2][0] == 'Y')){
        return;
    }

    for(uint32_t i = 0; i < substrs.size(); i++){
        InterpretLineSubstr(substrs[i]);
    }
}

void GCODEInterpreter::InterpretLineSubstr(std::string substr){
    if(substr[0] == 'Z'){
        std::string numStr = substr.substr(1, substr.size()-1);
        z = std::stof(numStr);
        return;
    }

    //if(z > -2){//todo bruh
    //    return;
    //}

    if(substr[0] == 'G'){
        std::string numStr = substr.substr(1, substr.size()-1);
        uint32_t numI = std::stoi(numStr);

        if(numI == 0 || numI == 1){
            char c = numI;
            lastGPos = outStream->tellp();
            outStream->write(&c, 1);
        }else{
            std::cerr << "Warning some goofy ass not skibidy sigma ohio grimace shake baby gronk negaive -20000 aura beta instruction: " << substr << "\n";
        }
    }
    else if(substr[0] == 'X' || substr[0] == 'Y'){
        std::string numStr = substr.substr(1, substr.size()-1);
        float numF = std::stof(numStr);


        //if(substr[0] == 'X'){
        //    if(fabsf(lastX-numF) > POINT_DIST_TRESHOLD && lastX != -1){
        //        std::cerr << lastX << "\n";
        //        outStream->seekp(lastGPos);
        //    }

        //    lastX = numF;
        //}else{
        //    if(fabsf(lastY-numF) > POINT_DIST_TRESHOLD && lastY != -1){
        //        std::cerr << lastY << "\n";
        //        outStream->seekp(lastGPos);
        //    }

        //    lastY = numF;
        //}


        outStream->write(reinterpret_cast<char*>(&numF), sizeof(numF));


    }
}

GCODEInterpreter::~GCODEInterpreter(){

    inStream->close();
    outStream->close();
}

