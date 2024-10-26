#include <iostream>
#include <raylib.h>
using namespace std;const int screenWidth = 800;
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

int main()
{


	
	InitWindow(screenWidth, screenHeight, "Patters");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		reversePyramid(5);
		ClearBackground(RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
	
	return 0;
}