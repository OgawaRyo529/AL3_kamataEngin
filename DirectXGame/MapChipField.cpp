#include <map>
#include<sstream>
#include <cassert>
#include <string>
#include<fstream>
#include<cassert>
#include "MapChipField.h"

namespace {


}
	std::map<std::string,MapChipType>mapChipTable={
		{"0",MapChipType::kBlank},
		{"1",MapChipType::kBlock},
	};

void MapChipField::ResetMapChipData()
{
	//マップチップデータをリセット
	mapChipData_.data.clear();
	mapChipData_.data.resize(kNumBlockVirtical);
	for (std::vector<MapChipType>& mapChipDataLine : mapChipData_.data) {
		mapChipDataLine.resize(kNumBlockHorizontal);
	}
}

void MapChipField:: LoadMapChipeCsv(const std::string& filePath) {
	
	ResetMapChipData();
	
	std::ifstream file;
	file.open(filePath);
	assert(file.is_open());

	std::stringstream mapChipCsv;

	mapChipCsv<<file.rdbuf();

	file.close();

	for (uint32_t i = 0; i < kNumBlockVirtical; ++i) {
		std::string line;
		getline(mapChipCsv,line);

		std::istringstream line_stream(line);

		for (uint32_t j = 0; j < kNumBlockHorizontal; ++j) {
			std::string word;
			getline(line_stream,word,',');

			if (mapChipTable.contains(word)) {
				mapChipData_.data[i][j]=mapChipTable[word];
			}
		}

	}

}

auto GetMapChipTypeByIndex(uint32_t xIndex, uint32_t yIndex) {
	if (xIndex < 0 || MapChipField::kNumBlockHorizontal - 1 < xIndex) {
		return MapChipType::kBlank;
	}
	if (yIndex < 0 || MapChipField::kNumBlockVirtical - 1 < yIndex) {
		return MapChipType::kBlock;
	}
	//return MapChipField::mapChipData_.data[yIndex][xIndex];
}

 Vector3 GetMapChipPositionByIndex(uint32_t xIndex, uint32_t yIndex) {

	return Vector3(MapChipField::kBlockWidth*xIndex,MapChipField::kBlockHeight*(MapChipField::kNumBlockVirtical-1-yIndex),0);
 }
