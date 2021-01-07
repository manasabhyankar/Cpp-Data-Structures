#include "doubly-linked-list.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    Node* n = new Node(0);
    DoublyLinkedList test(n);
    test.add_node(new Node(0), 0);
    test.add_node(new Node(1));
    test.add_node(new Node(2));
    test.add_node(new Node(3));
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
    if(f == NULL)
        cout << "NULL" << endl;
    Node* ff = test.search_node(5);
    cout << ff->get_payload() << endl;
    return 0;
}