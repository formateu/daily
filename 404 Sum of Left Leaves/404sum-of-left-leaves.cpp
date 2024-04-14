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
    int sumOfLeftLeaves(TreeNode* root) {
        return this->sumOfLeftLeavesImpl(root, false);
    }

    int sumOfLeftLeavesImpl(TreeNode* node, bool count) {
        if (!node) {
            return 0;
        }

        auto sum = sumOfLeftLeavesImpl(node->left, true) + sumOfLeftLeavesImpl(node->right, false);
        return count && node->left == nullptr && node->right == nullptr ? sum + node->val : sum;
    }
};