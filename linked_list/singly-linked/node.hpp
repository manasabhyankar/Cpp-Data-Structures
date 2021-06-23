class Node
{
    public:
        Node();
        Node(int val);
        Node* next;
        int get_payload();
        void set_payload(int n);
    private:
        int payload;
};