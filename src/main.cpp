#include "raylib.h"
#include "functions.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    game_initialize();
    SetTargetFPS(60);
    while (!WindowShouldClose())    
    {
        game_update();
    }
    CloseWindow();

    return 0;
}