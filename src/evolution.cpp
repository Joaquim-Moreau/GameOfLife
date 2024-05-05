#include "Engine.h"


int Engine::getNumberNeighbour(Vector2i tileID) {
    /*
     * @return int
     *
     * Returns the number of neighbours of the given tile
     * If the tile is on the edge of the window, we consider the non-existing neighbours as dead
     */

    int numberNeighbour = 0;

    // top left
    if (tileID.x > 0 && tileID.y > 0) {
        numberNeighbour += this->tiles[tileID.x - 1][tileID.y - 1];
    }

    // top
    if (tileID.y > 0) {
        numberNeighbour += this->tiles[tileID.x][tileID.y - 1];
    }

    // top right
    if (tileID.x < this->width - 1 && tileID.y > 0) {
        numberNeighbour += this->tiles[tileID.x + 1][tileID.y - 1];
    }

    // right
    if (tileID.x < this->width - 1) {
        numberNeighbour += this->tiles[tileID.x + 1][tileID.y];
    }

    // bottom right
    if (tileID.x < this->width - 1 && tileID.y < this->height - 1) {
        numberNeighbour += this->tiles[tileID.x + 1][tileID.y + 1];
    }

    // bottom
    if (tileID.y < this->height - 1) {
        numberNeighbour += this->tiles[tileID.x][tileID.y + 1];
    }

    // bottom left
    if (tileID.x > 0 && tileID.y < this->height - 1) {
        numberNeighbour += this->tiles[tileID.x - 1][tileID.y + 1];
    }

    // left
    if (tileID.x > 0) {
        numberNeighbour += this->tiles[tileID.x - 1][tileID.y];
    }

    return numberNeighbour;
}

void Engine::birth(Vector2i tileID) {
    /*
     * @return void
     *
     * Give life to a tile
     */
    if (!this->tiles[tileID.x][tileID.y] && this->getNumberNeighbour(tileID) == 3) {
        this->nextTurnTiles[tileID.x][tileID.y] = true;
    }
}

void Engine::death(Vector2i tileID) {
    /*
     * @return void
     *
     * Kill a tile
     */
    if (this->tiles[tileID.x][tileID.y] && this->getNumberNeighbour(tileID) != 2 && this->getNumberNeighbour(tileID) != 3) {
        this->nextTurnTiles[tileID.x][tileID.y] = false;
    }
}
