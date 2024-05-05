#include "Engine.h"

Vector2i Engine::getTileID(Vector2f mousePos) {
    /*
     * @return Vector2i
     *
     * Returns the ID of the tile where the mouse is currently in
     */
    auto x = static_cast<int> (mousePos.x / this->pixelSize);
    auto y = static_cast<int> (mousePos.y / this->pixelSize);

    return {x , y};
}

Vector2f Engine::getTilePos(Vector2i tileID) {
    /*
     * @return Vector2f
     *
     * Returns the position in pixels of the given tile
     */
    return {static_cast<float> (tileID.x) * this->pixelSize, static_cast<float> (tileID.y) * this->pixelSize};
}


