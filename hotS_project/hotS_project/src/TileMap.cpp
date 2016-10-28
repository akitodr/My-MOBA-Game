#include "TileMap.h"

void TileMap::init() {
	position.set(0, 0);
	tiles = new ofImage[255];
	tiles['@'].load("img/grass.png");
}

void TileMap::draw(const ofVec2f& camera) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			ofImage& tile = tiles[map[i][j]];
			if (tile.isAllocated()) {
				tile.draw(position.x + j * tile.getWidth() - camera.x,
						  position.y + i * tile.getHeight() - camera.y);
			}
		}
	}
}

float TileMap::getMapWidth() const {
	return TILE * WIDTH;
}

float TileMap::getMapHeight() const {
	return TILE * HEIGHT;
}

char TileMap::getTileChar(const ofVec2f& position) {
	int width = position.x / TILE;
	int height = position.y / TILE;
	return map[width][height];
}

ofVec2f TileMap::getSpawnPoint() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (map[i][j] == 'L') {
				ofVec2f result;
				result.x = result.x + j* TILE;
				result.y = result.y + i * TILE;
				return result;
			}
		}
	}
}