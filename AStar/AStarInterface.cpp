//
// Created by Mariusz Osowski on 3/21/16.
//

#include "AStarInferface.h"
#include <cmath>

struct compareNodeF {
  bool operator()(const NodePtr& lhs, const NodePtr& rhs) const {
      return lhs->getF()<rhs->getF();
  }
};

struct compareNodePositon {
  bool operator()(const NodePtr& lhs, const NodePtr& rhs) const {
      if (lhs->getX()<rhs->getX())
          return true;

      if (lhs->getX()>rhs->getX())
          return false;

      return lhs->getY()<rhs->getY();
  }
};

auto findNodeByPosition(MultiSet& set, Vec2 position) {
    auto it = set.begin();

    for (; it!=set.end(); it++) {
        if ((*it)->getX()==position.first && (*it)->getY()==position.second) break;
    }

    return it;
}

AStarInterface::AStarInterface() { }

AStarInterface::~AStarInterface() { }

std::vector<Vec2> reconstructPath(NodePtr& node) {
    std::vector<Vec2> path;

    while (node) {
        path.push_back({node->getX(), node->getY()});
        node = node->getParent();
    }

    return path;
}

std::vector<Vec2> AStarInterface::findPath(Vec2 source, Vec2 target) {
    MultiSet openSet;
    Set closedSet;

    NodePtr node = std::make_shared<Node>(source.first, source.second, 0, 0);
    openSet.insert(node);

    while (!openSet.empty()) {
        node = *openSet.begin();
        Vec2 pos = {node->getX(), node->getY()};
        openSet.erase(openSet.begin());
        closedSet.insert(node);

        if (node->getX()==target.first && node->getY()==target.second) {
            return reconstructPath(node);
        }

        auto neighbors = getNeighbors(pos);

        for (auto& neighbor : neighbors) {
            if (!isNodeAccessible(pos, neighbor)) continue;

            NodePtr tmp = std::make_shared<Node>(neighbor.first, neighbor.second, 0, 0);
            double g = node->getG()+getMoveCost(pos, neighbor);

            if (closedSet.find(tmp)!=closedSet.end()) {
                continue;
            }

            auto it = findNodeByPosition(openSet, neighbor);

            if (it!=openSet.end()) {
                auto neighborNode = *it;
                if (g<neighborNode->getG()) {
                    openSet.erase(it);
                    neighborNode->setG(g);
                    neighborNode->setParent(node);
                    openSet.insert(node);
                }
            }
            else {
                tmp->setG(g);
                tmp->setH(heuristic(neighbor, target));
                tmp->setParent(node);
                openSet.insert(tmp);
            }
        }
    }

    return std::vector<Vec2>();
}

/// Euclidean distance
double AStarInterface::heuristic(Vec2 start, Vec2 end) {
    return sqrt((start.first-end.first)*(start.first-end.first)+
            (start.second-end.second)*(start.second-end.second));
}
