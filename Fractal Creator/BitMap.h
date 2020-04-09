#pragma once

#include<string>
#include<cstdint>

class BitMap{
private:
	int m_width;
	int m_height;
	std::unique_ptr<uint8_t[]> m_pPixels;
public:
	BitMap(int width, int height);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	bool write(std::string filename);
	virtual ~BitMap();
};

