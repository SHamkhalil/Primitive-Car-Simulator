#include "raylib.h"
#include "vec3.hpp"

class Window{
  public:    
    Window(size_t screenWidth, size_t screenHight, const char *screenTitle) 
      : screenWidth(640), screenHight(480), screenTitle("Screen")
      { InitWindow(screenWidth, screenHight, screenTitle); }
    ~Window() { CloseWindow(); }
    
    void mainLoop(){
      cameraInit(&camera);
      SetTargetFPS(60);

      Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

      while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);

        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
        DrawGrid(10, 1.0f);
        UpdateCamera(&camera, CAMERA_ORBITAL);

        DrawFPS(10, 10);
        EndMode3D();
        EndDrawing();
      }
    }

    
  private:
    const size_t screenWidth,
                screenHight;
    const char *screenTitle;
    Camera3D camera = { 0 };

    void cameraInit(Camera3D *camera){
      camera->position = Vector3{ 0.0f, 10.0f, 10.0f };
      camera->target = Vector3{ 0.0f, 0.0f, 0.0f };
      camera->up = Vector3{ 0.0f, 1.0f, 0.0f };
      camera->fovy = 45.0f;
      camera->projection = CAMERA_PERSPECTIVE;  
    }
};

int main(void){
  Window window(640, 480, "TEST");

  window.mainLoop();

  return 0;
}