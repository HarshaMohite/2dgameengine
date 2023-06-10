#pragma once

class Entity;

class Component {
    public:
        /**
         * Reference to owning Component.
        */
        Entity* owner;

        /**
         * Destructor for closing component.
         * 
         * Override by child classes.
        */
        virtual ~Component() {}

        /**
         * Initializes game logic when component is spawned.
         * 
         * Override by child classes.
        */
        virtual void Initialize() {}

        /**
         * Function for updating game logic. Receives deltaTime.
         * 
         * Override by child classes.
        */
        virtual void Update(float deltaTime) {}

        /**
         * Function for handling rendering.
         * 
         * Override by child classes.
        */
        virtual void Render() {}
};