#include "raylib.h"
#include <cstddef>

class Window{
  public:    
    Window(size_t screenWidth, size_t screenHeight, const char *screenTitle) 
      { InitWindow(screenWidth, screenHeight, screenTitle); } 
    ~Window() { CloseWindow(); }

    Window(const Window&) = delete;
};

void cameraInit(Camera3D *camera){
  camera->position = Vector3{ 0.0f, 10.0f, 10.0f };
  camera->target = Vector3{ 0.0f, 0.0f, 0.0f };
  camera->up = Vector3{ 0.0f, 1.0f, 0.0f };
  camera->fovy = 45.0f;
  camera->projection = CAMERA_PERSPECTIVE;  
}

int main(void){
  Window window(640, 480, "TEST");
  Window copy = window;
  Camera3D camera = {};

  cameraInit(&camera);
  SetTargetFPS(144);

  Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

  while (!WindowShouldClose()){
    UpdateCamera(&camera, CAMERA_FREE);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(camera);

    // objects
    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
    DrawGrid(10, 1.0f);

    EndMode3D();

    DrawFPS(10, 10);
    
    EndDrawing();
  }

  return 0;
}