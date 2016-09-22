//
// Created by Mariusz Osowski on 3/21/16.
//

#include "Node.h"

int Node::getX() const {
    return x;
}

void Node::setX(int x) {
    Node::x = x;
}

int Node::getY() const {
    return y;
}

void Node::setY(int y) {
    Node::y = y;
}

double Node::getG() const {
    return g;
}

void Node::setG(double g) {
    f = h+g;
    Node::g = g;
}

double Node::getH() const {
    return h;
}

double Node::getF() const {
    return f;
}

void Node::setH(double h) {
    f = h+g;
    Node::h = h;
}

const std::shared_ptr<Node> &Node::getParent() const {
    return parent;
}

void Node::setParent(const std::shared_ptr<Node> &parent) {
    Node::parent = parent;
}