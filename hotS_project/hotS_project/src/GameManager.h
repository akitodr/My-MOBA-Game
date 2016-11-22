#pragma once

#include "ofMain.h"
#include <stdio.h>
#include <vector>
#include "GameObject.h"

#define GAMEMANAGER GameManager::instance()

class GameManager {
    private:
        std::vector<GameObject*> objects;
        std::vector<GameObject*> dead;
        GameManager();
    
    public:
        static GameManager& instance();
        void clear();
        void add(GameObject* object);
        void update(float secs, const ofVec2f& camera);
        void draw(const ofVec2f& camera);
        ~GameManager();
};
