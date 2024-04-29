#pragma once

// �̸��� �ʹ� ��ٰ� �����ȴٸ�
// �����ϸ� ������ ����.
// 64�ڰ� �Ѵ����� �ϴ� �����ض�
// ��ť��Ʈ�����δ� 128�� ���� ���δٰ� �Ѵ�
class HammerActor;
class MoleActor;
class PlayerHammerController
{
public:
	void Init(HammerActor* playerHammer, vector<MoleActor*> moles);
	void Update();

	//  - �÷��̾� �ظӸ� ���콺 ��ġ�� �����Ų��.
	void ChangePlayerHammerPos();

	//  - ���콺�� Ŭ���ϸ�, �÷��̾� �ظӿ� �δ����� �浹�Ǿ� ������ ������ ������.
	//		�δ����� �״´�.
	void CatchMole();

private:
	HammerActor* _playerHammer;
	vector<MoleActor*> _moles;

};
