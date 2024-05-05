#include "Engine.h"

void Engine::updateWindow() {
    /*
     * @return void
     *
     * Close the window when the "escape" key is pressed
     * or when clicking the exit x
     */

    switch (this->event.type) {
        case Event::Closed:
            this->window->close();
            break;
        case Event::KeyPressed:
            if (this->event.key.code == Keyboard::Escape) {
                this->window->close();
            }
            break;
        default:
            break;
    }
}

void Engine::updateMousePosition() {
    /*
     * @return void
     *
     * get and update the mouse position
     */

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Engine::updateTileClick() {
    /*
     * @return void
     *
     * Modify the tiles when clicking on them :
     * kill them if they are alive, and give them life if they are dead
     */

    switch (this->event.type) {
        case Event::MouseButtonPressed:
            static bool firstClick = true;
            if (this->event.mouseButton.button == Mouse::Left && firstClick) {
                this->startingTileID = getTileID(this->mousePosView);
                this->startingTile = tiles[this->startingTileID.x][this->startingTileID.y];
                this->tiles[this->startingTileID.x][this->startingTileID.y] = !this->startingTile;
                firstClick = false;
            }
            break;

        case Event::MouseMoved:
            if (!firstClick) {
                Vector2i tileID = getTileID(this->mousePosView);
                this->tiles[tileID.x][tileID.y] = !this->startingTile;
            }
            break;

        case Event::MouseButtonReleased:
            if (event.mouseButton.button == Mouse::Left) {
                firstClick = true;
            }
            break;

        default:
            break;
    }
}

void Engine::changeMode() {
    /*
     * @return void
     *
     * Launch the game of life or return to manual mode by pressing Enter
     */

    switch (this->event.type) {
        case Event::KeyPressed:
            if (this->event.key.code == Keyboard::Enter) {
                this->manualMode = !this->manualMode;
            }
            break;

        default:
            break;
    }
}

void Engine::updateBoard() {
    /*
     * @return void
     *
     * Update the board according to the rules of the game
     */
    this->nextTurnTiles = tiles;

    for (int i = 0; i < this->width; ++i) {
        for (int j = 0; j < this->height; ++j) {
            birth({i,j});
            death({i, j});
        }
    }
    this->tiles = nextTurnTiles;
}

void Engine::reset() {
    /*
     * @return void
     *
     * Return to the initial state of the game by pressing Space
     */
    switch (this->event.type) {
        case Event::KeyPressed:
            if (this->event.key.code == Keyboard::Space) {
                for (int i = 0; i < this->width; ++i) {
                    for (int j = 0; j < this->height; ++j) {
                        this->tiles[i][j] = false;
                        this->nextTurnTiles[i][j] = false;
                    }
                }
            }
            break;
        default:
            break;
    }
}

int delay(int milliseconds){
    clock_t goal = milliseconds + clock();
    while(clock() < goal);
    return 1;
}

void Engine::update() {
    /*
     *@return void
     *
     * Executes all the "update" functions.
     * -If the minotaur catches the player, game over
     * -If the player reaches the exit tile, you win
     */
    if (manualMode) {
        while (window->pollEvent(this->event)) {
            this->updateWindow();
            this->updateMousePosition();
            this->updateTileClick();
            this->reset();
            this->changeMode();
        }
    } else {

        // game of life
        this->updateBoard();
        delay(50);

        // return to manual mode
        while (window->pollEvent(this->event)) {
            this->updateWindow();
            this->changeMode();
        }
    }
}
