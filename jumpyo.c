#include "raylib.h"

int main()
{
	const int screenWidth = 600;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "JUMPYO!!!");

	SetTargetFPS(60);

	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(GRAY);

			if(IsKeyDown(KEY_SPACE))
			{	
				ClearBackground(RED);
			}

			DrawFPS(0, 0);
		EndDrawing();
	}

	CloseWindow();
}
