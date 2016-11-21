//
//  GameManager.cpp
//  colors
//
//  Created by ViniGodoy on 05/11/16.
//
//

#include "GameManager.h"

GameManager::GameManager() {
}

void GameManager::clear() {
    for (GameObject* object : objects) {
        delete  object;
    }
    objects.clear();
}

void GameManager::add(GameObject* object)
{
    object->init();
    objects.push_back(object);
}

void GameManager::update(float secs, const ofVec2f& camera)
{
    std::vector<GameObject*> alive;
    std::vector<GameObject*> toDelete;
    
    std::swap(toDelete, dead);
    
    //Para cada objeto object em objects
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->update(secs, camera);
        if (!objects[i]->isAlive()) {
            dead.push_back(objects[i]);
        } else {
            alive.push_back(objects[i]);
        }
    }
    
    for (int i = 0; i < objects.size()-1; i++) {
        for (int j = i+1; j < objects.size(); j++) {
            if (objects[i]->bounds().intersects(objects[j]->bounds())) {
                objects[i]->collidedWith(objects[j]);
                objects[j]->collidedWith(objects[i]);
            }
        }
    }
    
    for (GameObject* object : toDelete) {
        delete object;
    }
    
    std::swap(alive, objects);
}

void GameManager::draw(const ofVec2f& camera)
{
    for (GameObject* object : objects) {
        object->draw(camera);
    }
}

GameManager& GameManager::instance() {
    static GameManager manager;
    return manager;
}

GameManager::~GameManager()
{
    clear();
}
