#include "CGame.h"
#include <mutex>
using namespace std;

// global variable in CGame.h
int KEY = -1; 
bool PauseThread = false;
//

GAME cg;

void ThreadFunc1() {
	while (cg.isExit() == false) {
		if (PauseThread == false) KEY = _getch();
	}
}

int main()
{
	resizeConsole(1700, 800);
	fixConsoleWindow();
	Nocursortype();
	mutex m;
	int menuKey = -1;
	bool end = false;
	drawLoading();
	while (end == false) {
		introMenu(11, 42, menuKey);
		if (menuKey == 0) {
			thread t1(ThreadFunc1);
			cg.startGame();
			if (cg.isExit()) {
				end = true;
				t1.join();
			}
			//clearScreen();
		}
		else if (menuKey == 1) {
			if (cg.loadGame()) {
				thread t1(ThreadFunc1);
				cg.startGame();
				if (cg.isExit()) {
					end = true;
					t1.join();
				}
			}
		}
		else if (menuKey == 2) {
			cg.setting();
		}
		else {
			cg.exitGame();
			if (cg.isExit()) end = true;
		}
	} 
	clearScreen();
	GoodBye();
	_getch();

	return 0;
}
