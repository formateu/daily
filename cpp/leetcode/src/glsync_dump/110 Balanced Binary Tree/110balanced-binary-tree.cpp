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
    bool isBalanced(TreeNode* root) {
        int height = 1;
        return postOrderCheck(root, height);
    }

    bool postOrderCheck(TreeNode *curr, int &height) {
        if (curr == nullptr) {
            return true;
        } else {
            ++height;
        }

        int lh = height;
        int rh = height;
        bool l = postOrderCheck(curr->left, lh);
        bool r = postOrderCheck(curr->right, rh);
        height = std::max(lh, rh);

        return l && r && std::abs(lh - rh) <= 1;

    }
};