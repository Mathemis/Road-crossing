#ifndef CAR_H
#define CAR_H


#include "Obstacle.h"

class CAR :public OBSTACLE {
public:
	CAR() {
		_x = x0 + 2 + LANE + 1;
		_y = WIDTH - w_SIZE;
	}

	void setY(int y) {
		_y = y;
	}

	void Move(int level) // Left
	{
		Clear();
		_y -= level;
		if (_y < y0 + 2) _y = WIDTH - w_SIZE;
		textcolor(Cyan);
		gotoxy(_x, _y);
		printf("    %c%c%c%c%c%c", 220, 220, 220, 220, 220, 220);
		gotoxy(_x + 1, _y);
		printf(" %c%c%c%c  %c%c%c%c", 220, 220, 220, 219, 219, 219, 219, 220);
		gotoxy(_x + 2, _y);
		forc(i, 0, 10, 1) printf("%c", 219); printf("%c", 223);
		gotoxy(_x + 3, _y);
		printf(" %c%c    %c%c", 223, 223, 223, 223);
		textcolor(White);
	}
};


#endif // CAR_H
