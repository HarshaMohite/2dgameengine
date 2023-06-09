#include <iostream>
#include "./Constants.h"
#include "./Game.h"
#include "../lib/glm/glm.hpp"

/**
 * This class handles the basic launch and structure of the game.
*/

Game::Game() {
    this->isRunning = false;
}

Game::~Game() {

}

bool Game::IsRunning() const {
    return this->isRunning;
}

glm::vec2 projectilePos(0.0f, 0.0f);
glm::vec2 projectileVel(20.0f, 20.0f);

void Game::Initialize(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        std::cerr << "Error initializing SDL." << std::endl; 
        return; 
    }
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) { 
        std::cerr << "Error creating SDL window." << std::endl; 
        return; 
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return;
    }

    isRunning = true;
    return;
}

void Game::ProcessInput() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                isRunning = false;
            }
        default:
            break;
    }
}

void Game::Update() {
    /** NOTE: This is a less sophisticated way of doing a fixed timestep. This keeps the 
             CPU thread going.
    */
    // Wait until FRAME_TARGET_TIME (16.6ms for 60fps) has elapsed since last frame
    //while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TARGET_TIME));


    /**
     * NOTE: This method of fixing the timestep can be significantly improved.
     * Currently, SDL_Delay is limited by the OS scheduler's resolution.
     * @todo Ideally, we don't cap the framerate but fix the physics timestep and interpolate rendering.
     * Read more here: https://gafferongames.com/post/fix_your_timestep/
    */
    // Amount of time to wait until reaching the target frametime, if the current frame finishes faster than the target
    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);
    
    // Call delay if we are too early for processing the next frame
    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
        SDL_Delay(timeToWait);
    }


    // Delta time -- difference in ticks from last frame converted to seconds
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    /**
     * clamp deltaTime to a maximum value so if the game is slow or paused for an 
     * extended period of time, we just slow down the game (relatively) instead of
     * allowing deltaTime to take on a huge value
    */
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    // Set the ticks for the current frame to be used in next frame's DeltaTime calculation
    ticksLastFrame = SDL_GetTicks();

    projectilePos = glm::vec2(
        projectilePos.x + projectileVel.x * deltaTime,
        projectilePos.y + projectileVel.y * deltaTime
    );
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255); // background color
    SDL_RenderClear(renderer);

    SDL_Rect projectile {
        static_cast<int>(projectilePos.x),
        static_cast<int>(projectilePos.y),
        10,
        10
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // rectangle color
    SDL_RenderFillRect(renderer, &projectile);

    SDL_RenderPresent(renderer); // Swap back buffer with front buffer
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}