#pragma once
#include "ResourceBase.h"

struct Tile
{
	// 추후에 타일에 대한 정보가 추가되면, 여기에 값을 추가해주면 됨
	int value = 0;

	// 플레이어가 올 수 있는 지형인가 아닌가
};

class Tilemap : public ResourceBase
{
	DECLARE_CHILD(Tilemap, ResourceBase);

public:
	virtual void LoadFile(const wstring& path);
	virtual void SaveFile(const wstring& path);

public:
	Vector2Int GetMapSize() { return _mapSize; }
	int GetTileSize() { return _tileSize; }
	vector<vector<Tile>>& GetTiles() { return _tiles; }
	Tile* GetTileAt(Vector2Int pos);

	void SetMapSize(Vector2Int size) { _mapSize = size; }
	void SetTileSize(int size) { _tileSize = _tileSize; }

protected:
	Vector2Int _mapSize = {};
	int _tileSize = 0; // 항상 정사각형 모습이기때문에
	vector<vector<Tile>> _tiles;

};

