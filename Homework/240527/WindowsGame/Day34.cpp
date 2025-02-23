#include "pch.h"

void Comment1()
{
	// 1. 숙제 풀이
	//  - 버튼누르면 씬이동

	// 2. Layer
}

void Comment2()
{
	// Layer란?
	//  - Item이 장애물 뒤에 나오게 되면, 이상하게 보일 것이다.
	// 이런 것들을 Layer로 정해주고
	// 이 요소들은 항상 얘 앞에, 항상 얘 뒤에 그린다.
	// 이런 것들을 정해주는게 Layer이다.

	// 비슷한 애들끼리 모아서 그 친구들끼리 무언가를 해주는게 Layer구나
}

void Comment3()
{
	// 여태까지 배운 layer 개념은
	// 통상적으로 쓰이는 layer
	// 디자이너도 이렇게 부르고, 기획자도

	// 게임 프로그래머
	//  - [Collision Layer]

	// Collision Layer
	// - 게임 프로그래밍에서 최적화를 해야한다면, 충돌체크
	// - 충돌체크가 매프레임(144fps, 1초에 최소 144번) 
	// - 그 게산로직이 생각보다 복잡함 (폴리곤, 3D Collider)
	//  - 그 양은 (탄막 슈팅게임에서)총알이 100개 있다고 치고, 몬스터가 30마리 있다고치면
	//  - 총 130개의 오브젝트 130 * 130번 만큼 그 Collider Check 로직을 돌리게 된다.
	//  - 대충 17000번을 1초에 144번
	//  - 근데 충돌로직을 개선할 수 있는 방법은 없다.
	//  - 이미 수학자들이 만들어 놓은걸 우리가 개선하긴 어려움
	//  - 그냥 우리는 [충돌 횟수를 줄이는게] 최선
	//    - 충돌체크로직을 개선할 수 없으면, 할 수 있는것은 충돌체크 횟수를 줄이는것



	// [여담]
	// 게임 프로그래밍이 난이도가 제일 높다 한다.
	// 웹, 임베디드, 등 중에서
	// [144FPS => 1프레임에 허락된 시간 10ms도 안된다.]
	//  - 철권같이 조작키를 많이 타는데도, 1프레임이 튀면, 유저가 떠난다.. 코딩이 힘든데 예민하다.
	// 그래서 사실 이 부분을 잘 조절할 수 있으면 충분하다.


	// 충돌체크를 줄인다는건 무슨말인가??

	// ex) 탄막슈팅게임, 1942 같은거
	//  총알끼리 충돌체크를 하는것이 의미가 있을까? (X)
	//  총알 <-> Character 만 충돌체크를 하면 될 것같다.

	// 총알 : 100개
	// 캐릭터 : 30개

	// 130 * 130 번의 충돌체크가 아니라
	// 100 * 30 번의 충돌체크 13000번이나 줄었다.

	// Collision Layer
	// ==> 최적화의 일종, 이것부터 잡는다.
}

void Comment4()
{
	// 비트연산자
	// 비트연산에 대하여
	// 콘솔 Day34 참고
}

