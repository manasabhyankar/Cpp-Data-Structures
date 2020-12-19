class Node
{
    public:
        Node* next;
        Node* previous;
        Node() : previous(nullptr), next(nullptr){};
        int get_payload();
        void set_payload(int n);
    private:
        int payload;
};