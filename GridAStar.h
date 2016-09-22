//
// Created by Mariusz Osowski on 22/9/16.
//

#ifndef ASTAR_GRIDASTAR_H
#define ASTAR_GRIDASTAR_H

#include "AStar/AStarInferface.h"

class GridAStar : public AStarInterface {
public:
    void setMap(std::vector<std::vector<int>>& map);

protected:
    std::vector<std::vector<int>> map;

    virtual std::vector<Vec2> getNeighbors(Vec2 source) override;

    virtual bool isNodeAccessible(Vec2 src, Vec2 tgt) override;

    virtual double getMoveCost(Vec2 src, Vec2 tgt) override;
};

#endif //ASTAR_GRIDASTAR_H
