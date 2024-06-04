#include <cstdint>
#include <vector>

class MapChipField{
	//1ブロックのサイズ
	static inline const float kBlockWidth=1.0f;
	static inline const float kBlockHeight=1.0f;
	//ブロックの個数
	static inline  const uint32_t kNumBlockVirtical = 20;
	static inline  const uint32_t kNumBlockHorizontal=100;
};

enum class MapChipType{
	kBlank,
	kBlock,

};

struct MapChipData {
	std::vector<std::vector<MapChipType>>data;

	MapChipData *mapChipData_;
};