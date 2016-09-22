//
// Created by Mariusz Osowski on 22/9/16.
//


#include "GridAStar.h"

void GridAStar::setMap(std::vector<std::vector<int>>& map) {
    this->map = map;
}

std::vector<Vec2> GridAStar::getNeighbors(Vec2 source) {
    std::vector<Vec2> neighbors(4);

    neighbors[0] = {source.first+1, source.second};
    neighbors[1] = {source.first, source.second-1};
    neighbors[2] = {source.first-1, source.second};
    neighbors[3] = {source.first, source.second+1};

    return neighbors;
}

bool GridAStar::isNodeAccessible(Vec2 src, Vec2 tgt) {
    int x = tgt.first, y = tgt.second;

    if (y<0 || y>=map.size()) return false;
    if (x<0 || x>=map[y].size()) return false;

    if (map[y][x]==0) return true;

    return false;
}

double GridAStar::getMoveCost(Vec2 src, Vec2 tgt) {
    return heuristic(src, tgt);
}
