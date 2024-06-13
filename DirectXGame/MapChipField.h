#include <cstdint>
#include <vector>
#include<stdint.h>
#include"Vector3.h"
#include"model.h"
#include"WorldTransform.h"


//MapChipFieldの上に書く
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
	void ResetMapChipData();
	uint32_t GetNumBlockVirtical();
	uint32_t NumBlockHorizontal();

private:

	MapChipData mapChipData_;

	void LoadMapChipeCsv(const std::string& filePath);
	 MapChipType GetMapChipTypeByIndex(uint32_t xIndex,uint32_t yIndex);
	 Vector3 GetMapChipPositionByIndex(uint32_t xIndex,uint32_t yIndex);
	
};



