#include "singly-linked-list.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    Node* n = new Node(0);
    SinglyLinkedList test(n);
    test.add_node(new Node(1));
    test.add_node(new Node(2));
    test.add_node(new Node(3));
    test.add_node(new Node(4));
    test.print_list();
    test.delete_node(0);
    test.delete_node(2);
    test.print_list();
    test.add_node(new Node(0), -40);
    test.add_node(new Node(5), 100000);
    test.print_list();
    test.add_node(new Node(3), 3);
    test.print_list();
    Node* f = test.search_node(2);
    cout << f->get_payload() << endl;
    Node* ff = test.search_node(199);
    if(ff == NULL)
        cout << "NULL" << endl;
    return 0;
}