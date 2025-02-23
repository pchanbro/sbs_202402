// 프로젝트 속성 - 링커 - 시스템 -  창(/ SUBSYSTEM:WINDOWS)
// 프로젝트 속성 - C/C++ - 전처리기 - _DEBUG;_WINDOWS;%(PreprocessorDefinitions)

//====================================
//		## 헤더파일 선언 ##
//====================================
#include "pch.h"

//====================================
//		## 전역변수 선언 ##
//====================================
HINSTANCE _hInstance;
HWND _hWnd;

//====================================
//		## 함수 전방 선언 ##
//====================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void SetWindowSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;

	WNDCLASS wndClass = {};
	wndClass.cbClsExtra = 0;										// 클래스 여분 메모리
	wndClass.cbWndExtra = 0;										// 윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);	//백그라운드 색
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//커서
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//아이콘
	wndClass.hInstance = _hInstance;								//인스턴스 핸들
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//### 제일중요 ### : 윈도우 프로시저
	wndClass.lpszClassName = _T("SBS Academy");						//클래스 이름
	wndClass.lpszMenuName = NULL;									//메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						//윈도우 스타일

	::RegisterClass(&wndClass);

	//====================================
	//		## 2. 윈도우 생성 ##
	//====================================
	// CreateWindow 윈도우 생성함수

	_hWnd = CreateWindow(
		_T("SBS Academy")				//클래스 이름
		, _T("SBS Academy")				//윈도우 이름
		, WS_CAPTION | WS_SYSMENU		//윈도우 스타일
		, 0								//x
		, 0								//y
		, 800							//width
		, 600							//height
		, NULL							//부모 윈도우
		, NULL							//메뉴 핸들
		, _hInstance					//사용할 인스턴스 핸들
		, NULL							//부모가 나를 생성했을때, 어떤 인자로 생성했는지
	);

	SetWindowSize(0, 0, 800, 600);


	//====================================
	//		## 3. 윈도우 출력 ##
	//====================================
	//ShowWindow

	::ShowWindow(_hWnd, nCmdShow);

	//====================================
	//		## 4. 메세지 루프 ##
	//====================================

	MSG message;
	while (true)
	{
		if (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			//번역하다
			::TranslateMessage(&message);
			//실행시키다
			::DispatchMessage(&message);
		}
		else
		{

		}
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}

void SetWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, false);

	SetWindowPos(_hWnd, NULL, x, y, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);
}
