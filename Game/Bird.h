#ifndef BIRD_H
#define BIRD_H


#include "Obstacle.h"

class BIRD :public OBSTACLE {
public:
	BIRD() {
		_x = x0 + 2 + 2 * (LANE + 1);
		_y = y0 + 2;
	}

	void setY(int y) {
		_y = y;
	}

	void Move(int level) // Right
	{
		Clear();
		_y += level;
		if (_y + w_SIZE > WIDTH + 2) _y = y0 + 2;
		textcolor(Red);
		gotoxy(_x, _y);
		printf("      %c%c%c%c%c", 219, 223, 219, 220, 220);
		gotoxy(_x + 1, _y);
		printf(" %c%c%c%c%c%c%c%c", 220, 220, 220, 219, 219, 219, 219, 219);
		gotoxy(_x + 2, _y);
		printf("%c%c%c%c%c%c%c%c%c", 219, 219, 220, 220, 220, 220, 219, 219, 219);
		gotoxy(_x + 3, _y);
		printf("  %c%c%c%c%c%c%c", 223, 223, 223, 219, 219, 223, 223);
		textcolor(White);
	}
};



#endif // BIRD_H