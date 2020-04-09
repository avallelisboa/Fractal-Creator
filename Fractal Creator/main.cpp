#include <iostream>
#include "BitMap.h"

#define WIDTH 800
#define HEIGHT 600

int main() {
	BitMap bitmap(800, 600);

	//bitmap.setPixel(WIDTH / 2, HEIGHT / 2, 255, 255, 255);

	for (int w = 0; w < WIDTH; w++) {
		for (int h = 0; h < HEIGHT; h++) {
			bitmap.setPixel(w, h, 255, 0, 0);
		}
	}

	bitmap.write("test5.bmp");

	std::cout << "finished" << std::endl;

	return 0;
}