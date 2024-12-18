#include "raylib.h"


#define GRAVITY 9

struct protagonist
{
	int position;
	bool canJump;
}protagonist;

int main()
{
	const int screenWidth = 800;
    const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "JUMPYO!!!");

	int protDimX = 50;
	int protDimY = protDimX;

	int protPosX = 400;
	int protPosY = screenHeight - protDimX;


	Rectangle prot = { protPosX, protPosY, 
							  protDimX ,protDimY};

	
	int groundDim = 40;

	Rectangle ground = {0, screenHeight, screenWidth + groundDim, groundDim };

	Rectangle pole = {protPosX - 20, screenHeight - 20, 20, 40 };

    Camera2D camera = { 0 };
    camera.target = (Vector2){ prot.x + 20.0f, prot.y + 20.0f };
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

	
	while(!WindowShouldClose())
	{
		protagonist.canJump = true;
		// Fai movimento in aria
        if (IsKeyDown(KEY_RIGHT)) prot.x += 5;
        else if (IsKeyDown(KEY_LEFT)) prot.x -= 5;
        else if(protagonist.canJump == true)
        {	
        	
         	if((IsKeyDown(KEY_SPACE) && CheckCollisionRecs(ground, prot))) prot.y -= 7;
			if(IsKeyUp(KEY_SPACE) && !CheckCollisionRecs(ground, prot)) prot.y += GRAVITY;

			protagonist.canJump = false;
        }	

        // Camera target follows player
        camera.target = (Vector2){ prot.x + 20, prot.y + 20 };


		BeginDrawing();
			ClearBackground(RAYWHITE);

			BeginMode2D(camera);
			
				DrawRectangleRec(prot, RED);

				DrawRectangleRec(ground, BLUE);

				DrawRectangleRec(pole, GREEN);
	
			EndMode2D();

		SetExitKey(KEY_Q);

		EndDrawing();		
	}

	CloseWindow();
}
