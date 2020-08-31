#ifndef HUMAN_H
#define HUMAN_H


#include "PConsole.h"
#include "Obstacle.h"
#include "Area.h"



class HUMAN {
private:
	int _x, _y;
	bool _state; // dead 0 - live 1
	int _step;
	int score;

public:
	HUMAN() 
	{
		_x = x0 + 2 + 5 * (LANE + 1);
		_y = y0 + 2 + WIDTH / 2 - 7;
		_step = 3;
		_state = 1;
	}

	void Draw() 
	{
		gotoxy(_x, _y);
		printf("  %c%c%c", 219, 219, 219);
		gotoxy(_x + 1, _y);
		printf("%c%c%c%c%c%c%c", 220, 220, 220, 219, 220, 220, 220);
		gotoxy(_x + 2, _y);
		printf("%c %c%c%c %c",223, 219, 219, 219, 223);
		gotoxy(_x + 3, _y);
		printf("  %c %c",219, 219);
	}
	
	void Clear() 
	{
		forc(i, 0, 4, 1) {
			gotoxy(_x + i, _y);
			printf("       ");
		}
	}

	void Up() 
	{
		Clear();
		if (_x >= x0 + 2 + LANE + 1) {
			_x -= LANE + 1;
		}
		Draw();
	}

	void Down() 
	{
		Clear();
		if (_x <= x0 + 2 + 4 * (LANE + 1)) {
			_x += LANE + 1;
		}
		Draw();
	}
	
	void Left() 
	{

		Clear();
		if (_y >= y0 + 2 + _step) {
			_y -= _step;
		}
		Draw();
	}
	
	void Right() 
	{
		Clear();
		if (_y <= WIDTH - _step - 5) {
			_y += _step;
		}
		Draw();
	}
	
	bool isImpact(OBSTACLE *p)
	{ 
		if (_y < p->getY() + 11 && _y + 7 > p->getY()) return 1;
		return 0;
	}
	
	int LanePos() 
	{
		return (_x - y0 - 2) / (LANE + 1); 
	}
	
	void updatePos(int x, int y) 
	{
		_x = x;
		_y = y;
	}

	int getX() { return _x; }
	
	int getY() { return _y; }

	void drawUp() 
	{
		gotoxy(_x, _y);
		printf("  %c%c%c", 219, 219, 219);
		gotoxy(_x + 1, _y);
		printf("%c%c%c%c%c%c%c", 219, 220, 220, 219, 220, 220, 219);
		gotoxy(_x + 2, _y);
		printf("  %c%c%c", 219, 219, 219);
		gotoxy(_x + 3, _y);
		printf("  %c %c", 219, 219);
	}
};


#endif // HUMAN_H
