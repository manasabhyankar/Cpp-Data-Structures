#include "double_link_node.hpp"

Node::Node()
{}

Node::Node(int value)
    :payload(value)
{}

int Node::get_payload()
{
    return payload;
}

void Node::set_payload(int n)
{
    payload = n;
}