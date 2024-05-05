#include "Engine.h"

void Engine::drawBackground() {
    this->window->draw(this->background);
    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j) {
            if (this->tiles[i][j]) {
                this->tile.setSize({this->pixelSize, this->pixelSize});
                this->tile.setFillColor(Color::Black);
                this->tile.setPosition(this->getTilePos({i, j}));

                this->window->draw(this->tile);
            }
        }
    }
}

void Engine::draw() {
    /*
        @return void

        -clear old frame
        -draw the different objects
        -display new frame

        Renders the game objects
     */
    this->window->clear();

    this->drawBackground();

    this->window->display();
}
