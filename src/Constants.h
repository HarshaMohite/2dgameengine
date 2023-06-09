#pragma once

/**
 * This header provides engine-wide constants that need to be easily available
 * for editing runtime parameters.
*/

/**
 * Target width of the game window.
*/
const unsigned int WINDOW_WIDTH = 800;

/**
 * Target height of the game window.
*/
const unsigned int WINDOW_HEIGHT = 600;

/**
 * The target frames per second.
*/
const unsigned int FPS = 60;

/**
 * The amount of time in milliseconds that the frame must be rendered within.
*/
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;