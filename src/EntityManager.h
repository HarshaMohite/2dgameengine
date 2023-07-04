#pragma once

#include "./Entity.h"
#include "./Component.h"
#include <vector>

/**
 * Manages all the entities in an active game
*/
class EntityManager {
    private:
        /**
         * List of all entities managed in the active game.
        */
        std::vector<Entity*> entities;
    
    public:
        /**
         * Clears all entities currently registered.
         * Calls Destroy() on all entities registered.
        */
        void ClearData();

        /**
         * Receive update and deltaTime from game loop.
        */
        void Update(float deltaTime);

        /**
         * Handle render step from game loop.
        */
        void Render();

        /**
         * Checks if there are no entities registered.
         * @return True if entities array is size 0 (has no entities).
        */
        bool HasNoEntities();

        /**
         * Instantiates a new entity and places it in the Entity vector.
         * Entities are buckets that receive components, and the EntityManager handles
         * the entire lifecycle for an entity.
         * 
         * @return Reference to the newly created entity.
        */
        Entity& AddEntity(std::string entityName);

        /**
         * Returns the full vector of entity pointers.
         * @warning For debugging use only.
        */
        std::vector<Entity*> GetEntities() const;

        /**
         * @return Number of entities registered.
        */
        unsigned int GetEntityCount();
};
