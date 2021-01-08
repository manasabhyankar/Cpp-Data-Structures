#include "treenode.hpp"
#include <cstddef>
class BST
{
private:
    /* data */
public:
    /* data members*/
    BST(TreeNode* start = nullptr);
    TreeNode* root;
    /* functions */
    void insert_node(TreeNode* n = nullptr);
    /* destructor */
    ~BST();
};

BST::BST(TreeNode* start)
{
    if(start == NULL)
    {
        root = new TreeNode(0);
    }
    else
    {
        root = start;
    }
}
void BST::insert_node(TreeNode* n)
{
    TreeNode* parent = root;
    if(n == NULL)
        return;
    while(1){
        if(n->get_payload() < parent->get_payload())
        {
            if(parent->left == NULL)
            {
                parent->left = n;
                return;
            }
            parent = parent->left;
        }
        else
        {
            if(parent->right == NULL)
            {
                parent->right = n;
                return;
            }
            parent = parent->right;
        }
    }
}
BST::~BST()
{
}
