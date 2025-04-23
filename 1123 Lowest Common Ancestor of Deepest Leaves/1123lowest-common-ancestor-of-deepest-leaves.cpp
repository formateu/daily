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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        const int depth = maxDepth(root, 0);
        return impl(root, 0, depth);
        
    }
    
    TreeNode* impl(TreeNode* curr, int currentDepth, int maxDepth) {
        if (curr == nullptr) {
            return nullptr;
        }

        TreeNode* leftLca = impl(curr->left, currentDepth + 1, maxDepth);
        TreeNode* rightLca = impl(curr->right, currentDepth + 1, maxDepth);

        if (currentDepth == maxDepth) {
            return curr;
        }

        if (leftLca != nullptr && rightLca != nullptr) {
            return curr;
        }

        if (leftLca != nullptr) {
            return leftLca;
        }

        if (rightLca != nullptr) {
            return rightLca;
        }

        return nullptr;
    }

    int maxDepth(TreeNode* curr, const int currentDepth) {
        if (curr == nullptr) {
            return 0;
        }

        const int maxDepthLeft = maxDepth(curr->left, currentDepth + 1);
        const int maxDepthRight = maxDepth(curr->right, currentDepth + 1);
        const int maxChildDepth = std::max(maxDepthLeft, maxDepthRight);

        return std::max(maxChildDepth, currentDepth);
    }
};