#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct
    {
        std::vector<TreeNode *> ruta_p;
        std::vector<TreeNode *> ruta_q;

        std::vector<TreeNode *> &operator[](size_t pos) {
            if (pos)
                return ruta_q;
            else
                return ruta_p;
        }
    } rutas;
    size_t encontrados = 0;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        DFS(root, p, q);

        size_t pos = 0;
        if (rutas[0].size() <= rutas[1].size())
            pos = rutas[0].size();
        else
            pos = rutas[1].size();

        for (int i = pos - 1; i > 0; i--) {
            if (rutas[0][i] == rutas[1][i])
                return rutas[0][i];
        }

        return root;
    }

    void DFS(TreeNode *node, TreeNode *&p, TreeNode *&q) {
        if (!node)
            return;

        rutas[encontrados].push_back(node);

        if (node == p || node == q) {
            encontrados++;

            if (encontrados == 1)
                rutas[1] = rutas[0];
            else
                return;
        }

        DFS(node->left, p, q);
        if (encontrados == 2)
            return;
        DFS(node->right, p, q);
        if (encontrados == 2)
            return;

        rutas[encontrados].pop_back();
    }
};

int main() {
    Solution sol;
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode *p = root->left;
    TreeNode *q = root->right;
    TreeNode *result = sol.lowestCommonAncestor(root, p, q);
    cout << result->val << endl;

    return 0;
}
