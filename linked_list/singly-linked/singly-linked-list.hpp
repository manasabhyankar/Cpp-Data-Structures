#include "node.hpp"
class SinglyLinkedList
{
    public:
        /*Member variables*/
        Node* head;
        Node* tail;
        Node* current;
        Node* previous;
        inline static int node_size = 0;
        /*Constructor*/
        SinglyLinkedList(Node* start = nullptr);
        /*Member functions*/
        void add_node(Node* n, int idx = -1);
        void delete_node(int idx = -1);
        void print_list();
        Node* search_node(int value);
};