#include "Main.h"
#include "WindowMsg.h"
#include "GameData.h"
#include "GameManager.h"
#include "LevelData.h"
#include "AllObject.h"

AllObject* allObject = AllObject::getInstance();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;											//������ �ڵ� ����
	MSG Message;										//�޼��� ����ü ���� ����
	WNDCLASS WndClass;									//Windows Class ����ü ���� ����

	WndClass.cbClsExtra = 0;							//���� ����. ������ ���X
	WndClass.cbWndExtra = 0;							//���� ����
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �������� ��� ������ ����
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		//�������� ���콺������ ����� ����
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	//�������� Ŀ�� ������ ��� ����
	WndClass.hInstance = hInstance;						//������ Ŭ������ ����ϴ� ���α׷� ��ȣ
	WndClass.lpfnWndProc = WndProc;						//������ �޼��� ó�� �Լ� ����
	WndClass.lpszClassName = "winapi";					//������ Ŭ������ �̸� ����
	WndClass.lpszMenuName = NULL;						//�޴� ����
	WndClass.style = CS_HREDRAW | CS_VREDRAW;			//�������� ��Ÿ���� ����

	RegisterClass(&WndClass);							//WNDCLASS ����ü�� ������ ����

	GameData* gameData = GameData::getInstance();
	hWnd = CreateWindow("winapi", "winapi",			//�����츦 ����
		WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_CAPTION | WS_VISIBLE, 0,
		0, 16 + gameData->getwindowX(), 39 + gameData->getwindowY()
		, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	GameManager gameManager;
	//�޼��� ������ ����
	while (gameData->getisgaming())
	{
		if (PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);

			DispatchMessage(&Message);
		}
		gameManager.logicUpdate();
	}
	return (int)Message.wParam;							//Ż�� �ڵ�. ���α׷� ����
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	if (iMessage) {
		//�޼������ִٸ� �������ְ�
		WindowMsg::getInstance()->settingMsg(hWnd, iMessage, wParam, lParam);
	}
	else {
		//���ٸ� 0���� �ʱ�ȭ���ݴϴ�
		WindowMsg::getInstance()->settingMsg(hWnd, 0, 0, 0);
	}
	if (WM_DESTROY == iMessage) {
		//���� �޼����� �߻��Ǹ� ������ �����մϴ�
		GameData::getInstance()->setisgaming(false);
	}
	else if (WM_CREATE == iMessage) {
		LevelData::LevelLode("titlescreen");
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}