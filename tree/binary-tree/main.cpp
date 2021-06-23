#include "BST.hpp"
#include <iostream>
using namespace std;
int main()
{
    TreeNode* n = new TreeNode(5);
    BST tree;
    tree.insert_node(n);
    tree.insert_node(new TreeNode(-5));
    cout << tree.root->left->get_payload() << " | " << tree.root->right->get_payload();
    return 0;
}