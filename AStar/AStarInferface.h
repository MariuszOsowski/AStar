//
// Created by Mariusz Osowski on 3/21/16.
//

#ifndef ASTAR_INTERFACE_H
#define ASTAR_INTERFACE_H

#include <vector>
#include <utility>
#include <set>
#include "Node.h"

typedef std::pair<int, int> Vec2;
struct compareNodeF;
struct compareNodePositon;
typedef std::shared_ptr<Node> NodePtr;
typedef std::multiset<NodePtr, compareNodeF> MultiSet;
typedef std::set<NodePtr, compareNodePositon> Set;

class AStarInterface {
public:
    AStarInterface();

    virtual ~AStarInterface();

    virtual std::vector<Vec2> findPath(Vec2 source, Vec2 target);

protected:
    virtual double heuristic(Vec2 source, Vec2 target);

    virtual std::vector<Vec2> getNeighbors(Vec2 source) = 0;

    virtual bool isNodeAccessible(Vec2 src, Vec2 tgt) = 0;

    virtual double getMoveCost(Vec2 src, Vec2 tgt) = 0;
};

#endif //ASTAR_INTERFACE_H
