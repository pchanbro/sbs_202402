#pragma once

class Player;
enum class TileType
{
	EMPTY,
	WALL
};

class Board
{
public:
	Board() {}
	~Board() {}

	void Init(int size, Player* player);
	void Render();

	Vector2Int GetEnterPos() { return _enterPos; }
	Vector2Int GetExitPos() { return _exitPos; }
	int GetSize() { return _size; }
	bool CanGo(Vector2Int pos);

private:
	vector<vector<TileType>> _tiles = {};
	int _size = 0;

	Vector2Int _enterPos = { 1,1 };
	Vector2Int _exitPos = {};
	Player* _player = nullptr;
};

