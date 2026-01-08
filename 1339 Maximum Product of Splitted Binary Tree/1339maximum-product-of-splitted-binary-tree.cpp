/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static constexpr int MOD = 1'000'000'007;
    long long total = 0;
    long long best = 0;

    long long sumTree(TreeNode* node) {
        if (!node) return 0;
        return static_cast<long long>(node->val) + sumTree(node->left) + sumTree(node->right);
    }

    long long dfs(TreeNode* node) {
        if (!node) return 0;
        long long s = static_cast<long long>(node->val) + dfs(node->left) + dfs(node->right);

        best = std::max(best, s * (total - s));
        return s;
    }

    int maxProduct(TreeNode* root) {
        total = sumTree(root);
        dfs(root);
        return best % MOD;
    }
};