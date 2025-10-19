#include "raylib.h"
#include <raymath.h>
#include <stdio.h>
#include <stdlib.h>
///////////////////////////////////////////////////////
///                  Data Structs
///////////////////////////////////////////////////////
typedef struct {
    int id;
    Vector2 position;
    Vector2 velocity;
    float radius;
    float mass;
} balls;
///////////////////////////////////////////////////////
typedef struct node {
    int data;
    struct node *next;
} node_t;
// Todo :
// Data struct for nearest neighbor search
// and funktion to store and search them , so maybe 2 ?
// Ball Tree / Binary Tree
// Todo
// Funktion umbauen ?! Kullison nocchmal trennen
void update_balls(balls *ball, int screenWidth, int screenHeight) {
  ball->position.x += ball->velocity.x;
  ball->position.y += ball->velocity.y;
  // Kollision mit rechter und linker Wand
  if (ball->position.x - ball->radius <= 0 ||
      ball->position.x + ball->radius >= screenWidth) {
    ball->velocity.x = -ball->velocity.x;
  }
  // Kollision mit oberer/unterer Wand (Y-Richtung umkehren)
  if (ball->position.y - ball->radius <= 0 ||
      ball->position.y + ball->radius >= screenHeight) {
    ball->velocity.y = -ball->velocity.y;
  }
}

balls *createBalls(int Size) {
  balls *array = (balls *)malloc(sizeof(balls) * Size);
  for (int i = 0; i < Size; i++) {
    int randomy = rand() % 980;
    int randomx = rand() % 1280;
    int radommass = rand() % 10;
    Vector2 velocity = {5, 5};
    Vector2 position = {randomx, randomy};
    array[i].id = i;
    array[i].position = position;
    array[i].velocity = velocity;
    array[i].mass = radommass;
    array[i].radius = radommass * 1.1;
  }
  return array;
}

int main() {
  const int screenWidth = 1280;
  const int screenHeight = 980;
  /////////////////////////////////////////////////////////
  //          Setting Screen and Fps
  /////////////////////////////////////////////////////////
  InitWindow(screenWidth, screenHeight, "Test");
  SetTargetFPS(60);
  /////////////////////////////////////////////////////////
  //         Basics Variables
  //////////////////////////////////////////////////////////

  int midscreenWidth = screenWidth / 2;
  int midscreenHeight = screenHeight / 2;
  Vector2 center = {(midscreenWidth), (midscreenHeight)};
  // Hilfslinien
  Vector2 hilfx = {0, midscreenHeight};
  Vector2 hilfx2 = {screenWidth, midscreenHeight};
  Vector2 hilfy = {midscreenWidth, 0};
  Vector2 hilfy2 = {midscreenWidth, screenWidth};
  /////////////////////////////////////////////////////////
  //             Creating Multiple Balls
  /////////////////////////////////////////////////////////
  int ballscount = 10;
  balls *allballs = createBalls(ballscount);
  /////////////////////////////////////////////////////////
  //                Gameloop
  /////////////////////////////////////////////////////////
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (int i = 0; i < ballscount; i++) {
      update_balls(&allballs[i], screenWidth, screenHeight);
    }

    DrawLineV(hilfx, hilfx2, BLACK);
    DrawLineV(hilfy, hilfy2, BLACK);
    for (int i = 0; i < ballscount; i++) {
      DrawCircleV(allballs[i].position, allballs[i].radius, ORANGE);
    }

    EndDrawing();
  }
  CloseWindow();

  return 0;
}
