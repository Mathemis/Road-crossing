#ifndef CGAME_H
#define CGAME_H

#include "Obstacle.h"
#include "Menu.h"
#include "Human.h"
#include "Bird.h"
#include "Car.h"
#include "Dinosaur.h"
#include "Truck.h"
#include "Area.h"
#include <fstream>
#include <vector>
#include <thread>


extern int KEY;
extern bool PauseThread;

class GAME
{
private:
	DINOSAUR *din;
	BIRD *brd;
	CAR *car;
	TRUCK *trk;
	HUMAN hm;
	int num;
	int level;
	bool IS_RUNNING;
	bool onSound;
	int light;
public:
	GAME();
	~GAME();
	void drawGame();
	void resetGame();
	void Win();
	void Dead();
	void startGame();
	void exitGame();
	bool loadGame();
	void saveGame();
	void pauseGame();
	void setting();
	void updatePosHuman();
	void updatePosObstacle();
	bool isExit() { return IS_RUNNING == false; }
};

#endif // CGAME_H