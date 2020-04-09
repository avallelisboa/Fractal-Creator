#include "BitMap.h"
#include "BitmapInfo.h"
#include "BitmapFile.h"



BitMap::BitMap(int width, int height):	m_width(width), m_height(height), m_pPixel(new uint8_t[width * height * 3]){
											//initializes, width, height and the pixels buffer, 8 bytes for each color(rgb) for each pixel
	memset(m_pPixel.get(), 0, sizeof(uint8_t) * width * height * 3);//initializes the buffer with the value 0

}

void BitMap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){

}

bool BitMap::write(std::string filename) {
	BitmapFile fileHeader;
	BitmapInfo infoHeader;

	fileHeader.fileSize = sizeof(BitmapFile) + sizeof(BitmapInfo) +  m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFile) + sizeof(BitmapInfo);

	infoHeader.width = m_width;
	infoHeader.height = m_width;

	return false;
}

BitMap::~BitMap(){
}
