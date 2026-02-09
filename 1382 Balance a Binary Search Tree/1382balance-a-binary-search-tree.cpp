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
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> vals;
        inOrder(root, vals);

        return construct(vals, 0, vals.size() / 2, vals.size());

    }

    void inOrder(TreeNode *curr, std::vector<int> &vals) {
        if (curr == nullptr) return;
        inOrder(curr->left, vals);
        vals.emplace_back(curr->val);
        inOrder(curr->right, vals);
    }

    TreeNode* construct(const std::vector<int> &vals, std::size_t l, std::size_t p, std::size_t r) {
        TreeNode* node = new TreeNode(vals[p]);

        if (l < p) {
            std::size_t lp = l + (p - l) / 2;
            node->left = construct(vals, l, lp, p);
        }

        if (p + 1 < r) {
            std::size_t rl = p + 1;
            std::size_t rp = rl + (r - rl) / 2;
            node->right = construct(vals, rl, rp, r);
        }

        return node;
    }
};