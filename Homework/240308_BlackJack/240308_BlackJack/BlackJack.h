#pragma once

struct Card
{
	int Index;

	void Print();
	void Swap(Card& another);

};

class BlackJack
{
private:
	int _playerMoney = 1000;
	int _betMoney = 0;
	int _deckIndex = 0;
	Card _myCard[10] = {};
	Card _dealerCard[10] = {};
	int _myIndex = 0;
	int _dealerIndex = 0;
	int _myCardSum = 0;
	int _delearCardSum = 0;
public:
	// �Լ��� �����ϸ� �Ű������� �����͸� �������� ���� ����
	// �װ� C��Ÿ���̱� ����
	// �����δ� vector�� �޾��ַ��� ����
	// �״ϱ� �������ʹ� vector�� ����ض�
	BlackJack();
	~BlackJack();
	void GenerateCard(Card* deck);
	void SuffleDeck(Card* deck);
	bool IsContinue();
	void Betting();
	void GiveCard(Card* deck, Card* card, int& index);
	void showMyCardNumber(Card* myCard, int myIndex);
	void showDealerCardNumber(Card* dealerCard, int dealerIndex);
	void DoGetMoreCard(Card* deck);
	void dealerGetCard(Card* deck);
	void showResult();
	void isDeckAllUsed(Card* deck);
};
