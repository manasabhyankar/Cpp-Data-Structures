class Node
{
    public:
        Node* next;
        int get_payload();
        void set_payload(int n);
    private:
        int payload;
};