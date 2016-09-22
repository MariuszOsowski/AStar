//
// Created by Mariusz Osowski on 3/21/16.
//

#ifndef ASTAR_NODE_H
#define ASTAR_NODE_H

#include <memory>

class Node {
public:
    Node(int x, int y, double g, double h, const std::shared_ptr<Node>& parent = nullptr)
            :x(x), y(y), g(g), h(h), parent(parent) { f = h+g; }

    void setX(int x);

    void setY(int y);

    void setG(double g);

    void setH(double h);

    void setParent(const std::shared_ptr<Node>& parent);

    int getX() const;

    int getY() const;

    double getG() const;

    double getH() const;

    double getF() const;

    const std::shared_ptr<Node>& getParent() const;

private:
    int x, y;
    double g, h, f;
    std::shared_ptr<Node> parent;
};

#endif //ASTAR_NODE_H
