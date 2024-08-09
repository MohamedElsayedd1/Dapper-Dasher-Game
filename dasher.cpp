#include <iostream>
#include "include/raylib.h"

struct MultipleNebulas
{
    Rectangle Rec;
    Vector2 Pos;
};

const int sizeOfNebulas = 10;
MultipleNebulas nebulas[sizeOfNebulas];

bool isOnGround(Vector2 Pos, Rectangle Rec, int windowHeight)
{
    return Pos.y >= windowHeight - Rec.height;
}

void updateScarfyAnimation(Rectangle &Rec, int width)
{
    Rec.x += Rec.width; // Move to the next frame in the sprite sheet
    if (Rec.x >= width) // Check if we have reached the end of the sprite sheet
    {
        Rec.x = 0; // Loop back to the first frame
    }
}

void updateNebulasAnimation(MultipleNebulas nebuls[10], int width, int size)
{
    for (int i = 0; i < size; i++)
    {
        nebuls[i].Rec.x += width / 8;
        if (nebulas[i].Rec.x >= width)
        {
            nebulas[i].Rec.x = 0;
        }
    }
}

void intializeNabulas(Texture2D nebula, MultipleNebulas *nebuls, int size, int windowWidth, int windowHeight)
{
    float basePositionX{windowWidth};
    for (int i = 0; i < size; i++)
    {
        nebulas[i].Rec = {0, 0, nebula.width / 8, nebula.height / 8};
        nebulas[i].Pos = {basePositionX, windowHeight - nebula.height / 8};
        basePositionX += 600 + GetRandomValue(0, 400);
    }
}

void drawNebulas(Texture2D neb, MultipleNebulas *nebuls, int size)
{
    for (int i = 0; i < size; i++)
    {
        DrawTextureRec(neb, nebuls[i].Rec, nebuls[i].Pos, WHITE);
    }
}

int main()
{
    const int width = 700;  // Window width
    const int height = 500; // Window height

    // Initialize the window
    InitWindow(width, height, "Dapper Dasher");

    float velocity{0.0f};         // Character's velocity
    const float gravity{800.0f};  // Gravity force
    const float JumpVal{-500.0f}; // Jump force

    // Load textures
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    Texture2D farBuilding = LoadTexture("textures/far-buildings.png");
    Texture2D backBuilding = LoadTexture("textures/back-buildings.png");
    Texture2D foreground = LoadTexture("textures/foreground.png");

    // Initialize character's texture rectangle and position
    Rectangle scarfyRec = {0, 0, scarfy.width / 6, scarfy.height};

    Vector2 scarfyPos = {width / 2 - scarfyRec.width / 2, height - scarfyRec.height};
    float farBuildingX{};
    float backBuildingX{};
    float foregroundX{};

    // Initialize nebulas
    intializeNabulas(nebula, nebulas, sizeOfNebulas, width, height);

    float finishLine{nebulas[sizeOfNebulas - 1].Pos.x};

    float nebVelocity{-450}; // Nebula movement speed

    const float nebUpdateTime{1.0 / 12.0}; // Animation update time
    float runningTime{0};                  // Character animation timer
    float nebRunningTime{0};               // Nebula animation timer

    SetTargetFPS(60); // Set frame rate

    bool isCollision{false};
    bool isGameOver{false};

    while (!WindowShouldClose()) // Game loop
    {
        bool isJump = false;            // Check if the character is in the air
        const float dT{GetFrameTime()}; // Delta time

        BeginDrawing();
        ClearBackground(WHITE);

        if (farBuildingX <= -1 * farBuilding.width * 2.8)
        {
            farBuildingX = 0;
        }
        Vector2 farBuildingPos1 = {farBuildingX, 0};
        DrawTextureEx(farBuilding, farBuildingPos1, 0.0, 2.8, WHITE);
        Vector2 farBuildingPos2 = {farBuildingX + farBuilding.width * 2.8, 0};
        DrawTextureEx(farBuilding, farBuildingPos2, 0.0, 2.8, WHITE);
        farBuildingX -= 20 * dT;

        if (backBuildingX <= -backBuilding.width * 2.7)
        {
            backBuildingX = 0.0;
        }
        Vector2 backBuildingPos1 = {backBuildingX, 0};
        DrawTextureEx(backBuilding, backBuildingPos1, 0.0, 2.7, WHITE);
        Vector2 backBuildingPos2 = {backBuildingX + backBuilding.width * 2.7, 0};
        DrawTextureEx(backBuilding, backBuildingPos2, 0.0, 2.7, WHITE);
        backBuildingX -= 40 * dT;

        if (foregroundX <= -foreground.width * 2.7)
        {
            foregroundX = 0;
        }
        Vector2 foregroundPos1 = {foregroundX, 0};
        DrawTextureEx(foreground, foregroundPos1, 0.0, 2.7, WHITE);
        Vector2 foregroundPos2 = {foregroundX + foreground.width * 2.7, 0};
        DrawTextureEx(foreground, foregroundPos2, 0.0, 2.7, WHITE);
        foregroundX -= 80 * dT;

        if (isGameOver)
        {
            DrawText("Game Over!", width / 2 - 100, height / 2, 40, WHITE);
        }
        else
        {
            // Draw character and nebulas
            DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
            drawNebulas(nebula, nebulas, sizeOfNebulas);
            if (scarfyPos.y < height - scarfyRec.height) // Character is in the air
            {
                velocity += gravity * dT; // Apply gravity
                isJump = true;
            }
            else if (isOnGround(scarfyPos, scarfyRec, height)) // Character is on the ground
            {
                velocity = 0;
                scarfyPos.y = height - scarfyRec.height;
            }

            if (IsKeyPressed(KEY_SPACE) && !isJump) // Jump
            {
                velocity = JumpVal;
            }

            scarfyPos.y += velocity * dT; // Update position

            for (int i = 0; i < sizeOfNebulas; i++)
            {
                nebulas[i].Pos.x += nebVelocity * dT;
            }

            // Update animation timers and frames
            runningTime += dT;
            nebRunningTime += dT;

            if (runningTime >= nebUpdateTime && !isJump)
            {
                runningTime = 0;
                updateScarfyAnimation(scarfyRec, nebula.width);
            }

            if (nebRunningTime >= nebUpdateTime)
            {
                nebRunningTime = 0;
                updateNebulasAnimation(nebulas, nebula.width, sizeOfNebulas);
            }
            finishLine += dT * nebVelocity;
            if (finishLine <= 0 - nebula.width / 2)
            {
                DrawText("You Win !", (width / 2) - 50, height / 2, 60, WHITE);
            }

            // Collision detection
            for (MultipleNebulas &nebula : nebulas)
            {
                float pad{40.0};
                Rectangle nebulaRec{nebula.Pos.x + pad, nebula.Pos.y + pad, nebula.Rec.width - 2 * pad, nebula.Rec.height - 2 * pad};
                Rectangle ScarfyRec{scarfyPos.x, scarfyPos.y, scarfyRec.width, scarfyRec.height};
                if (CheckCollisionRecs(nebulaRec, ScarfyRec))
                {
                    isCollision = true;
                    break; // Exit loop if collision is detected
                }
            }
        }

        // Game over display
        if (isCollision)
        {
            isGameOver = true;
        }
        EndDrawing();
    }

    // Unload textures and close the window
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    UnloadTexture(farBuilding);
    UnloadTexture(backBuilding);
    UnloadTexture(foreground);
    CloseWindow();

    return 0;
}
