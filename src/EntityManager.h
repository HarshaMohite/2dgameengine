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
        void Update(float deltatime);
        void Render();
        bool HasNoEntities();
        Entity& AddEntity(std::string entityName);
        std::vector<Entity*> GetEntities() const;
        unsigned int GetEntityCount();
};
