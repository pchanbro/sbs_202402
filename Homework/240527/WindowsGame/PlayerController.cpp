#include "pch.h"
#include "PlayerController.h"
#include "PaddleActor.h"
#include "BallActor.h"
#include "InGameScene.h"

void PlayerController::Init(PaddleActor* paddle, BallActor* ball)
{
	_paddle = paddle;
	_ball = ball;
}

void PlayerController::Update()
{

	if (!_canBallControl)
	{
		if (::Input->GetKey(KeyCode::Left))
		{
			_paddle->Move(Vector2::Left());
		}
		if (::Input->GetKey(KeyCode::Right))
		{
			_paddle->Move(Vector2::Right());
		}
	}


	if (_canBallControl)
	{
		if (::Input->GetKey(KeyCode::RightMouse))
		{
			Vector2 ballDir = Vector2(Input->GetMousePos().x - _ball->GetBody().pos.x, Input->GetMousePos().y - _ball->GetBody().pos.y);
			ballDir = ballDir.Normalize();

			_ball->SetMoveDir(ballDir);

			//게임상태가 변경되어야합니다.
			InGameScene* currentScene = dynamic_cast<InGameScene*>(GET_SINGLE(SceneManager)->GetCurrentScene()); //static_cast나 dynamic_cast로 받아줘야 하는데 확실하지 않으니 dynamic_cast로 받아줌
			if (currentScene != nullptr) // currentScene가 존재하면
			{
				currentScene->ChangeGameState(GameState::Play);
			}

		}
	}

}