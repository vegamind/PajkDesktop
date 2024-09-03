#include "gcodeInterpreter.hpp"
#include "bmpCreator.hpp"

int main(int argc, char** argv){
	GCODEInterpreter interpreter("input.gcode", "out.bin");
	BMPCreator bmpCreator("out.bin", "test.bmp", 128, 128);
}