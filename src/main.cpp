#include <raylib.h>
#include <iostream>
using namespace std;

int playerScore = 0;
int cpuScore = 0;

Color Green = Color{38, 185, 154, 255};
Color DarkGreen = Color{20, 160, 133, 255};
Color LightGreen = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

class Ball
{
public:
    float x, y;
    int speedX, speedY;
    int radius;

    void Draw()
    {
        DrawCircle(x, y, radius, Yellow);
    }

    void Update()
    {
        x += speedX;
        y += speedY;

        if (y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speedY *= -1;
        }
        if (x + radius >= GetScreenWidth()) // Cpu wins
        {
            cpuScore++;
            ResetBall();
        }
        if (x - radius <= 0)
        {
            playerScore++;
            ResetBall();
        }
    }
    void ResetBall()
    {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        int speed_choices[2] = {-1, 1};
        speedX *= speed_choices[GetRandomValue(0, 1)];
        speedY *= speed_choices[GetRandomValue(0, 1)];
    }
};

class Puddle
{
protected:
    void LimitMovement()
    {
        if (y <= 0)
        {
            y = 0;
        }
        if (y >= GetScreenHeight() - height)
        {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x, y;
    float width, height;
    int speed;
    void Draw()
    {
        DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
    }

    void Update()
    {
        if (IsKeyDown(KEY_UP))
        {
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            y = y + speed;
        }
        LimitMovement();
    }
    bool CheckCollision(Ball ball)
    {
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x, y, width, height}))
        {
            return true;
        }
        return false;
    }
};

class CpuPaddle : public Puddle
{
public:
    void Update(Ball ball)
    {
        if (y + height / 2 > ball.y)
        {
            y -= speed;
        }
        if (y + height / 2 < ball.y)
        {
            y += speed;
        }
        LimitMovement();
    }
};

Ball ball;
Puddle player;
CpuPaddle cpuPaddle;

int main()
{
    cout << "stargin the game" << endl;
    const int screenWidth = 1280;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "My pong game");

    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedX = 7;
    ball.speedY = 7;

    cpuPaddle.width = 25;
    cpuPaddle.height = 120;
    cpuPaddle.x = 10;
    cpuPaddle.y = screenHeight / 2 - cpuPaddle.height / 2;
    cpuPaddle.speed = 6;

    player.width = 25;
    player.height = 120;
    player.x = screenWidth - player.width - 10;
    player.y = screenHeight / 2 - player.height / 2;
    player.speed = 6;

    while (WindowShouldClose() == false)
    {

        // Updating
        ball.Update();
        player.Update();
        cpuPaddle.Update(ball);

        // check for collisions
        if (cpuPaddle.CheckCollision(ball) || player.CheckCollision(ball))
        {
            ball.speedX *= -1;
        }

        // Drawing
        BeginDrawing();
        ClearBackground(DarkGreen);
        DrawRectangle(screenWidth / 2, 0, screenWidth / 2, screenHeight, Green);
        DrawCircle(screenWidth / 2, screenHeight / 2, 150, LightGreen);
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        ball.Draw();
        player.Draw();
        cpuPaddle.Draw();
        DrawText(TextFormat("%i", cpuScore), screenWidth / 4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", playerScore), 3 * screenWidth / 4 - 20, 20, 80, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}