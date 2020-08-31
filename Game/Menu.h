#ifndef MENU_H
#define MENU_H



#include "PConsole.h"
//#include <iostream>
//using namespace std;
#include <string>


inline void drawLoading()
{
	int x = 20, y = 80;
	int w = 45;
	gotoxy(x - 2, y + 18);
	printf("LOADING...");
	gotoxy(x, y);
	printf("%c", 201);
	forc(i, 0, w, 1) printf("%c", 205);
	printf("%c", 187);
	gotoxy(x + 1, y);
	printf("%c", 186);
	gotoxy(x + 1, y + w + 1);
	printf("%c", 186);
	gotoxy(x + 2, y);
	printf("%c", 200);
	forc(i, 0, w, 1) printf("%c", 205);
	printf("%c", 188);
	gotoxy(x + 1, y + 1);
	textcolor(10);
	forc(i, 0, w, 1) {
		delay(25);
		if (i > w - 13 && i <= w - 10) delay(50);
		if (i > w - 20 && i < w - 18) delay(100);
		printf("%c", 219);
	}
	textcolor(15);
	gotoxy(x - 2, y + 18);
	printf("FINISHED    ");
	delay(400);
}

inline void drawTittle (int x, int y){
	gotoxy(x, y);
	textcolor(DarkRed);
	printf("$$$$$$$\\   $$$$$$\\   $$$$$$\\  $$$$$$$\\          $$$$$$\\  $$$$$$$\\   $$$$$$\\   $$$$$$\\   $$$$$$\\  $$$$$$\\ $$\\   $$\\  $$$$$$\\");
	gotoxy(++x, y);
	printf("$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\        $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ \\_$$  _|$$$\\  $$ |$$  __$$\\");
	gotoxy(++x, y);
	textcolor(Yellow);
	printf("$$ |  $$ |$$ /  $$ |$$ /  $$ |$$ |  $$ |       $$ /  \\__|$$ |  $$ |$$ /  $$ |$$ /  \\__|$$ /  \\__|  $$ |  $$$$\\ $$ |$$ /  \\__|");
	gotoxy(++x, y);
	printf("$$$$$$$  |$$ |  $$ |$$$$$$$$ |$$ |  $$ |       $$ |      $$$$$$$  |$$ |  $$ |\\$$$$$$\\  \\$$$$$$\\    $$ |  $$ $$\\$$ |$$ |$$$$\\");
	gotoxy(++x, y);
	textcolor(Green);
	printf("$$  __$$< $$ |  $$ |$$  __$$ |$$ |  $$ |       $$ |      $$  __$$< $$ |  $$ | \\____$$\\  \\____$$\\   $$ |  $$ \\$$$$ |$$ |\\_$$ |");
	gotoxy(++x, y);
	printf("$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |       $$ |  $$\\ $$ |  $$ |$$ |  $$ |$$\\   $$ |$$\\   $$ |  $$ |  $$ |\\$$$ |$$ |  $$ |");
	gotoxy(++x, y);
	textcolor(DarkCyan);
	printf("$$ |  $$ | $$$$$$  |$$ |  $$ |$$$$$$$  |       \\$$$$$$  |$$ |  $$ | $$$$$$  |\\$$$$$$  |\\$$$$$$  |$$$$$$\\ $$ | \\$$ |\\$$$$$$  |");
	gotoxy(++x, y);
	printf("\\__|  \\__| \\______/ \\__|  \\__|\\_______/         \\______/ \\__|  \\__| \\______/  \\______/  \\______/ \\______|\\__|  \\__| \\______/ "); 
	textcolor(White);
}


inline void introMenu(int a, int b, int &key){
	string List[4] = { "NEW GAME","LOAD GAME","SETTINGS","EXIT" };
	int color[4] = { Red, White, White ,White };
	clearScreen();
	drawTittle(a, b);
	key = 0;
	int move = -1;
	do {
		int x = a + 11, y = b + 52;
		forc(i, 0, 4, 1) {
			gotoxy(x + 2*i, y);
			textcolor(color[i]);
			cout << List[i];
		}
		textcolor(White);	
		do {
			move = _getch();
			switch (move) {
			case UP :
				if (key > 0) key--;
				break;
			case DOWN:
				if (key < 3) key++;
				break;
			case ENTER:
				break;
			}
		} while (move != UP && move != DOWN && move != ENTER);

		forc(i, 0, 4, 1) color[i] = White;
		color[key] = Red;

	} while (move != ENTER);
	
}


inline void ingameMenu()
{
	textcolor(Red);
	gotoxy(2, WIDTH + 25);
	printf("IN-GAME MENU");
	gotoxy(4, WIDTH + 15);
	textcolor(Grey); printf("Press on the keyboard");
	gotoxy(6, WIDTH + 15);
	textcolor(Green); printf("P");
	textcolor(White);
	printf(": Pause game");
	gotoxy(8, WIDTH + 15);
	textcolor(Green); printf("R");
	textcolor(White);
	printf(": Resume game");
	gotoxy(10, WIDTH + 15);
	textcolor(Green); printf("L");
	textcolor(White);
	printf(": Load game from file");
	gotoxy(12, WIDTH + 15);
	textcolor(Green); printf("S");
	textcolor(White);
	printf(": Save game to file");
	gotoxy(14, WIDTH + 15);
	textcolor(Green); printf("T");
	textcolor(White);
	printf(": Settings");
	gotoxy(16, WIDTH + 15);
	textcolor(Green); printf("ESC");
	textcolor(White);
	printf(": Exit");
}



inline void GoodBye()
{
	int x = 20, y = 80;
	//textcolor(Red);
	textcolor(Yellow);
	gotoxy(x, y);
	printf("  ____                 _    ____");
	gotoxy(++x, y);
	printf(" / ___| ___   ___   __| |  | __ )");
	//textcolor(Yellow);
	gotoxy(++x, y);
	printf("| |  _ / _ \\ / _ \\ / _` |  |  _ \\| | | |/ _ \\");
	gotoxy(++x, y);
	printf("| |_| | (_) | (_) | (_| |  | |_) | |_| |  __/");
	//textcolor(Green);
	gotoxy(++x, y);
	printf(" \\____|\\___/ \\___/ \\__,_|  |____/ \\__, |\\___|");
	gotoxy(++x, y);
	printf("                                  |___/");
	textcolor(White);
}


inline void Sound(bool &on)
{
	int x = 20, y = 90;
	clearScreen();
	textcolor(Yellow);
	gotoxy(x, y);
	printf("Turn SOUND:");
	string List[2] = { "ON","OFF" };
	int color[2] = { DarkRed, White };
	int key = 0;
	int move = -1;
	do {
		gotoxy(x + 2, y + 3);
		textcolor(color[0]);
		cout << List[0];
		gotoxy(x + 4, y + 3);
		textcolor(color[1]);
		cout << List[1];
		textcolor(White);
		do {
			move = _getch();
			switch (move) {
			case UP:
				if (key == 1) key--;
				break;
			case DOWN:
				if (key == 0) key++;
				break;
			}
		} while (move != UP && move != DOWN && move != ENTER);

		color[0] = White;
		color[1] = White;
		color[key] = DarkRed;

	} while (move != ENTER);
	if (key == 0) on = true;
	else on = false;
}

inline void Level(int &level)
{
	int x = 19, y = 88;
	clearScreen();
	textcolor(Yellow);
	gotoxy(x, y);
	printf("Choose LEVEL:");
	string List[4] = { "Level 1","Level 2","Level 3","Level 4" };
	int color[4] = { DarkRed, White, White, White };
	int key = 0;
	int move = -1;
	do {
		forc(i, 0, 4, 1) {
			gotoxy(x + 2 * i + 2, y + 2);
			textcolor(color[i]);
			cout << List[i];
		}
		textcolor(White);
		do {
			move = _getch();
			switch (move) {
			case UP:
				if (key > 0) key--;
				break;
			case DOWN:
				if (key < 3) key++;
				break;
			}
		} while (move != UP && move != DOWN && move != ENTER);

		forc(i, 0, 4, 1) color[i] = White;
		color[key] = DarkRed;

	} while (move != ENTER);
	level = key + 1;
}

#endif // MENU_H