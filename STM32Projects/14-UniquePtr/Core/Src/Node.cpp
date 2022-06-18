#include "Node.h"

Node::Node(int value)
  : Node(value, nullptr)
{
}

Node::Node(int value, Node* parent)
  : value(value)
{
}

void Node::setLeftChild(int value)
{
    if (!left) {
        left = std::unique_ptr<Node>(new Node(value, this));
    }
    else {
        left->value = value;
    }
}

void Node::setRightChild(int value)
{
    if (!right) {
        right = std::unique_ptr<Node>(new Node(value, this));
    }
    else {
        right->value = value;
    }
}
