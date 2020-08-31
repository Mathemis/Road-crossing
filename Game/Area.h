#ifndef AREA_H
#define AREA_H

#include <string>
#include "PConsole.h"
#define WIDTH 135
#define HEIGHT 43
#define LANE 6

#define x0 1
#define y0 1

inline void drawArea()
{
	int x = x0, y = y0;
	// khung tren
	gotoxy(x, y);
	printf("%c", 201);
	forc(i, 0, WIDTH, 1) printf("%c", 205);
	printf("%c", 187);
	// cac lane
	forc(i, 0, 5, 1) {
		forc(j, 0, LANE, 1) {
			gotoxy(x + j + 1, y);
			printf("%c", 186);
			gotoxy(x + j + 1, y + WIDTH + 1);
			printf("%c", 186);
		}

		gotoxy(x += LANE + 1, y);
		printf("%c", 186);
		if (i == 0 || i == 4) {
			textcolor(DarkGreen);
			forc(j, 0, WIDTH, 1)  printf("=");
			textcolor(White);
		}
			
		else {
			textcolor(Grey);
			forc(j, 0, WIDTH, 1)  printf("-");
			textcolor(White);
		}
		printf("%c", 186);
	}
	forc(j, 0, LANE, 1) {
		gotoxy(x + j + 1, y);
		printf("%c", 186);
		gotoxy(x + j + 1, y + WIDTH + 1);
		printf("%c", 186);
	}
	// khung duoi
	gotoxy(x += LANE + 1, y);
	printf("%c", 200);
	forc(i, 0, WIDTH, 1) printf("%c", 205);
	printf("%c", 188);
}

inline void Message(string s) {
	textcolor(15);
	gotoxy(HEIGHT - 11, WIDTH + 15);
	cout << s;
}

inline void clearMessage()
{
	int x = HEIGHT - 12, y = WIDTH + 15;
	gotoxy(x, y);
	forc(i, 0, 6, 1) {
		gotoxy(x + i, y);
		printf("                                               ");
	}
}


inline void Status() {
	int x = 20, y = WIDTH + 15;
	int w = 14;
	// ve khung
	gotoxy(x, y);
	printf("%c", 218);
	forc(i, 0, w, 1) printf("%c", 196);
	printf("%c", 191);
	forc(i, 0, 3, 1) {
		gotoxy(x + i + 1, y);
		printf("%c", 179);
		gotoxy(x + i + 1, y + w + 1);
		printf("%c", 179);
	}
	gotoxy(x + 4, y);
	printf("%c", 192);
	forc(i, 0, w, 1) printf("%c", 196);
	printf("%c", 217);
	//

	gotoxy(x + 2, y + 3);
	printf("LEVEL:");
}

inline void drawLevel(int level) {
	textcolor(Yellow);
	gotoxy(22, WIDTH + 26);
	printf("%-3d", level);
	textcolor(White);
}

inline void drawSkull(int x, int y)
{
	gotoxy(x, y);
	printf("%c%c       %c%c", 220, 219, 219, 220); delay(20);
	gotoxy(x + 1, y + 2);
	printf("%c%c%c%c%c%c%c", 220, 219, 219, 219, 219, 219, 220); delay(20);
	gotoxy(x + 2, y + 2);
	printf("%c%c%c%c%c%c%c", 219, 220, 220, 219, 220, 220, 219); delay(20);
	gotoxy(x + 3, y);
	printf("%c%c %c%c%c%c%c %c%c", 220, 220, 219, 223, 219, 223, 219, 220, 220); delay(20);
	gotoxy(x + 4, y + 1);
	printf("%c       %c", 223, 223); delay(20);
}

inline void clearSkull(int x, int y)
{
	forc(i, 0, 5, 1) {
		gotoxy(x + i, y);
		printf("           ");
	}
}

inline void Instruction()
{
	gotoxy(HEIGHT + 3, y0 + 2);
	textcolor(Grey);
	printf("Press ");
	textcolor(White);
	printf("LEFT, RIGHT, UP, DOWN");
	textcolor(Grey);
	printf(" on the keyboard for moving");
	textcolor(White);
}

inline void drawLight(int x, int y, int color)
{
	gotoxy(x, y);
	textcolor(color); 
	printf("%c%c", 219, 219);
	textcolor(White); 
}

inline void drawFrame(int x, int y) {
	int w = 70;
	gotoxy(x, y);
	printf("%c", 218);
	forc(i, 0, w, 1) printf("%c", 196);
	printf("%c", 191);

	gotoxy(x + 1, y);
	printf("%c", 179);
	gotoxy(x + 1, y + w + 1);
	printf("%c", 179);

	gotoxy(x + 2, y);
	printf("%c", 192);
	forc(i, 0, w, 1) printf("%c", 196);
	printf("%c", 217);
}

#endif // AREA_H