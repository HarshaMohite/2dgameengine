#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/**
 * This class handles the basic launch and structure of the game.
*/
class Game {
    private:
        /**
         * If true, the game is running.
        */    
        bool isRunning;

        /**
         * Pointer to the running SDL window.
        */
        SDL_Window *window;

        /**
         * Pointer to the created SDL renderer.
        */
        SDL_Renderer *renderer;

        /**
         * The number of ticks elapsed since SDL_Init().
         * Retrieved from SDL_GetTicks() and used to make DeltaTime calculations
         * baesd on last frame's tick count.
        */
        int ticksLastFrame = 0;

    public:
        /**
         * Called to bring up the world for play.
        */
        Game();

        /**
         * Called when this class is closed. Handles closing out the game.
        */
        ~Game();

        /**
         * @return bool isRunning, which states if the game is currently active.
        */
        bool IsRunning() const;

        /**
         * Initializes SDL, the game window, and any necessary components.
         * @param width Window width.
         * @param height Window height.
        */
        void Initialize(int width, int height);

        /**
         * Processes input every frame from the input buffer.
        */
        void ProcessInput();

        /**
         * Updates gameplay logic every frame.
        */
        void Update();

        /**
         * Handles rendering every frame.
         * 
         * Renders on the back buffer and then swaps with front buffer once rendered.
        */
        void Render();

        /**
         * Handles exiting the game.
        */
        void Destroy();
};