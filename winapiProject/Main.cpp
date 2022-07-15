#include "Main.h"
#include "WindowMsg.h"
#include "GameData.h"
#include "GameManager.h"
#include "LevelData.h"
#include "AllObject.h"

AllObject* allObject = AllObject::getInstance();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;											//윈도우 핸들 선언
	MSG Message;										//메세지 구조체 변수 선언
	WNDCLASS WndClass;									//Windows Class 구조체 변수 선언

	WndClass.cbClsExtra = 0;							//예약 영역. 지금은 사용X
	WndClass.cbWndExtra = 0;							//예약 영역
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 윈도우의 배경 색상을 지정
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		//윈도우의 마우스포인터 모양을 지정
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	//윈도우의 커서 아이콘 모양 지정
	WndClass.hInstance = hInstance;						//윈도우 클래스를 등록하는 프로그램 번호
	WndClass.lpfnWndProc = WndProc;						//윈도우 메세지 처리 함수 지정
	WndClass.lpszClassName = "winapi";					//윈도우 클래스의 이름 지정
	WndClass.lpszMenuName = NULL;						//메뉴 지정
	WndClass.style = CS_HREDRAW | CS_VREDRAW;			//윈도우의 스타일을 정의

	RegisterClass(&WndClass);							//WNDCLASS 구조체의 번지를 전달

	GameData* gameData = GameData::getInstance();
	hWnd = CreateWindow("winapi", "winapi",			//윈도우를 생성
		WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_CAPTION | WS_VISIBLE, 0,
		0, 16 + gameData->getwindowX(), 39 + gameData->getwindowY()
		, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	GameManager gameManager;
	//메세지 루프를 실행
	while (gameData->getisgaming())
	{
		if (PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);

			DispatchMessage(&Message);
		}
		gameManager.logicUpdate();
	}
	return (int)Message.wParam;							//탈출 코드. 프로그램 종료
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	if (iMessage) {
		//메세지가있다면 갱신해주고
		WindowMsg::getInstance()->settingMsg(hWnd, iMessage, wParam, lParam);
	}
	else {
		//없다면 0으로 초기화해줍니다
		WindowMsg::getInstance()->settingMsg(hWnd, 0, 0, 0);
	}
	if (WM_DESTROY == iMessage) {
		//종료 메세지가 발생되면 게임을 종료합니다
		GameData::getInstance()->setisgaming(false);
	}
	else if (WM_CREATE == iMessage) {
		LevelData::LevelLode("titlescreen");
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}