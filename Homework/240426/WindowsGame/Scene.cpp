#include "pch.h"
#include "Scene.h"
#include "Actor.h"

void Scene::Init()
{
	// 기본적인 처리
}
void Scene::Render(HDC hdc)
{
	// ranged-base for문
	for (Actor* actor : _actors)// 요소들을 순회하면서 받아줌
	{
		actor->Render(hdc);
	}
}
void Scene::Update()
{
	for (Actor* actor : _actors)
	{
		actor->Update();
	}
}
void Scene::Release()
{
	for (Actor* actor : _actors)
	{
		actor->Release();
		SAFE_DELETE(actor);
	}
	_actors.clear();
}
void Scene::SpawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	_actors.push_back(actor);
}
void Scene::DespawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	// 삭제할 객체찾기
	auto findIt = find(_actors.begin(), _actors.end(), actor); // 처음부터 끝까지 중 actor라는게 있는지를 찾는다.
	// 못찾았으면 findIt이 _actors.end()가 된다.
	if (findIt != _actors.end())
	{
		(*findIt)->Release();
		Actor* deleteActor = (*findIt);
		SAFE_DELETE(deleteActor);
		_actors.erase(findIt);
	}
}
