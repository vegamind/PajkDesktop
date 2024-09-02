#include "gcodeInterpreter.hpp"
#include "bmpCreator.hpp"

int main(int argc, char** argv){
	GCODEInterpreter interpreter("input.gcode", "out.bin", 128, 128);
	BMPCreator bmpCreator("out.bin", "test.bmp");
}