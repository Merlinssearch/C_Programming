#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  // Manage Window Setting
  int screenWidth = 1000;
  int screenHeight = 500;
  InitWindow(screenWidth, screenHeight, "Music Visualizer");
  SetTargetFPS(60);

  // Manage Audio Setting
  InitAudioDevice();
  Music music = LoadMusicStream("music.mp3");
  PlayMusicStream(music);
  SetMusicVolume(music, 0.5f);
  // End Audio Setting

  float maxVolume = 160;
  float Volume = 80;
  float SetMusicVolume2 = maxVolume / Volume;
  int musicVolumey = 80;
  bool Updategui = true;

  // Start Window
  while (!WindowShouldClose()) {
    Vector2 mousePos = GetMousePosition();
    UpdateMusicStream(music);

    // Check if mouse is clicked on the volume control bar
    if ((mousePos.x > 20 && mousePos.x < 70) &&
        (mousePos.y > 50 && mousePos.y < 210) &&
        IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      musicVolumey = mousePos.y - 50;
      if (musicVolumey > maxVolume)
        musicVolumey = maxVolume;
      if (musicVolumey < 0)
        musicVolumey = 0;
      SetMusicVolume(music, (float)musicVolumey / maxVolume);
      printf("Volume: %f\n", (float)musicVolumey / maxVolume);
    }

    // Draw background
    BeginDrawing();
    ClearBackground(BLACK);

    // Draw volume control bar (Red for max, Blue for current volume level)
    DrawRectangle(20, 50, 50, maxVolume, RED);
    DrawRectangle(20, 50, 50, musicVolumey, BLUE);

    // Pause/Resume music with spacebar
    if (IsKeyPressed(KEY_SPACE)) {
      if (IsMusicStreamPlaying(music)) {
        PauseMusicStream(music);
      } else {
        ResumeMusicStream(music);
      }
    }

    // Close window on ESC key
    if (IsKeyPressed(KEY_ESCAPE)) {
      CloseWindow();
    }

    EndDrawing();
  }

  // Close audio and window
  UnloadMusicStream(music);
  CloseAudioDevice();
  CloseWindow();

  return 0;
}
