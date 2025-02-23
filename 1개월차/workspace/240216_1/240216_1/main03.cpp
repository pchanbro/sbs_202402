#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	// 난수
	// 랜덤수 

	// 랜덤수를 배우는 이유

	// 게임에서는 랜덤 없이는 할 수 있는게 없다.
	
	// 가위바위보를 할 때 뭐를 낼지
	// 캐릭터 데미지도 랜덤이 어느정도 들어간다.(메이플의 스킬도 쓸 때 마다 데미지가 다름)

	// 랜덤 쓰는 법 (암기과정)
	// 1. #include <time.h>
	// 2. main문 안에서
	// srand(time(NULL)); 명령을 실행
	// 3. rand()를 사용하면 랜덤수가 뽑힘

	srand(time(NULL));
	int 랜덤수 = rand(); 
	::printf("랜덤 값 : %d\n", 랜덤수);
	::printf("랜덤 값 : %d\n", 랜덤수); // 참고로 이렇게 두 번 쓴다고 해서 두번 째에 다른 수가 오지는 않는다 위에서 초기화해줄 때 한 번 랜덤으로 가져올 뿐이기에 윗줄과 결과값이 같아진다.
	::printf("랜덤 값 : %d\n", rand());
	::printf("랜덤 값 : %d\n", rand());
	::printf("랜덤 값 : %d\n", rand());
	::printf("랜덤 값 : %d\n", rand());
	::printf("랜덤 값 : %d\n", rand());
	::printf("랜덤 값 : %d\n", rand());



	// srand(값);
	// => rand()를 하면 컴퓨터에서 예정된 시드값을 뽑아온다.
	// => 예정된 시드값을 섞어주는 함수가 srand
	// 근데 srand(값)에 들어가는 '값'이 고정되면 rand()값도 고정이 된다.
	// 그렇다면 위에 '값'이 랜덤이 되어야 하는게 아닌가?

	// 그걸 이제 시간으로 돌리자.

	// time(NULL) 
	// => 현재 시간
	// => 1970년 1월 1일부터 현재까지 몇틱이 지났는지

	// => 그럼 사실상 time(NULL)이 랜덤인데
	// 왜 rand()를 굳이 쓰는가?
	// => 불법 악성유저들은 1970년 1월 1일부터 현재까지 몇틱이 지났는지을 계산해서 
	// 프로그램에 취약점이 있는지 테스트한다.
	// 예를 들면 뽑기(가챠)같은거에서
	// 그렇기에 위험성이 존재함
	// 나중에 다른 랜덤을 배울 것이다.

	// 난수를 더 잘 다루기 위해서는 
	// 사칙 연산을 배워야한다.
}