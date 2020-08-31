#ifndef TRUCK_H
#define TRUCK_H


#include "Obstacle.h"

class TRUCK :public OBSTACLE {
public:
	TRUCK() {
		_x = x0 + 2 + 3 * (LANE + 1);
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
		//textcolor(White);
		gotoxy(_x, _y);
		printf("    %c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
		gotoxy(_x + 1, _y);
		printf(" %c%c%c%c     %c", 219, 223, 219, 219, 219);
		gotoxy(_x + 2, _y);
		printf("%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 220, 219, 219, 220, 220, 220, 220, 220, 219);
		gotoxy(_x + 3, _y);
		printf("%c%c%c%c%c%c%c%c%c%c%c", 223, 219, 219, 223, 223, 223, 223, 223, 219, 219, 223);
		//textcolor(White);
	}
};

#endif // TRUCK_H


