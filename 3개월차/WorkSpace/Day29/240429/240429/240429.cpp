﻿// 240429.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 프로그램 실행 : <Ctrl + F5> 또는[디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.


#include <iostream>
using namespace std;

// 부동소수점 오차를 잡아주는 범위
// 프로그래밍에서 실수에서 이정도 오차는 같은 수라고 봐주겠다.. 하는 범위
#define EPSILON 1e-6f // 0.000001 

int main()
{
    // 부동소수점
    int a = 1;
    int b = 2;
    bool c = a + b == 3;

    cout << a + b << endl;
    cout << c << endl;

    float d = 0.1;
    float e = 0.2;

    //요게핵심!!!
    //1. 얘가 안되는 건 알아야함. (필수)
    //2. 얘가 안되는 이유. (면접때는 준비해야함) (굳이 평소엔 알필요없긴함.)
    // false가 들어간다. 이게 안된다는건 평소부터 알아야 한다.
    // 그 이유는 밑에 있는데 그걸 면접땐 알아야함
    bool f = d + e == 0.3; // 근데 이런코드가 필요할때가 오긴함

    // Vector까지 나간마당에
    // ----- 여기 내용 못봄 선생님꺼 보고 확인하기

    // 근데
    float g = 0.1f;
    float h = 0.2f;
    // 이거는 true가 들어간다 f를 통해 반올림이 되기 때문!
    bool i = g + h == 0.3f;

    bool j = abs(0.3 - (d + e)) <= EPSILON;
    

    cout << d + e << endl; // 근데 이거로 출력하면 막상 0.3이 출력된다.
    cout << f << endl; // 근데 다르다고 한다는것은 다르다는 것!
    // 다음을 알면 된다.

    // 실수의 원리
    // float <- 4byte (32비트)
    // 어떻게 활용할거냐에 따라, 범위가 달라진다.
    // 1비트 -> 양수, 음수
    // N비트 -> 정수를 표현하는데 쓰임
    // 나머지비트 -> 소수점을 표현하는데 사용

    // 0.5를 표현할때
    // 0.5 => 2의 -1제곱
    // 0.25 => 2의 -2제곱
    // 0.75 => 2의 -1제곱 + 2의 -2제곱
    // 0.1 => 어떻게 표현하나? 2의 보수가 아닌데??
    // 엄청 세세하게 나눠서
    // 거의 0.1과 비슷하게 만든다는 것
    // 그러니 0.1 + 0.2 != 0.3인 것!!

    // 1 => 2의 0제곱
    // 2 => 2의 1제곱
    // 3 => 2의 1제곱 + 2의 0제곱
    // 4 => 2의 2제곱
    // 5 => 2의 2제곱 + 2의 0제곱
    // 6 => 2의 2제곱 + 2의 1제곱
    // ...
    
    // int <- 4byte (1바이트 == 8비트) (32비트)
    // int의 범위    (1비트 => 양수냐 음수냐를 따지는 데 쓰임)
    // -21억 ~ 21억  << 2의 31제곱 ==> 21억

}