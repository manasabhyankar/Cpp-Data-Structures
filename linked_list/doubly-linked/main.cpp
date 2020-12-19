#include "double_link_node.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /***********************************/
    /*Node setup for doubly-linked list*/
    /***********************************/

    vector<Node*> nodes;
    for (size_t i = 0; i < 10; i++)
    {
        Node* n = new Node();
        n->set_payload(i*10);
        nodes.push_back(n);
    }
    Node* head = nodes[0];
    Node* tail = nodes[nodes.size()-1];
    Node* current = head;
    Node* prev = head;
    for(int i = 1; i<nodes.size(); i++){
        current->next = nodes[i];
        current->previous = prev;
        prev = current;
        current = current->next;
    }
    tail->next = nullptr;
    prev = head;
    current = head;
    /***********************************/
    /***Test node insertion into head***/
    /***********************************/
    Node* ins1 = new Node();
    ins1->set_payload(345);
    current->previous = ins1;
    ins1->next = current;
    ins1->previous = ins1;
    head = ins1;
    current = head;
    prev = head;
    /***********************************/
    /***Test node insertion into index**/
    /***********************************/
    Node* ins2 = new Node();
    ins2->set_payload(72);
    //let's insert to index 3
    for(int idx = 0; idx < 3; ++idx)
    {
        prev = current;
        current = current->next;
    }
    //current is now at index 3.
    //prev is now at index 2
    prev->next = ins2;
    ins2->previous = prev;
    ins2->next = current;
    current->previous = ins2;
    current = head;
    prev = head;
    /***********************************/
    /***Test node insertion into tail***/
    /***********************************/
    Node* ins3 = new Node();
    ins3->set_payload(42980745);
    while(current->next != NULL){
        prev = current;
        current = current->next;
    }
    current->next = ins3;
    ins3->next = nullptr;
    ins3->previous = current;
    prev = current;
    current = current->next;
    tail = ins3;
    current = head;
    prev = head;
    /**********************************************/
    /*********Delete the node at the head.*********/
    /**********************************************/
    current = current->next;
    delete prev;
    head = current;
    /***********************************************/
    /*******Delete the node at index 3.*************/
    /***********************************************/
    for (size_t i = 0; i < 3; i++)
    {
        current = current->next;
    }
    current->previous->next = current->next;
    current->next->previous = current->previous;
    current->next = nullptr;
    current->previous = nullptr;
    delete current;
    current = head;
    /***********************************************/
    /*******Delete the node at the tail.************/
    /***********************************************/
    while(current->next)
    {
        current = current->next;
    }
    current->previous->next = nullptr;
    current->previous = nullptr;
    current->next = nullptr;
    delete current;
    current = head;
    while(current != nullptr)
    {
        cout << "Current node value: " << current->get_payload() << endl;
        current = current->next;
    }
}