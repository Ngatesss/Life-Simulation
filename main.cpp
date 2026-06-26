#include <iostream>
#include "raylib.h"
#include "raygui.h"
#include "libs/NEAT/src/NEAT.hpp"
#include <raymath.h> // Nécessaire pour les opérations sur les Vector2

#include "src/Simulation.hpp"


int main() {
    const int screenWidth = 1500;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Life Simulation");

    Camera2D camera = { 0 };
    camera.target = Vector2{ 0.0f, 0.0f };
    camera.offset = Vector2{ screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    Simulation simulation = Simulation(500,500);
    simulation.init();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // move cam
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f / camera.zoom);
            camera.target = Vector2Add(camera.target, delta);
        }

        // zoom
        float wheel = GetMouseWheelMove();
        if (wheel != 0) {
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

            camera.offset = GetMousePosition();
            camera.target = mouseWorldPos;

            const float zoomIncrement = 0.125f;
            camera.zoom += (wheel * zoomIncrement);

            if (camera.zoom < 0.1f) camera.zoom = 0.1f;
        }

        simulation.update();

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);


            // Grid
                DrawRectangle(0, 0, 500, 500, {240, 240, 240, 255});

                for (int i = 0; i <= 500; i += 50) {
                    DrawLine(i, 0, i, 500, LIGHTGRAY);
                    DrawLine(0, i, 500, i, LIGHTGRAY);
                }

                DrawRectangleLines(0, 0, 500, 500, DARKGRAY);
        simulation.draw();


            EndMode2D();

            DrawText("Clic droit pour déplacer la caméra", 10, 10, 20, DARKGRAY);
            DrawText("Molette pour zoomer/dézoomer", 10, 40, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}