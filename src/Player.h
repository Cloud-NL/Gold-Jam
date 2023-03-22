#include "raylib.h"

class Player {
    public:
    float x,y;
    int speed_x, speed_y;
    Texture2D texture;

    void Draw()
    {
        DrawTexturePro(texture, Rectangle{0, 0, 100, 100}, Rectangle{x,y, 100, 100}, Vector2{20, 20}, 0, WHITE);
    }
};