#pragma once

#include "../EntityManager.h"
#include "../../lib/glm/glm.hpp"

/**
 * This component holds transform information about an entity.
*/
class TransformComponent: public Component {
    public:
        /**
         * Position in 2D space.
        */
        glm::vec2 position;

        /**
         * Current travel velocity.
        */
        glm::vec2 velocity;

        /**
         * Width of the entity in pixels.
        */
        int width;

        /**
         * Height of the entity in pixels.
        */
        int height;

        /**
         * Scaling factor for the entity.
        */
        int scale;

        /**
         * Initializer.
         * @param posX Start position Y.
         * @param posY Start position X.
         * @param velX Initial velocity X.
         * @param velY Initial velocity Y.
         * @param w Width.
         * @param h Height.
         * @param s Scale.
        */
        TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s);

        /**
         * Call upon initialization.
        */
        void Initialize() override;

        /**
         * Receive update and deltaTime every frame.
        */
        void Update(float deltaTime) override;

        /**
         * Receive render update every frame.
        */
        void Render() override;


    private:
};