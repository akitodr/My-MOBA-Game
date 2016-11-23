#ifndef animation_h
#define animation_h

#include "ofMain.h"
#include <vector>
#include <string>


class Animation {
private:
	vector <ofImage*> images;
	int frame;
	bool repeat;
	float frameTime;
	float time;

public:
	Animation();
	void update(float secs);
	void draw(const ofVec2f& position);
	void addFrame(string image);
	void reset();
	void setFrameTime(float secs);
	void setFrame(int num);
	ofVec2f getFrameSize() const;
};

#endif
