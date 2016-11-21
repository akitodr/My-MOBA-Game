//
//  GameManager.hpp
//  colors
//
//  Created by ViniGodoy on 05/11/16.
//
//

#ifndef GameManager_hpp
#define GameManager_hpp

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

#endif /* GameManager_hpp */
