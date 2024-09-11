#include "gcodeInterpreter.hpp"
#include "bmpCreator.hpp"


int main(int argc, char** argv){
	if(argc < 2){
		throw std::runtime_error("No file path provided");
	}

	GCODEInterpreter interpreter(argv[1]);
	BMPGCODECreator bmpCreator("test", 160, 128);
}