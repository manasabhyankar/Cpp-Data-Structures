#include "double_link_node.hpp"
class DoublyLinkedList
{
    public:
        /*Member variables*/
        Node* head;
        Node* tail;
        Node* current;
        Node* previous;
        inline static int node_size = 0;
        /*Constructor*/
        DoublyLinkedList(Node* start = nullptr);
        /*Member functions*/
        void add_node(Node* n, int idx = -1);
        void delete_node(int idx = -1);
        Node* search_node(int val);
        void print_list();
};