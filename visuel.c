#include <raylib.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Jeux du pendu - ESIEA");

    while (!WindowShouldClose()) 
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("some basic shapes available on raylib", 20, 20, 20, DARKGRAY);

            DrawCircle(screenWidth/5, 120, 35, DARKBLUE);

            DrawRectangle(screenWidth/4*2 - 60, 100, 120, 60, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;

}