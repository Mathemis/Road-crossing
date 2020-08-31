#include "CGame.h"

GAME::GAME()
{
	num = 3;
	din = new DINOSAUR[num];
	brd = new BIRD[num] ;
	car = new CAR[num];
	trk = new TRUCK[num];
	forc(i, 0, num, 1) {
		din[i].setY(y0 + 2 + i * (GAP + w_SIZE));
		brd[i].setY(y0 + 2 + i * (GAP + w_SIZE) + 7);
		trk[i].setY(y0 + 2 + i * (GAP + w_SIZE) + 11);
		car[i].setY(y0 + 2 + i * (GAP + w_SIZE) + 5);
	}
	IS_RUNNING = true;
	level = 1;
	onSound = true;
	light = 0;
}

GAME::~GAME()
{
	delete[]din;
	delete[]brd;
	delete[]car;
	delete[]trk;
}

void GAME::drawGame()
{
	drawArea();
	ingameMenu();
	hm.Draw();
	Status();
}

void GAME::resetGame()
{
	forc(i, 0, num, 1) {
		din[i].Clear();
		brd[i].Clear();
		trk[i].Clear();
		car[i].Clear();
	}
	forc(i, 0, num, 1) {
		din[i].setY(y0 + 2 + i * (GAP + w_SIZE));
		brd[i].setY(y0 + 2 + i * (GAP + w_SIZE) + 7);
		trk[i].setY(y0 + 2 + i * (GAP + w_SIZE) + 11);
		car[i].setY(y0 + 2 + i * (GAP + w_SIZE) + 5);
	}
	hm.Clear();
	hm.updatePos(x0 + 2 + 5 * (LANE + 1), y0 + 2 + WIDTH / 2 - 7);
	hm.Draw();
	light = 0;
}

void GAME::Win()
{
	PauseThread = true;
	int t = 6;
	if (onSound)
		PlaySound(TEXT("cheer2.wav"), NULL, SND_FILENAME | SND_ASYNC);
	while (t--) {
		textcolor(White);
		gotoxy(HEIGHT - 12, WIDTH + 15);
		cout << "YOU WIN!";
		hm.Draw();
		delay(350);
		hm.Clear();
		textcolor(Yellow);
		gotoxy(HEIGHT - 12, WIDTH + 15);
		cout << "YOU WIN!";
		hm.drawUp();
		delay(350);
		textcolor(White);
	}

	int x = HEIGHT - 9, y = WIDTH + 15;
	textcolor(White);
	gotoxy(x, y);
	printf("Do you want to Replay?");
	string List[2] = { "Yes","No" };
	int color[2] = { Red, White };
	int key = 0;
	int move = -1;
	do {
		gotoxy(x + 2, y + 4);
		textcolor(color[0]);
		cout << List[0];
		gotoxy(x + 2, y + 12);
		textcolor(color[1]);
		cout << List[1];
		textcolor(White);
		do {
			move = _getch();
			switch (move) {
			case LEFT:
				if (key == 1) key--;
				break;
			case RIGHT:
				if (key == 0) key++;
				break;
			}
		} while (move != LEFT && move != RIGHT && move != ENTER);

		color[0] = White;
		color[1] = White;
		color[key] = Red;

	} while (move != ENTER);
	if (key) IS_RUNNING = false;
	else {
		PauseThread = false;
		level = 1;
		resetGame();
	}
}

void GAME::Dead()
{
	if (onSound)
		PlaySound(TEXT("smb_bowserfalls.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Message("YOU ARE DEAD!");
	int t = 6, x = hm.getX(), y = hm.getY() - 1;
	hm.Clear();
	while (t--) {
		textcolor(DarkRed);
		drawSkull(x, y);
		//delay(20);
		textcolor(White);
		drawSkull(x, y);
		delay(20);
		textcolor(White);
		clearSkull(x, y);
		delay(50);
	}
	resetGame();
}

void GAME::startGame()
{
	clearScreen();
	drawGame();
	while (IS_RUNNING) {
		switch (KEY) {
			case PAUSE:
				pauseGame();
				break;
			case SAVE:
				PauseThread = true;
				saveGame();
				PauseThread = false;
				if (isExit() == false) {
					clearScreen();
					drawGame();
				}
				break;
			case LOAD:
				PauseThread = true;
				loadGame();
				resetGame();
				PauseThread = false;
				clearScreen();
				drawGame();
				break;
			case SETTING:
				PauseThread = true;
				setting();
				PauseThread = false;
				clearScreen();
				drawGame();
				break;
			case ESC:
				PauseThread = true;
				exitGame();
				PauseThread = false;
				if (isExit() == false) {
					clearScreen();
					drawGame();
				}
				break;
			default: 
				clearMessage();
				updatePosObstacle();
				drawLevel(level);
				updatePosHuman();
				int lane = hm.LanePos();
				bool isDead = false;
				if (lane == 0) {
					if (level == 4) {
						Win();
					}
					else {
						level++;
						if (onSound)
							PlaySound(TEXT("smb_powerup.wav"), NULL, SND_FILENAME | SND_ASYNC);
						Message("LEVEL UP!");
						delay(2000);
						resetGame();
					}
				}
				else if (lane == 1) {
					forc(i, 0, 3, 1) {
						if (hm.isImpact(car + i)) {
							isDead = true;
							break;
						}
					}
					if (isDead) {
						isDead = false;
						Dead();
					}
				}
				else if (lane == 2) {
					forc(i, 0, 3, 1) {
						if (hm.isImpact(brd + i)) {
							isDead = true;
							break;
						}
					}
					if (isDead) {
						isDead = false;
						Dead();
					}
				}
				else if (lane == 3) {
					forc(i, 0, 3, 1) {
						if (hm.isImpact(trk + i)) {
							isDead = true;
							break;
						}
					}
					if (isDead) {
						isDead = false;
						Dead();
					}
				}
				else if (lane == 4) {
					forc(i, 0, 3, 1) {
						if (hm.isImpact(din + i)) {
							isDead = true;
							break;
						}
					}
					if (isDead) {
						isDead = false;
						Dead();
					}
				}
				if (KEY != ESC) KEY = -1;
				delay(120 - (level - 1) * 18);
				break;
	
		}
	}
}

void GAME::exitGame() {
	int x = 20, y = 88;
	clearScreen();
	textcolor(Yellow);
	gotoxy(x, y);
	printf("DO YOU REALLY WANT TO EXIT?");
	string List[2] = { "Yes","No" };
	int color[2] = { Red, White };
	int key = 0;
	int move = -1;
	do {
		gotoxy(x + 2, y + 8);
		textcolor(color[0]);
		cout << List[0];
		gotoxy(x + 2, y + 15);
		textcolor(color[1]);
		cout << List[1];
		textcolor(White);
		do {
			move = _getch();
			switch (move) {
			case LEFT:
				if (key == 1) key--;
				break;
			case RIGHT:
				if (key == 0) key++;
				break;
			}
		} while (move != LEFT && move != RIGHT && move != ENTER);

		color[0] = White;
		color[1] = White;
		color[key] = Red;

	} while (move != ENTER);
	if (key == 0) IS_RUNNING = false;
}

bool GAME::loadGame()
{
	clearScreen();
	gotoxy(14, 61);
	textcolor(Yellow);
	printf("Input File name:");
	textcolor(White);
	//
	string List[3] = { "F", "BACK","LOAD" };
	int color[3] = { Red, White, White };
	int key = 0, move = -1;
	string s = "";
	do {
		textcolor(color[0]);
		drawFrame(16, 60);
		gotoxy(20, 61);
		textcolor(color[1]);
		cout << List[1];
		gotoxy(20, 126);
		textcolor(color[2]);
		cout << List[2];
		textcolor(White);
		bool flag = false;

		do {
			if (flag == false) move = _getch();
			switch (move) {
			case LEFT:
				if (key == 2) key--;
				break;
			case RIGHT:
				if (key == 1) key++;
				break;
			case UP:
				if (key > 0) key = 0;
				break;
			case DOWN:
				if (key == 0) key++;
				break;
			case ENTER:
				if (key == 0) {
					gotoxy(17, 61);
					cin >> s;
					key = 1;
					flag = true;
					move = DOWN;
				}
				break;
			}
		} while (move != LEFT && move != RIGHT && move != UP && move != DOWN && move != ENTER);

		color[0] = White;
		color[1] = White;
		color[2] = White;
		color[key] = Red;

	} while (move != ENTER);
	bool res = true;
	if (key == 2) {
		fstream f(s, ios::in | ios::binary);
		gotoxy(23, 80);
		if (f.fail()) {
			textcolor(White);
			printf("LOAD GAME ");
			textcolor(Yellow);
			printf("UNSUCCESSFULL!");
			res = false;
		}
		else {
			f.read(reinterpret_cast<char *>(&level), sizeof(level));
			f.read(reinterpret_cast<char *>(&onSound), sizeof(onSound));
			textcolor(White);
			printf("LOAD GAME ");
			textcolor(Yellow);
			printf("SUCCESSFULL!");
		}
		f.close();
		gotoxy(25, 80);
		textcolor(Grey);
		printf("Press Enter to continue...");
		textcolor(White);
		_getch();
	}
	else if (key == 1) res = false;
	return res;
}

void GAME::saveGame()
{
	clearScreen();
	gotoxy(14, 61);
	textcolor(Yellow);
	printf("Input File name:");
	textcolor(White);
	//
	string List[3] = { "F", "BACK","SAVE" };
	int color[3] = { Red, White, White };
	int key = 0, move = -1;
	string s = "";
	do {
		textcolor(color[0]);
		drawFrame(16, 60);
		gotoxy(20, 61);
		textcolor(color[1]);
		cout << List[1];
		gotoxy(20, 126);
		textcolor(color[2]);
		cout << List[2];
		textcolor(White);
		bool flag = false;

		do {
			if (flag == false) move = _getch();
			switch (move) {
			case LEFT:
				if (key == 2) key--;
				break;
			case RIGHT:
				if (key == 1) key++;
				break;
			case UP:
				if (key > 0) key = 0;
				break;
			case DOWN:
				if (key == 0) key++;
				break;
			case ENTER:
				if (key == 0) {
					gotoxy(17, 61);
					cin >> s;
					key = 1;
					flag = true;
					move = DOWN;
				}
				break;
			}
		} while (move != LEFT && move != RIGHT && move != UP && move != DOWN && move != ENTER);

		color[0] = White;
		color[1] = White;
		color[2] = White;
		color[key] = Red;

	} while (move != ENTER);
	if (key == 2) {
		fstream f(s, ios::out | ios::binary);
		f.write(reinterpret_cast<char *>(&level), sizeof(level));
		f.write(reinterpret_cast<char *>(&onSound), sizeof(onSound));
		f.close();
		//
		int x = 16, y = 80;
		clearScreen();
		gotoxy(x - 2, y);
		printf("SAVE GAME SUCCESSFULL!");
		textcolor(Yellow);
		gotoxy(x, y);
		printf("DO YOU WANT TO CONTINUE PLAYING?");
		string List[2] = { "Yes","No" };
		int color[2] = { Red, White };
		int key = 0;
		int move = -1;
		do {
			gotoxy(x + 2, y + 8);
			textcolor(color[0]);
			cout << List[0];
			gotoxy(x + 2, y + 15);
			textcolor(color[1]);
			cout << List[1];
			textcolor(White);
			do {
				move = _getch();
				switch (move) {
				case LEFT:
					if (key == 1) key--;
					break;
				case RIGHT:
					if (key == 0) key++;
					break;
				}
			} while (move != LEFT && move != RIGHT && move != ENTER);

			color[0] = White;
			color[1] = White;
			color[key] = Red;

		} while (move != ENTER);
		if (key == 1) IS_RUNNING = false;
	}
}

void GAME::pauseGame()
{
	Message("GAME PAUSED");
}

void GAME::setting()
{
	int x = 20, y = 90;
	clearScreen();
	string List[3] = { "SOUND","LEVEL", "Back" };
	int color[3] = { DarkCyan, White, White };
	bool back = false;
	while (back == false) {
		int key = 0;
		int move = -1;
		clearScreen();
		forc(i, 0, 3, 1) color[i] = White;
		color[key] = DarkCyan;
		do {
			forc(i, 0, 3, 1) {
				gotoxy(x + 2 * i, y);
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
					if (key < 2) key++;
					break;
				}
			} while (move != UP && move != DOWN && move != ENTER);

			forc(i, 0, 3, 1) color[i] = White;
			color[key] = DarkCyan;

		} while (move != ENTER);
		if (key == 0) Sound(onSound);
		else if (key == 1) Level(level);
		else back = true;
	}
}

void GAME::updatePosHuman()
{
	switch (KEY) {
	case UP:
		if (onSound)
			PlaySound(TEXT("smb_fireball.wav"), NULL, SND_FILENAME | SND_ASYNC);
		hm.Up();
		break;
	case DOWN:
		if (onSound)
			PlaySound(TEXT("smb_fireball.wav"), NULL, SND_FILENAME | SND_ASYNC);
		hm.Down();
		break;
	case LEFT:
		if (onSound)
			PlaySound(TEXT("smb_fireball.wav"), NULL, SND_FILENAME | SND_ASYNC);
		hm.Left();
		break;
	case RIGHT:
		if (onSound)
			PlaySound(TEXT("smb_fireball.wav"), NULL, SND_FILENAME | SND_ASYNC);
		hm.Right();
		break;
	}
}
void GAME::updatePosObstacle()
{
	light = (light + 1) % 501; 
	int lc1 = Green, lc2 = Green;
	forc(i, 0, num, 1) {
		din[i].Move(level);
		if ((light > 100 && light < 150) || (light > 350 && light < 400)) {
			trk[i].Move(0);
			lc2 = DarkRed;
		}
		else trk[i].Move(level);
		if ((light > 50 && light < 100) || (light > 300 && light < 350)) {
			car[i].Move(0);
			lc1 = DarkRed;
		}
		else car[i].Move(level);
		brd[i].Move(level);
	}
	drawLight(x0 + 1 + (LANE + 1), y0 + 1, lc1);
	drawLight(x0 + 1 + 3 * (LANE + 1), y0 + 1, lc2);
}