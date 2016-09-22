//
// Created by Mariusz Osowski on 22/9/16.
//

#include "GridAStar.h"
#include <iostream>
#include <ctime>
#include "Helper.h"

int main() {
    srand(time(NULL));
    GridAStar astar;
    std::vector<Vec2> path;

    std::vector<std::vector<int>> map;

    while (path.size()==0) {
        map = generateMap(60, 60);
        astar.setMap(map);
        path = astar.findPath({0, 59}, {59, 0});
    }

    drawPathOnMap(map, path);
    std::string html = renderMapToHtml(map);
    Save("map.html", html);

    OpenInBrowser("map.html");

    return 0;
}
