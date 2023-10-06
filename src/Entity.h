#pragma once

#include <vector>
#include <string>
#include "./Component.h"
#include "./EntityManager.h"

class Component;
class EntityManager;

class Entity {
    private:
        /**
         * Reference to the game instance's EntityManager.
        */
        EntityManager& manager;

        /**
         * If true, this component is active and receives updates.
        */
        bool isActive;

        /**
         * Array of components attached to this entity.
        */
        std::vector<Component*> components;

    public:
        /**
         * Name of this entity.
        */
        std::string name;

        /**
         * Initializer.
         * @param manager Reference to game instance's EntityManager.
        */
        Entity(EntityManager& manager);

        /**
         * @overload
         * @param manager Reference to game instance's EntityManager.
         * @param name Name for this Entity.
        */
        Entity(EntityManager& manager, std::string name);

        /**
         * Receive update with deltaTime every frame.
        */
        void Update(float deltaTime);

        /**
         * Receive render every frame.
        */
        void Render();

        /**
         * Handle deletion.
        */
        void Destroy();

        /**
         * @return True if this entity is active.
        */
        bool IsActive() const;
};