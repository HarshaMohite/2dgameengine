#include "./Constants.h"
#include "./Game.h"

/**
 * This class handles the basic startup of the game window and the initialization of the gameplay loop.
*/

int main(int argc, char *args[]) {
    Game game;

    game.Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    // This represents the game process while it's running.
    // e.g. the Game Loop
    while (game.IsRunning()) {
        game.ProcessInput();
        game.Update();
        game.Render();
    }

    game.Destroy();

    return 0;
}