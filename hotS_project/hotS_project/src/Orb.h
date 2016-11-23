//
//  Orb.h
//  hots
//
//  Created by BEPID on 11/21/16.
//
//

#ifndef Orb_h
#define Orb_h

#include "Skill.h"

class Orb : public Skill{
private:
    ofVec2f initialPos;
	int demage;
	int increase;
	bool alive;
public:
    Orb(const ofVec2f& pos, const ofVec2f direction);
    void init();
    bool isAlive() const;
    void update(float secs, const ofVec2f& camera);
    void collidedWith(GameObject* other);
	int getDemage() const;
};


#endif /* Orb_h */
