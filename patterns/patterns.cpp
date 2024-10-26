#include <iostream>
#include <raylib.h>
using namespace std;
const int screenWidth = 800;
const int screenHeight = 450;

struct PatternDetials {
	int startDrawWidth = 10;
	int startDrawHeight = 10;
	int space = 25;
	Color color = RAYWHITE;
} pd;

void starBlock(int n) {
		for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			DrawRectangle(pd.startDrawWidth + (j * pd.space), pd.startDrawHeight + (i * pd.space), 20, 20, RED);
		}
	}
}
void rightStar(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			DrawRectangle(pd.startDrawWidth + (j * pd.space), pd.startDrawHeight + (i * pd.space), 20, 20, RED);
		}
	}
}
void numberRightStar(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j;
		}
		cout << endl;
	}
}
void numberRightStar2(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
}
void numberReverseRightStar(int n)
{
	for (int i = 0; i < n; i++)
	{
		int toPrint = 1;
		for (int j = n; j > i; j--)
		{
			cout << toPrint;
			toPrint++;
		}
		cout << endl;
	}
}

void reverseRightStar(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j > i; j--)
		{
			DrawRectangle(pd.startDrawWidth + (j * pd.space), pd.startDrawHeight + (i * pd.space), 20, 20, RED);
		}
	}
}
void pyramid(int n) {
	int startDrawWidth = 200;
	int startDrawHeight = 10;
	int space = 25;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 2 * i + 1; j++) {
			DrawRectangle(startDrawWidth + ((n - i - 1) * space) + (j * space), startDrawHeight + (i * space), 20, 20, RED);
		}
	}
}
void reversePyramid(int n) {
	int startDrawWidth = 200;
	int startDrawHeight = 10;
	int space = 25;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - (2 * i + 1); j++) {
			DrawRectangle(startDrawWidth + (i * space) + (j * space),startDrawHeight + (i * space),20, 20, RED);
		}
	}
}

enum PatternType {
	NONE,
	STAR_BLOCK,
	RIGHT_STAR,
	REVERSE_RIGHT_STAR,
	PYRAMID,
	REVERSE_PYRAMID
};

int main() {
	InitWindow(screenWidth, screenHeight, "Patterns");
	SetTargetFPS(60);

	PatternType currentPattern = NONE;
	Rectangle buttons[5] = {
		{50, 50, 200, 40},   
		{50, 100, 200, 40},  
		{50, 150, 200, 40}, 
		{50, 200, 200, 40},  
		{50, 250, 200, 40}   
	};

	const char* buttonTexts[5] = {
		"Star Block",
		"Right Star",
		"Reverse Right Star",
		"Pyramid",
		"Reverse Pyramid"
	};

	while (!WindowShouldClose()) {
		Vector2 mousePoint = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			for (int i = 0; i < 5; i++) {
				if (CheckCollisionPointRec(mousePoint, buttons[i])) {
					currentPattern = (PatternType)(i + 1);
					pd.startDrawWidth = 300; 
					pd.startDrawHeight = 50;
				}
			}
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		for (int i = 0; i < 5; i++) {
			DrawRectangleRec(buttons[i], LIGHTGRAY);
			DrawText(buttonTexts[i], buttons[i].x + 10, buttons[i].y + 10, 20, BLACK);

			if (CheckCollisionPointRec(mousePoint, buttons[i])) {
				DrawRectangleLinesEx(buttons[i], 2, RED);
			}
		}

		switch (currentPattern) {
		case STAR_BLOCK:
			starBlock(5);
			break;
		case RIGHT_STAR:
			rightStar(5);
			break;
		case REVERSE_RIGHT_STAR:
			reverseRightStar(5);
			break;
		case PYRAMID:
			pyramid(5);
			break;
		case REVERSE_PYRAMID:
			reversePyramid(5);
			break;
		default:
			DrawText("Select a pattern", 300, 200, 30, DARKGRAY);
			break;
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
