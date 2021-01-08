#include "doubly-linked-list.hpp"
#include <vector>
#include <iostream>
using namespace std;
/*
If passed in a valid start node, the constructor shall
create a new SinglyLinkedList with the node start as
the head of the list. If start is not valid, the head of
the SinglyLinkedList shall be a new Node.
*/
DoublyLinkedList::DoublyLinkedList(Node* start)
{
    if(!start == NULL)
    {
        head = start;
        head->next = nullptr;
        head->previous = nullptr;
        DoublyLinkedList::node_size++;
    }
    else
    {
        head = new Node(0);
        tail = head;
        head->next = nullptr;
        head->previous = nullptr;
        current = head;
        previous = head;
        DoublyLinkedList::node_size++;
    }   
}

/*
Add a new node somewhere in the linked list. If the
index is invalid, an error will be output. If no
index is specified, the default behavior will append 
the new node to the list.
*/
void DoublyLinkedList::add_node(Node* n, int idx)
{
    current = head;
    previous = head;
    if(idx == -1)
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = n;
        n->next = nullptr;
        n->previous = current;
        tail = n;
        current = head;
        previous = head;
        DoublyLinkedList::node_size++;
    }
    else if(idx <= 0)
    {
        n->next = head;
        n->previous = nullptr;
        head->previous = n;
        head = n;
        current = head;
        previous = head;
        DoublyLinkedList::node_size++;
    }
    else if(idx >= node_size - 1)
    {
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = n;
        n->next = nullptr;
        n->previous = current;
        tail = n;
        current = head;
        previous = head;
        DoublyLinkedList::node_size++;
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
        n->previous = previous;
        current->previous = n;
        current = head;
        previous = head;
        DoublyLinkedList::node_size++;
    }
}

/*
Delete a node somewhere in the linked list. If the
index is invalid, an error will be output. If no
index is specified, the default behavior will delete 
the head.
*/
void DoublyLinkedList::delete_node(int idx)
{
    current = head;
    previous = head;
    if(idx <= 0)
    {
        head = head->next;
        head->previous = nullptr;
        current->next = nullptr;
        delete current;
        current = head;
        previous = head;
        DoublyLinkedList::node_size--;
    }
    else if(idx >= node_size - 1)
    {
        while(current->next)
        {
            previous = current;
            current = current->next;
        }
        previous->next = nullptr;
        tail = previous;
        delete current;
        current = head;
        previous = head;
        DoublyLinkedList::node_size--;
    }
    else
    {
        for(int i = 0; i < idx; ++i)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        current->next->previous = previous;
        delete current;
        current = head;
        previous = head;
        DoublyLinkedList::node_size--;
    }
}
/*
Search for a node in the list and return it
if it exists.
*/
Node* DoublyLinkedList::search_node(int val)
{
    current = head;
    previous = head;
    while(current != nullptr)
    {
        if(current->get_payload() == val)
        {
            cout << "Found a node with the value: " << val
            << "." << endl;
            return current;
        }
        current = current->next;
    }
    cout << "Did not find a node with the value: " << val
    << "." << endl;
    return nullptr;
}
/*
Print the values and indices of list. Guarantees
current and previous will point to head when the
function exits.
*/
void DoublyLinkedList::print_list()
{
    int node_idx = 0;
    current = head;
    while(current != NULL)
    {
        string prev_val, next_val;
        if(current->previous == NULL)
        {
            prev_val = "NULL";
        }
        else
        {
            prev_val = to_string(current->previous->get_payload());
        }
        if(current->next == NULL)
        {    
            next_val = "NULL";
        }
        else
        {
            next_val = to_string(current->next->get_payload());
        }
        cout << "Node Index: " << node_idx
        << "\t|\t" << "Node Value: " << current->get_payload()
        << "\t|\t" << "Previous Node: " << prev_val
        << "\t|\t" << "Next Node: " << next_val
        << endl;
        current = current->next;
        ++node_idx;
    }
    cout << endl;
}