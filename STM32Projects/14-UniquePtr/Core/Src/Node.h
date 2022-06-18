#pragma once

#include <memory>

class Node
{
public:
    explicit Node(int value);

    void setLeftChild(int value);
    void setRightChild(int value);

private:
    Node(int value, Node* parent);

private:
    int value = 0;
    Node* parent = nullptr;

    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};
