#include "singly-linked-list.hpp"
#include <vector>
#include <iostream>
using namespace std;

/*
If passed in a valid start node, the constructor shall
create a new SinglyLinkedList with the node start as
the head of the list. If start is not valid, the head of
the SinglyLinkedList shall be a new Node.
*/
SinglyLinkedList::SinglyLinkedList(Node* start)
{
    if(!start == NULL)
    {
        head = start;
        SinglyLinkedList::node_size++;
    }
    else
    {
        head = new Node(0);
        tail = head;
        tail->next = nullptr;
        current = head;
        previous = head;
        SinglyLinkedList::node_size++;
    }   
}

/*
Add a new node somewhere in the linked list. If the
index is invalid, an error will be output. If no
index is specified, the default behavior will append 
the new node to the list.
*/
void SinglyLinkedList::add_node(Node* n, int idx)
{
    current = head;
    previous = head;
    if(idx == -1)
    {
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = n;
        n->next = nullptr;
        tail = n;
        current = head;
        previous = head;
        SinglyLinkedList::node_size++;
    }
    else if(idx <= 0)
    {
        n->next = head;
        head = n;
        current = head;
        previous = head;
        SinglyLinkedList::node_size++;
    }
    else if(idx >= node_size - 1)
    {
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = n;
        n->next = nullptr;
        tail = n;
        current = head;
        previous = head;
        SinglyLinkedList::node_size++;
    }
    else
    {
        for(int i = 0; i < idx; ++i)
        {
            previous = current;
            current = current->next;
        }
        previous->next = n;
        n->next = current;
        current = head;
        previous = head;
        SinglyLinkedList::node_size++;
    }
}

/*
Delete a node somewhere in the linked list. If the
index is invalid, an error will be output. If no
index is specified, the default behavior will delete 
the head.
*/
void SinglyLinkedList::delete_node(int idx)
{
    current = head;
    previous = head;
    if(idx <= 0)
    {
        head = head->next;
        current->next = nullptr;
        delete current;
        current = head;
        previous = head;
        SinglyLinkedList::node_size--;
    }
    else if(idx >= node_size - 1)
    {
        while(current->next)
        {
            previous = current;
            current = current->next;
        }
        previous->next = nullptr;
        current->next = nullptr;
        tail = previous;
        delete current;
        current = head;
        previous = head;
        SinglyLinkedList::node_size--;
    }
    else
    {
        for(int i = 0; i < idx; ++i)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        current->next = nullptr;
        delete current;
        current = head;
        previous = head;
        SinglyLinkedList::node_size--;
    }
}
/*
Print the values and indices of list. Guarantees
current and previous will point to head when the
function exits.
*/
void SinglyLinkedList::print_list()
{
    int node_idx = 0;
    current = head;
    while(current != NULL)
    {
        cout << "Node Index: " << node_idx
        << " | " << "Node Value: " << current->get_payload()
        << endl;
        current = current->next;
        ++node_idx;
    }
    cout << endl;
    current = head;
    previous = head;
}
/*
Search for a node with a specific value.
*/
Node* SinglyLinkedList::search_node(int value)
{
    current = head;
    previous = head;
    while(current != NULL)
    {
        if(current->get_payload() == value)
        {
            cout << "Found a node with the value: " << value
            << "." << endl;
            return current;
        }
        current = current->next;
    }
    cout << "Did not find a node with the value: " << value
    << "." << endl;
    return nullptr;
}