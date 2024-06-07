﻿#include <cstdint>
#include <vector>
#include<stdint.h>
#include"Vector3.h"

enum class MapChipType{
	kBlank,
	kBlock,

};
struct  MapChipData {
	std::vector<std::vector<MapChipType>>data;
};

class MapChipField{
public:
	//1ブロックのサイズ
	static inline const float kBlockWidth=1.0f;
	static inline const float kBlockHeight=1.0f;

	//ブロックの個数
	static inline  const uint32_t kNumBlockVirtical = 20;
	static inline  const uint32_t kNumBlockHorizontal=100;

private:
	MapChipData mapChipData_;
void ResetMapChipData();

void LoadMapChipeCsv(const std::string& filePath);

};



