#pragma once
// actor�� �������� component�� ��� �־����
class Component;
class Collider;
class Actor
{
	// Actor�� �⺻���� �Ӽ��� ���� �ȵ� �ִ°� ����.
protected:
	CenterRect _body = {};
	string _name;
	vector<Component*> _components;

	bool _isEnable = true;

public:
	// ����(Getter), ����(Setter)
	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }

	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

	bool GetEnable() { return _isEnable; }
	void SetEnable(bool isEnable) { _isEnable = isEnable; }

public:
	// �浹 ���۵Ǿ�����.
	// Unity
	virtual void OnTriggerEnter(Collider* collider, Collider* other);
	// �浹 �������� 
	virtual void OnTriggerExit(Collider* collider, Collider* other);

	// Unreal
	// void OnComponentBeginOverlap(Collider* collider, Collider * other);
	// �浹 �������� 
	// void OnComponentEndOverlap(Collider* collider, Collider * other);

public:
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};
