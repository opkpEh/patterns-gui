#include <iostream>
#include <raylib.h>
using namespace std;

void starBlock(int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void rightStar(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cout << "*";
		}
		cout << endl;
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
void reverseRightStar(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j > i; j--)
		{
			cout << "*";
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
void pyramid(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n-1; j > i; j--)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void reversePyramid(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2*n-(2*i+1); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

int main()
{

	const int screenWidth = 800;
	const int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "Patters");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		EndDrawing();
	}

	CloseWindow();

	int n;
	cout << "Enter the number of rows: ";
	cin >> n;
	reversePyramid(n);
	return 0;
}