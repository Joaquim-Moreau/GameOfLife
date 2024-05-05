#ifndef MINOTAUR_ENGINE_H
#define MINOTAUR_ENGINE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <ctime>

using namespace sf;
using namespace std;

class Engine {
private:
    // Variables
    // Window
    Event event{};
    RenderWindow* window;
    VideoMode videoMode;

    const unsigned int FPS = 60;

    // Mouse position
    Vector2i mousePosWindow;
    Vector2f mousePosView;

    // Game logic
    bool manualMode;
    float pixelSize;
    int height;
    int width;

    // Game objects
    RectangleShape background;
    vector<vector<bool>> tiles;
    vector<vector<bool>> nextTurnTiles;
    RectangleShape tile;
    bool startingTile;
    Vector2i startingTileID;

    // Private Functions
    void initVariables();
    void initWindow();
    void initBackground();

public:
    // Constructors / Destructors
    Engine();
    virtual ~Engine();

    // Accessors
    bool getWindowIsOpen() const;

    // Functions
    void updateWindow();
    void updateMousePosition();
    void updateTileClick();
    void changeMode();
    void updateBoard();
    void reset();
    void update();

    int getNumberNeighbour(Vector2i tileID);
    void birth(Vector2i tileID);
    void death(Vector2i tileID);

    void drawBackground();
    void draw();

    Vector2i getTileID(Vector2f mousePos);
    Vector2f getTilePos(Vector2i tileID);

    // The main loop will be in the run function
    void run();
};


#endif
