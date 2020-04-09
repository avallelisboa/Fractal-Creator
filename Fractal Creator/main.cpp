#include <iostream>
#include "BitMap.h"
int main() {
	BitMap bitmap(800, 600);
	bitmap.write("test.bmp");

	return 0;
}