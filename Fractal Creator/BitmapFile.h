#pragma once

#include <cstdint>

#pragma pack(push, 2)

struct BitmapFile {
	char header[2]{'B','M'};
	int32_t fileSize;
	int32_t reserved{ 0 };
	int32_t dataOffset;
};

#pragma pack(pop)