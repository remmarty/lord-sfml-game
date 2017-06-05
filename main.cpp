#include <SFML/Graphics.hpp>
#include "classes/engine/GameEngine.h"
#include "tmx_parser/tmxparser.h"

int main() {
    // testing if parser works and gives no errors
    tmxparser::TmxMap map;
    tmxparser::TmxReturn error = tmxparser::parseFromFile("../maps/test_map.tmx", &map, "../tilesets/terrain.png");

    GameEngine engine;
    engine.run();

    return 0;
}