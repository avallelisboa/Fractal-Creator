#include <fstream>
#include "BitMap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

BitMap::BitMap(int width, int height):	m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]){
											//initializes, width, height and the pixels buffer, 8 bytes for each color(rgb) for each pixel
	memset(m_pPixels.get(), 0, sizeof(uint8_t) * width * height * 3);//initializes the buffer with the value 0
}

void BitMap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){
	uint8_t *pPixel = m_pPixels.get();

	pPixel += y * 3 * m_width + x * 3;
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;


}

bool BitMap::write(std::string filename) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) +  m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	std::ofstream file;
	file.open(filename, std::ios::binary);

	if (!file) return false;

	file.write((char*)&fileHeader, sizeof(fileHeader));
	file.write((char*)&infoHeader, sizeof(infoHeader));
	file.write((char*)m_pPixels.get(), m_width * m_height * 3);

	file.close();

	if (!file) return false;

	return true;
}

BitMap::~BitMap(){
}
