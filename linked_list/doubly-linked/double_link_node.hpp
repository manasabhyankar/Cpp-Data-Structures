class Node
{
    public:
        Node* next;
        Node* previous;
        Node();
        Node(int value);
        int get_payload();
        void set_payload(int n);
    private:
        int payload;
};