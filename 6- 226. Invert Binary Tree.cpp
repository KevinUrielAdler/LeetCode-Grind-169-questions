#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root)
            return root;

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};


int main() {
    Solution sol;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    TreeNode *res = sol.invertTree(root);

    std::cout<<res->val<<std::endl;
    std::cout<<res->left->val<<std::endl;
    std::cout<<res->right->val<<std::endl;
    std::cout<<res->left->left->val<<std::endl;
    std::cout<<res->left->right->val<<std::endl;
    std::cout<<res->right->left->val<<std::endl;
    std::cout<<res->right->right->val<<std::endl;
    return 0;
}
