#pragma once

#include "ofMain.h"

#define HEIGHT 16
#define WIDTH 16
#define TILE 64

class TileMap {
	private:
		ofImage* tiles;
		ofVec2f position;
		ofVec2f spawnPoint;

		char map[HEIGHT][WIDTH] = {
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@",
			"@@@@@@@@@@@@@@@", };

	public:

		void init();
		void draw(const ofVec2f& camera);
		float getMapWidth() const;
		float getMapHeight() const;
		int getTileWidth() const;
		int getTileHeight() const;
		char getTileChar(const ofVec2f& position);

		ofVec2f getSpawnPoint();
};		
