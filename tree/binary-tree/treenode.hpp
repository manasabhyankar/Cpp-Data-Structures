class TreeNode
{
private:
    int payload;
public:
    TreeNode(int value = 0);
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    int get_payload();
    void set_payload(int value);
    ~TreeNode();
};

TreeNode::TreeNode(int value)
    : payload(value)
{}
int TreeNode::get_payload()
{
    return payload;
}
void TreeNode::set_payload(int value)
{
    payload = value;
}
