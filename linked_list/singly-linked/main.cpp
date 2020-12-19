#include "node.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    // Setup nodes and link together into list
    vector<Node*> nodes;
    for(int i=0; i<5; i++)
    {
        Node* n = new Node();
        n->set_payload(i);
        nodes.push_back(n);
    }
    Node* head = nodes[0];
    Node* tail = nodes[4];
    Node* current = head;
    Node* previous = head;
    for (size_t i = 1; i < nodes.size(); i++)
    {
        current->next = nodes[i];
        current = current->next;
    }
    tail->next = nullptr;
    /***********************************************/
    /*******Insert the new node at the head.*******/
    /***********************************************/
    Node* ins = new Node();
    ins->set_payload(42);
    // test to see if node can be "inserted" at head
    ins->next = head;
    head = ins;
    current = head;
    previous = head;
    /***********************************************/
    /*******Insert the new node at index 1.*******/
    /***********************************************/
    Node* ins1 = new Node();
    ins1->set_payload(100);
    //test to see if node can be inserted in the middle
    //current size of linked list is 4
    //we will insert at index 1
    current = current->next; //current is pointing to index 1
    previous = head; //previous node is pointing to head
    previous->next = ins1; //previous node's next is new node
    ins1->next = current; //new node's next is current
    current = head;
    previous = head;
    /***********************************************/
    /*******Insert the new node at the tail.*******/
    /***********************************************/
    Node* ins2 = new Node();
    ins2->set_payload(55);
    //test to see if node can be "inserted" at tail
    //current linked list size is 5
    while(current->next) //iterate to end of linked list
    {
        current = current->next;   
    }
    //current is the tail currently
    //set tail's next to new node and new node's next to nullptr
    current->next = ins2;
    // tail = ins2;
    //reset current pointer
    current = head;
    while(current)
    {
        cout << current->get_payload() << "\n";
        current = current->next;
    } 

    return 0;
}