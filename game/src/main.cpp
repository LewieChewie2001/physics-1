// This project uses the Raylib framework to handle graphics, input 
// documentations here!
//https://www.raylib.com/examples.html

#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "game.h"

const unsigned int TARGET_FPS = 50;
float time = 0;
float dt;
float x = 500;
float y = 500;
float frequency = 1.0f;
float amplitude = 70;


void update()
{
    dt = 1.0 / TARGET_FPS;
    time += dt;

    x = x + (-sin(time * frequency)) * frequency * amplitude * dt;
    y = y + (cos(time * frequency)) * frequency * amplitude * dt;
}

void draw()
{
    BeginDrawing();
        
        ClearBackground(WHITE);
        DrawText("Physics Labs 1: Conor D'Arcy 101446834", 10, 40, 20, LIGHTGRAY);
        GuiSliderBar(Rectangle{ 80, (float)GetScreenHeight() - 10, 1000, 10}, "Time", TextFormat("%.2f", time), &time, 0, 240);
        DrawText(TextFormat ("FPS: %i, TIME: %.2f", TARGET_FPS, time), GetScreenWidth() - 250, 40, 20, LIGHTGRAY);


        DrawCircle(x, y, 60, RED);
        DrawCircle(GetScreenWidth() / 2 + cos(time * frequency) * amplitude, GetScreenHeight() / 2 + sin(time * frequency) * amplitude, 60, GREEN);

    EndDrawing();
}

int main()
{
    InitWindow(InitialWidth, InitialHeight, "Physics Labs 1: Conor D'Arcy 101446834");
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose())
    {
        update();
        draw();
    }

    CloseWindow();
    return 0;
}
