#include "animation.h"

Animation::Animation() {
	frame = 0;
	repeat = true;
	time = 0;
}

void Animation::update(float secs) {
    time += secs;
    if (time >= frameTime) {
        time = 0;
        if (frame == images.size() - 1) {
            if (repeat) {
                frame = 0;
            }
        }
        else {
            frame = frame + 1;
        }
    }   
}

void Animation::draw(const ofVec2f& position) {
	for (int i = 0; i < images.size(); i++) {
		if(images[frame] != nullptr)
		images[frame]->draw(position);
	}
}

void Animation::addFrame(string image) {
	ofImage* img = new ofImage();
	img->load(image);
	images.push_back(img);
}

void Animation::reset() {
	frame = 0;
	time = 0;
}

void Animation::setFrameTime(float secs) {
	frameTime = secs;
}

ofVec2f Animation::getFrameSize() const {
	return ofVec2f(images[0]->getWidth(), images[0]->getHeight());
}
