#ifndef OBSTACLE_H
#define OBSTACLE_H


#include "PConsole.h"
#include "Area.h"
#define w_SIZE 11
#define h_SIZE 4
#define GAP 30



class OBSTACLE {
protected:
	int _x, _y;
public:
	OBSTACLE() {}
	void Clear()
	{
		if (_y < y0 + 2) return;
		forc(i, 0, h_SIZE, 1) {
			gotoxy(_x + i, _y);
			printf("           "); // w_SIZE
		}

	}
	virtual void setY(int) = 0;
	virtual void Move(int) = 0; // RIGHT or LEFT
	int getY() { return _y; }
};

#endif // MENU_HOBSTACLE_H