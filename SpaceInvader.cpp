/* Game: Space Invader
   Author: Xuechi Li
   Last edit: Feb 19, 2017 */
#include <iostream >
#include <stdio.h>
#include <windows.h>
#include <conio.h>
using namespace std;

const int WIDTH = 10;
const int HEIGHT = 10;
const int MAX_HEALTH = 10;

class Hero {
private:
	int x;
	int health;
public:
	Hero(int nx, int nhealth) { x = nx; health = nhealth; }

	int getX() { return x; }
	void decrementX() { x--; }
	void incrementX() { x++; }
	int getHealth() { return health; }
};

void gotoxy(int x, int y) {
	COORD pos;
	pos.X = 2 * x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawItem(int x, int y, char *str) {
	gotoxy(x, y);
	cout << str;
}

void drawHero(Hero &h) {
	drawItem(h.getX(), HEIGHT, "★");
}

void drawHealth(int h) {
	gotoxy(WIDTH * 2, 9);
	cout << "HEALTH: " << h;
}

void spawnEnemy() {

}

int main() { 

	/* draw background */
	for(int i = 0; i <= WIDTH; i++) {
		for(int j = 0; j <= HEIGHT; j++) {
			drawItem(i, j, "■");
		}
	}
	
	/* draw hero */
	Hero hero(WIDTH / 2, MAX_HEALTH);
	drawHero(hero);
	
	/* draw info */
	drawItem(WIDTH * 2, 5, "Press A to move left");
	drawItem(WIDTH * 2, 6, "Press D to move right");
	drawItem(WIDTH * 2, 7, "Press S to trigger bullet");

	/* draw enemies */
	for(int i = 0; i <= WIDTH; i++) {
		drawItem(i, 0, "●");
	}

	char input;
	int yArray[WIDTH + 1]; // the nearest Y indices of the enemies
	// only the first row showing at the beginning of the game
	for(int i = 0; i <= WIDTH; i++) {
		yArray[i] = 0;
	}

	int currXIndex = hero.getX();
	int currYIndex = yArray[currXIndex];

	int counter = 0;

	int currNumOfEnemyRows = 1;

	while(1) {
		int hHealth = hero.getHealth();
		if(hHealth <= 0) {
			// game over
			return 0;
		}

		if(counter++ % 100 == 50) {
			// spawn another row of enemies
			currNumOfEnemyRows++;
			for(int i = 0; i <= WIDTH; i++) {
				for(int j = currNumOfEnemyRows - 1; j > 0; j--) {
					if(yArray[i] >= j - 1) {
						drawItem(i, j, "●");
					} else {
						drawItem(i, j, "■");
					}
				}
			}

			for(int i = 0; i <= WIDTH; i++) {
				yArray[i]++;
			}
		}

		drawHealth(hHealth);
		input = 'toy';

		if(kbhit()) {
			gotoxy(50, 0);
			input = getche();
		}

		switch(input) {
		case 'a':
			// move left
			if(hero.getX() > 0) {
				drawItem(hero.getX(), HEIGHT, "■");
				hero.decrementX();
				drawHero(hero);
			}
			break;
		case 'd':
			// move right
			if(hero.getX() < WIDTH) {
				drawItem(hero.getX(), HEIGHT, "■");
				hero.incrementX();
				drawHero(hero);
			}
			break;
		case 's':
			// trigger bullet
			currXIndex = hero.getX();
			currYIndex = yArray[currXIndex];
			drawItem(currXIndex, currYIndex, "■");
			yArray[currXIndex]--;
			break;
		default:
			break;
		}
	}
	return 0;
}
