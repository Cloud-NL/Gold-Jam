#include "functions.h"
#include "raylib.h"
#include "Player.h"
#include "GameOver.h"
#include "Gold.h"
#include <iostream>

#define MAX_GOLD 10

Player player;
Gold gold[MAX_GOLD];
GameOver game_over;

void game_update(void) // Gelooped door main
{
    game_draw();
    game_input();
    game_collision();
}

void game_draw(void)
{
    BeginDrawing();
        ClearBackground(YELLOW);
        game_over.Update();
        if(!game_over.gameover)
        {
        player.Draw();
        DrawText(TextFormat("Gold Dodged: %i", gold->dodged), 10, GetScreenHeight() / 100, 20, BLACK);
            if(gold->active)
            {
                gold->Update();
                for(int i = 0; i < MAX_GOLD; i++)
                {
                    gold->Draw(gold[i].x, gold[i].y);
                }

                if(gold->dodged > 50)
                {
                    gold->speed_y = 8;
                }
                if(gold->dodged > 100)
                {
                    gold->speed_y = 16;
                }
                if(gold->speed_y > 200)
                {
                    gold->speed_y = 24;
                }
            }
        } else {
            game_over.Game_Over();
        }

    EndDrawing();
}

void game_collision(void)
{
    for(int i = 0; i < MAX_GOLD; i++)
    {
        if(CheckCollisionCircleRec(Vector2{player.x, player.y}, 10, Rectangle{gold[i].x, gold[i].y, 30, 30}) &! game_over.gameover)
        {
            game_over.gameover = true;
            gold[i].x = GetRandomValue(0, 750);
            gold[i].y = GetRandomValue(0, 600);
            gold->dodged = 0;
        }
    }
}

void game_initialize(void)
{

    gold->texture = LoadTexture("../textures/gold.png");
    gold->dodged = 0;
    gold->speed_y = 4;

    player.x = GetScreenWidth() / 2 - 25;
    player.y = GetScreenHeight() - 50;
    player.texture = LoadTexture("../textures/player.png");

    game_over.gameover = false;
    game_over.x = GetScreenWidth() / 2;
    game_over.y = GetScreenHeight() / 2;

    for(int i = 0; i < MAX_GOLD; i++)
    {
        gold[i].x = GetRandomValue(0, 750);
        gold[i].y = GetRandomValue(0, 600);
        gold[i].active = true;
    }
}

void game_input(void)
{
    if(IsKeyDown(KEY_LEFT) &! game_over.gameover)
    {
        player.x -= 5;
    } else if(IsKeyDown(KEY_RIGHT) &! game_over.gameover)
    {
        player.x += 5;
    }
}