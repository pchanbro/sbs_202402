#include "pch.h"

void Comment1()
{
	// 오늘 수업할거

	// 1. 벽돌깨기 저번에 다못한거 마무리하겠습니다.
	// 
	// 2. 리소스매니저 -> 이미지 붙일수 있도록 작업
	//		수요일까지 진행
}

void Comment2()
{
	// 벽돌깨기를 다 완성을 못했다면
	// 로직이 어려워서 못했을가능성은 되게 낮아요

	// 빙고보다 쉽습니다.
	// 로직자체는 남은게 
	// 1. 벽돌생성해준다. 
	// 2. 벽돌과 볼이 부딪히면 벽돌이 사라진다.


	// 로직이 어려워서 못했다 (X)
	// -> 프레임워크를 어떻게 활용해야하는지.
	//		내 생각을 어떻게 코드로 옮겨야하는지
	//		이게 안되어서 못하신분들이 많을거에요.


	//BrickActor 벽돌액터
	// 를 만들어주는게 가장 중요.
}

void Comment3()
{
	// 함수를 사용하는 이유
		//  - 1. 가독성
		//  - 2. 재활용성 (유지보수)


		// 개발하다보면
		// 함수로 안되어있는 내용을 복사할일도 생기고
		// 아니면 if땜질로 되게끔 만드는 경우도 있다.

		// 정답일수도 있다
		// 기본적으로 프로그래밍은 정상적으로 돌아가기만하면 다 정답입니다.
		// 그 이후로 어떻게 유지보수할 떄 잘할 수 있냐 << 이걸 다음 단계에서 고민하는거에요
		// 근데 지금 시기는 사실 프로그램이 돌아갈 수 있게끔만 만들어라
		// 충분한 시간을 두고 고민해라 
		// 그런 고민은 입사 이후에 해도 늦지 않다

		// 계속 생각하면서 코드짜다보면 누구나 언젠간 할 수 있게된다.
		// 함수로할건지, if땜질로 할건지, 아니면 다른방법으로 할건지에 대해서는 

		// 우리가 함수를 왜 배웠는지, if를 왜 배웠는지, 여러가지 방법을 왜 배웠는지를 생각해보자

		// 그리고 기획이 다이나믹하게 바뀌었을때를 상상하면 또 정답이 나온다.
		// 어떻게 짜둔 코드가 더 쉽게 변경될 수 있을까를 고민해라

		// 또 코드는 혼자 짜는게 아님을 고려해라
		// 수정은 혼자하는게 아니다.
		// 만약 내가 한 것처럼 
		// 튕기는 if문에 ||으로 조건을 추가하면
		// 이후에 점점 || 조건이 추가되어 기괴해진다.
		// 그리고 그 이후에 if문 안에서 더 기괴한짓이 일어난다.

		// 최대한 if문은 한글로 읽을 수 있게 만들어주는게 좋다.


		// 프로그래밍 관련 학과 나온 사람들은 줄이 짧은것에 집착하는 사람이 많은데

		// 오히려 컨텐츠쪽 코드는
		// 줄수가 많을수록 유지보수가 쉬울때가 많다.
		// 그리고 줄수가 많다고 느려지지도 않는다. (컨텐츠쪽은)

		// 컨텐츠쪽의 대부분의 부하는
		// 렌더링에서 걸린다.
		// 근데 이 내용은 면접땐 말하지 말아라 
}

void Comment4() 
{
	// 오늘 리소스 매니저를 만들거다

	// 리소스 매니저란 무엇인가?

	// 게임을 보면
	// 2D이미지도 있고, 3D 모델링도 있고, 사운드도 나온다.
	// 그 친구들의 특징이 있다.
	// 바로 용량이 상당히 크다는 것

	// 용량이 크면 솔루션안에 넣기가 힘들다.

	// 용량이 큰 리소스들은 Windows에서 기본으로 제공해주는 리소스 관련 기능으로는 힘들다.

	// 결국 리소스는 외부에서 리소스를 로딩해줘야한다.
	// 실제로 exe파일은 100MB인 반면,
	// 리소스파일은 30GB 이런경우가 많다.

	// 결국 리소스매니저는
	//  - 외부에서 오는 리소스들을 관리해주는 매니저
}

void Comment5()
{
	//map은 
	// BinaryTree의 데이터를 key로 들어가게하고 (wstring)
	// 그안에 실제데이터(ResourceBase*) 가 따로 있다 

	//map의 장점은
	// 검색이 빠르다.
}

void Comment6()
{
	// 리소스를 만들건데

	// Texture와 Sprite부터 만들거다

	// Texture와 Sprite 차이

	// Texture : 이미지
	// Sprite : 이미지(투명색을 지정할 수 있다.)

	// Texture는 이미지 원본
	// Sprite는 Texture(이미지 원본)의 일부를 가리키는 것

	// Texture - 이 텍스처를 구성할 떄 뭐가 필요할지 구상해야 한다.


	// 화면 그리는 과정이 
	// HDC를 만들고
	// HBITMAP으로 그림을 그렸다

	// 텍스처도 같다.
	// 결국에는 완성된 HDC와
	// HBITMAP이 있는것
	// + SIZE (INT형) => Vector2Int
	// + 투명색(Uint32)
	// 256 => 2의 8승

	// 0 ~ 255 (R) => Uint8
	// 0 ~ 255 (G) => Uint8
	// 0 ~ 255 (B) => Uint8
	// 0 ~ 255 (A) => Uint8

	// Uint32(Uint8 4개가 모였으니)
}