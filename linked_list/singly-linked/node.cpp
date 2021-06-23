#include "node.hpp"

Node::Node()
{}
Node::Node(int val)
    : payload(val)
{}
int Node::get_payload()
{
    return payload;
}

void Node::set_payload(int n)
{
    payload = n;
}