﻿// 인클루드가 없다.
// 일단 지금 C#은 필요한 include 다 되어있다고 생각하면 된다.

namespace _240614_01 // namespace 이런 공간, 있어도 되고 없어도 되고
{
    // internal은 이 프로젝트 안에서 public으로 쓰겠다는거
    // 이거 말고도 public, private도 있다.
    // 잘 모르겠다 싶으면 그냥 public 써라
    // internal보다 public이 좀 더 일반적이다.
    public class Program // _240614_01 이라는 namespace에 Program이 있다
    {
        // 여기선 이제 C++처럼
        // public : 
        // private : 
        // 이런식으로 섹션을 나눠서 지정해주는게 아니라
        // 함수마다 앞에 public, private등을 붙여서 적어준다.
        public static void Main(string[] args) // arguments는 사실 있으나 없으나 상관 없다.(생략이 가능)
        {
            // C#은 기본적으로 메인문 따라가는데 Program 클래스 안에 있는 메인문을 따라감
            Console.WriteLine("Hello, World!");

            Console.WriteLine("동해물과 백두산이 마르고 닳도록");
            Console.WriteLine("하느님이 보우하사 우리나라 만세");
            Console.WriteLine("무궁화 삼천리 화려강산");
            Console.WriteLine("대한사랑 대한으로 길이 보전하세");
        }
    }
}


// 새로운 언어를 배울때 체크해야할 것.
// 나는 C, C++ 를 배워서
// 언리얼엔진을 배워서 회사에서 취업해서
// 언리얼엔진으로 게임만들것이다.


// -> C++만 배우면 끝나는거아니야? -> 그런 케이스는 정말 드물다, 스페셜리스트들

// 본격적인 게임을 만들게되면 (회사에 취업하거나, 인디게임을 만들거나)
// 엔진작업보다 엔진 외적인 작업을 해야할 경우가 상당히 많아요.

// C++로는 그런툴을만들기에는 많이 어렵습니다.

// 대체로 선택하는게, C#이나 Python 같은 고급언어를 많이 선택해요.
// 가끔 Javascript 도 선택을하는데 게임 개발자에겐 좀 어색해서 보통 C#이나 Python 선택함


// 회사에 취업했는데
// 팀장님이 파이썬으로 뭐 만들어와.
// 나는 C++밖에 안했는데 그걸 어떻게만들지?
// 
// 신규언어 배울때 보통 기간을 회사기준 하루줍니다.
// 
// 신규언어를 배울때 체크해야할것.

// (언어를 하나 확실하게 안다는 가정) 

// 1주일차~ 2주일차때 했던과정들을 상상해보면돼요.

// 1) 변수 선언 + 사칙연산
// 2) if문, for문, while문 
// 3) 함수 콜 (매게변수의 값을 변경하는 방법) (in, out 함수 포함) (reference 형태)
// 4) STL 중에서 vector, map 을 이 언어에는 어떻게 사용하는지?
// 5) 이정도 배우고 그러면 C++에서 만들었던 숙제들을 지금당장 구현할수있는지?
// 6) 메모리구조. (Heap, Stack, Code, Data) (좀 큰프로젝트를 만들때 꼭 알아둘것.) (신입들 자주 까먹는데 매우 중요한 요소다)
// 7) [클래스, 인터페이스] -> 모든 언어에 다 있는 특성으로 사용방법만 익히면된다.
//    - 프로그램 아키텍처이기에 얼마나 프로그램 구조를 잘 짜냐 설계를 잘하냐의 문제


// 1. 사용자정의자료형 (Enum, Class, Struct)
// 2. object 특징


// 딱 저정도만 배우면, 일단 사용가능한 언어라고 생각하시면됩니다.