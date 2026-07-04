#include<Windows.h>
#include"resource.h"

//Протатип функции:
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, NULL);
}

//Реализация функции:
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:  //Отрабатывает один раз, при запуске окна.
		break;
	case WM_COMMAND:	//Отработка нажатия кнопок, действий мышью, и т.д.
		switch (LOWORD(wParam))
		{
		case IDOK: MessageBox(hwnd, "Была нажата кнопка ОК!", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwnd, 0);
		}
		break;
	case WM_CLOSE:		//Отрабатывает при нажатии на кнопку закрытия окна "Х".
		EndDialog(hwnd, 0);
		break;
	}
	return FALSE;
}