#include "gcodeInterpreter.hpp"


GCODEInterpreter::GCODEInterpreter(std::string inputPath): inputPath(inputPath), outputPath("tmp.bin"),
lastX(-1), lastY(-1), z(0){
    data.emplace_back();
    SetupStreams();
    ReadFile();
    WriteToFile();
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

    bool f300Found = false;


    for(uint32_t i = 0; i < line.size();){
        std::size_t substrEnd = line.find(' ', i);

        if(substrEnd == std::string::npos){
            substrEnd = line.size();
        }

        std::string substr = line.substr(i, substrEnd - i);

        if(!substr.compare("F300")){
            f300Found = true;
        }

        i = substrEnd + 1;

        substrs.push_back(substr);
    }


    bool suitableFormat = false;

    if(substrs.size() < 2){
        return;
    }


    if(!f300Found){
        data.emplace_back();
    }

    if(!(substrs[0][0] == 'G' && substrs[1][0] == 'X' && substrs[2][0] == 'Y')){
        return;
    }

    for(uint32_t i = 0; i < substrs.size(); i++){
        InterpretLineSubstr(substrs[i]);
    }
}

void GCODEInterpreter::InterpretLineSubstr(std::string substr){
    if(!substr.compare("F300")){
        data.emplace_back();
        return;
    }

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

        data.back().push_back(numF);
    }
}

void GCODEInterpreter::WriteToFile(){
    uint32_t max = 0;
    std::list<float>* max_chunk;

    for(auto& chunk : data){
        if(chunk.size() > max){
            max_chunk = &chunk;
            max = chunk.size();
        }
    }

    std::vector<float> chunk_vec;
    chunk_vec.reserve(max_chunk->size());

    for(float f : *max_chunk){
        chunk_vec.push_back(f);
    }

    outStream->write((char*)chunk_vec.data(), chunk_vec.size() * sizeof(float));
}

GCODEInterpreter::~GCODEInterpreter(){

    inStream->close();
    outStream->close();

    std::remove(outputPath.c_str());
}

