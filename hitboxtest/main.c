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
    int radommass = rand() % 100;
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
// das in ein bool ändern ,Physics extra machen !
void check_collision(balls *ball, int i, int k) {
  float distance = Vector2Distance(ball[i].position, ball[k].position);
  float sum_radius = ball[i].radius + ball[k].radius;
  Vector2 ball_0_direction = Vector2Normalize(ball[i].velocity);
  Vector2 ball_1_direction = Vector2Normalize(ball[k].velocity);

  if (distance <= sum_radius) {
    ball[i].velocity = (Vector2Add(ball_1_direction, ball[i].velocity));
    ball[k].velocity = (Vector2Add(ball_0_direction, ball[k].velocity));
  }
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
  // Vector2 center = {(midscreenWidth), (midscreenHeight)};
  //  Hilfslinien
  Vector2 hilfx = {0, midscreenHeight};
  Vector2 hilfx2 = {screenWidth, midscreenHeight};
  Vector2 hilfy = {midscreenWidth, 0};
  Vector2 hilfy2 = {midscreenWidth, screenWidth};
  /////////////////////////////////////////////////////////
  //             Creating Multiple Balls
  /////////////////////////////////////////////////////////
  int ballscount = 2;
  balls *allballs = createBalls(ballscount);
  /////////////////////////////////////////////////////////
  //                Gameloop
  /////////////////////////////////////////////////////////
  while (!WindowShouldClose()) {
    BeginDrawing();
    // Check and Update
    ClearBackground(RAYWHITE);
    for (int i = 0; i < ballscount; i++) {
      update_balls(&allballs[i], screenWidth, screenHeight);
    }
    check_collision(allballs, 0, 1);

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
