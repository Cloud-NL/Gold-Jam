#include "raylib.h"

class Gold {
    public:
    float x,y;
    int speed_x, speed_y;
    bool active;
    Texture2D texture;
    int dodged;

    void Draw(float x, float y)
    {
        if(active)
        {
            DrawTexturePro(texture, Rectangle{0, 0, 50, 50}, Rectangle{x,y, 50, 50}, Vector2{20, 20}, 0, WHITE);
        }
    }

    void Update()
    {
        for(int i=0; i < 10; i++)
        {
            this[i].y += speed_y;
            if(this[i].y > 750)
            {
                this[i].y = 0;
                this[i].x = GetRandomValue(0, 800);
                this->dodged++;
            }
        }
    }
};