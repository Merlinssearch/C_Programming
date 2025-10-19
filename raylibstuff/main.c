#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdbool.h>

typedef struct {
    Vector2 position;
    Vector2 velocity;
    float radius;
    float mass;
    Color color;
    bool isPlayer;
} Ball;

Ball InitBall(Vector2 pos, float radius, Color color, bool isPlayer) {
  Ball ball;
  ball.position = pos;
  ball.velocity = (Vector2){0};
  ball.radius = radius;
  ball.mass = 1.0f;
  ball.color = color;
  ball.isPlayer = isPlayer;
  return ball;
}

void movePlayer(Ball *Player) {
  Player->velocity = (Vector2){2, 2};
  if (IsKeyDown(KEY_W)) {
    Player->position.y -= Player->velocity.y;
  }
  if (IsKeyDown(KEY_A)) {
    Player->position.x -= Player->velocity.x;
  }
  if (IsKeyDown(KEY_S)) {
    Player->position.y += Player->velocity.y;
  }
  if (IsKeyDown(KEY_D)) {
    Player->position.x += Player->velocity.x;
  }
  DrawCircle(Player->position.x, Player->position.y, 50, BLUE);
}

int main() {
  const int screenWidth = 1280;
  const int screenHeight = 980;
  const int y_Mid = screenHeight / 2;
  const int x_Mid = screenWidth / 2;
  InitWindow(screenWidth, screenHeight, "raylib");
  SetTargetFPS(60);
  Ball player = InitBall((Vector2){640, 480}, 20.0f, BLUE, true);
  while (!WindowShouldClose()) {
    // Refresh
    BeginDrawing();
    ClearBackground(WHITE);
    // MAIN STUFF
    DrawLine(0, y_Mid, screenWidth, y_Mid, BLACK);
    DrawLine(x_Mid, 0, x_Mid, screenHeight, BLACK);
    movePlayer(&player);
    // END
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
