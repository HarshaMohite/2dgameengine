#pragma once

#include <vector>
#include <string>

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
        */
        Entity(EntityManager& manager, std::string name);
        void Update(float deltaTime);
        void Render();
        void Destroy();
        bool isActive() const;
};