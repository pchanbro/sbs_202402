#pragma once
class Panel;
class UI
{
public:
	UI() {}
	virtual ~UI() {}
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
public:
	virtual void Show();
	virtual void Hide();

public:
	void SetRect(CenterRect rect);
	CenterRect GetRect();
	Vector2 GetPos() { return _pos; }
	bool isInMouse(); // UI라면 필수적으로 가지고 있어야 하는 함수
	Panel* GetParent() { return _parent; }
	void SetParent(Panel* parent) { _parent = parent; }
	bool IsInMouse();

protected:
	Vector2 _pos = {};
	Vector2Int _size = {};
	bool _isShow = true;
	Panel* _parent = nullptr;
};

