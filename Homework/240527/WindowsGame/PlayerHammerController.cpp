#include "pch.h"
#include "PlayerHammerController.h"
#include "HammerActor.h"
#include "MoleActor.h"
#include "BoxCollider.h"
#include "MoleGameScene.h"

void PlayerHammerController::Init(HammerActor* playerHammer, vector<MoleActor*> moles)
{
	// Linking (���� �μ��� ������ ������ �־��ִ°�)
	// SetLink
	_playerHammer = playerHammer;
	_moles = moles;
}
void PlayerHammerController::Update()
{
	this->ChangePlayerHammerPos(); // �̰� ���༭ ���콺�� �ظӰ� ����ٴҰŴ�

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		_playerHammer->ChangeState(HammerActorState::Hit);
		this->CatchMole();
	}

	if (Input->GetKeyUp(KeyCode::LeftMouse))
	{
		_playerHammer->ChangeState(HammerActorState::Idle);
	}
}
void PlayerHammerController::ChangePlayerHammerPos()
{
	POINT mousePos = Input->GetMousePos();
	_playerHammer->SetPos(mousePos);
}
void PlayerHammerController::CatchMole()
{
	POINT mousePos = Input->GetMousePos();
	for (MoleActor* mole : _moles)
	{
		BoxCollider* moleCollider = mole->GetComponent<BoxCollider>();
		// RectInRect�� ��쿡�� PtInRect�� 8�� ȣ���Ѵ� �׷��� PtInRect ����ص� ������ ������ �̰� ����ض�
		// �̷� ����� �κ��� �ٷ� ����ȭ�� ���ִ� ��! �ʹ� �Ű澲�� �ʴ´� �ص� �̷� �˾ƺ� �� �ִ� �κ��� ����ȭ�� ���ִ°� ����.
		if (Collision::PtInRect(mousePos, moleCollider->GetCollision().ToRect()))
		{
			if (mole->GetState() == MoleActorState::Out)
			{
				// ������ ���� ����

				// ���� ���� ������ ����
				MoleGameScene* currentScene = dynamic_cast<MoleGameScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());

				// �ڵ�� ������� �׷��� �ٸ����ӿ� ���Ǿ� ġ������ ������ �Ǵ°� �����ϵ��� ������ ���� if���� �߰��Ѵ�.
				// �δ��� ��⿡���� ����ϵ��� �� �ڵ带 �߰��Ѵ�. 
				// �̰� �߰� �����ָ� �ٸ������� �� ���͸� ����� ��쿡�� �Ʒ� �ڵ尡 ����� ���ɼ��� �����Ѵ�.
				// �׷��� �Ǹ� �ſ� ġ������ ������ �ȴ�.
				if (currentScene != nullptr)
				{
					// MoleGameScene�϶��� ����!
					currentScene->PlusScore();
				}

				mole->ChangeState(MoleActorState::Die);
			}
		}
	}
}