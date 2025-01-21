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
    bool isBalanced(TreeNode *root) {
        return dfs(root, 1) != -1;
    }

    int dfs(TreeNode *root, int prof) {
        if (!root)
            return prof;

        int prof_left = dfs(root->left, prof);
        int prof_right = dfs(root->right, prof);

        if (prof_left == -1 || prof_right == -1 ||
            abs(prof_left - prof_right) > 1)

            return -1;

        return prof + (prof_left >= prof_right) * prof_left + (prof_left < prof_right) * prof_right;
    }
};

int main() {
    Solution sol;
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    bool ans = sol.isBalanced(root);
    cout << boolalpha << ans;

    return 0;
}
