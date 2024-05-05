#include "Engine.h"


void Engine::initVariables() {
    /*
     * @return void
     *
     * Initialize the different variables
     */

    this->window = nullptr;

    // Game logic
    this->manualMode = true;
    this->pixelSize = 10.f;
}

void Engine::initWindow() {
    /*
     * @return void
     *
     * Initialize the window in which we display everything
     */

    this->videoMode.height = 1000;
    this->videoMode.width = 1900;
    this->window = new RenderWindow(this->videoMode, "Game1");
    this->window->setFramerateLimit(FPS);

    this->height = static_cast<int>(static_cast<float>(this->videoMode.height) /this->pixelSize);
    this->width = static_cast<int>(static_cast<float>(this->videoMode.width) / this->pixelSize);
}

void Engine::initBackground() {
    /*
     * @return void
     *
     * Initialize the background (all the blank tiles)
     */

    this->background.setSize({static_cast<float>(this->videoMode.width),
                              static_cast<float>(this->videoMode.height)});
    this->background.setFillColor(Color::White);

    for (int i = 0; i < this->width; ++i) {
        vector<bool> T;
        //vector<bool> nextT;
        for (int j = 0; j < this->height; ++j) {
            //this->tile.setSize({this->pixelSize, this->pixelSize});
            //this->tile.setFillColor(Color::White);
            //this->tile.setPosition(this->getTilePos({i, j}));
            T.push_back(false);
            //nextT.push_back(false);
        }
        this->tiles.push_back(T);
        this->nextTurnTiles.push_back(T);
    }
}


//Constructors / Destructors
Engine::Engine() {
    this->initVariables();
    this->initWindow();
    this->initBackground();
}

Engine::~Engine() {
    delete this->window;
}

// Accessors
bool Engine::getWindowIsOpen() const {
    return this->window->isOpen();
}

void Engine::run() {
    // Main Loop, run until the window is closed
    update();
    draw();
}
