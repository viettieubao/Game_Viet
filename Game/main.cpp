#include "WindowGame.h"
#include "Graphic.h"
#include "Textture.h"
#include "GameTime.h"
#include <Windows.h>
#include <string>
#include "Map.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow) {
	WINDOW->initHandleWindows(hInstance, nCmdShow);
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	Map* map = new Map();
	map->init("Data\\Map\\level2\\level2.MatrixTile.txt", "Data\\Map\\level2\\level2.TileSheet.png");
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			if (GAME_TIME->canCreateFrame()) {

				GRAPHICS->BeginGraphics();
				map->draw();
				GRAPHICS->EndGraphics();
				GRAPHICS->PresentBackBuffer();
			}
			else {
				timeBeginPeriod(1);
				Sleep((DWORD)(1000 * (GAME_TIME->minFrameTime)));
				timeEndPeriod(1);
			}
		}
	}
	delete WINDOW;
	delete GRAPHICS;

	return nCmdShow;
}