#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

// TODO : UpdateMusicStream() to be set (Wahab or Tooba ne is function ko set karna hai warna game me music nhi chalega)
// Function yu likhna hai      UpdateMusicStream(music);      music parameter is in PlayState.h

int main()
{
    Game::getInstance()->init();

    while (WindowShouldClose() == false)
    {
        // Update
        Game::getInstance()->update();

        Game::getInstance()->render();
        
    }

    return 0;
}