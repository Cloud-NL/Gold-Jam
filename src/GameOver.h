#include "raylib.h"

class GameOver {
    public:
    float x,y;
    bool gameover;

    void Game_Over()
    {
        if(this->gameover)
        {
            DrawText("Game Over Press [SPACE] to restart.", GetScreenWidth() / 2 - MeasureText("Game Over Press [SPACE] to restart.", 30) / 2, GetScreenHeight() / 2, 30, BLACK);
        }
    }

    void Update()
    {
        if(IsKeyPressed(KEY_SPACE))
        {
            this->gameover = false;
        }
    }
};