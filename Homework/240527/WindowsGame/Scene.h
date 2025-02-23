// 앞으로 만들 씬들은 이 씬 파일을 상속받아서 만들거다.

#pragma once
class Actor; // 전방선언
class UI;
class Scene
{
protected: // 씬에는 액터, 카메라, UI 세가지는 있어야 한다.
	// Layer의 개수만큼 벡터를 배열 형태로 만들어야 한다.
	vector<Actor*> _actors[static_cast<int>(LayerType::End)]; // 몇 개가 추가될지 모르니 vector로 해줘라
	Vector2Int _cameraPosition = {};
	vector<UI*> _uis;

//----------------------------
//  ## 기본함수
//----------------------------
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	// Actor 조작함수
	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);

public:
	// Camera 조작함수
	void SetCameraPos(Vector2Int pos) { _cameraPosition = pos; }
	Vector2Int GetCameraPos() { return _cameraPosition; }
};

