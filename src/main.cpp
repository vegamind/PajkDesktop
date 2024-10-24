#include "gcodeInterpreter.hpp"
#include "bmpCreator.hpp"


int main(int argc, char** argv){
	if(argc < 2){
		exit(-1);
	}

	GCODEInterpreter interpreter(argv[1]);
	BMPGCODECreator bmpCreator(argv[1], 160, 128);
}