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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        const int maxDepth = calcMaxDepth(root, 0);
        int seen = 0;
        return maxDepthCount(root, maxDepth, 0, seen);
    }

    int calcMaxDepth(TreeNode* node, int currentDepth) {
        int result = currentDepth;
        if (node->left != nullptr) {
            result = std::max(result, calcMaxDepth(node->left, currentDepth + 1));
        }

        if (node->right != nullptr) {
            result = std::max(result, calcMaxDepth(node->right, currentDepth + 1));
        }

        return result;
    }

    TreeNode* maxDepthCount(TreeNode* node, const int maxDepth, int currentDepth, int &seen) {
        if (node == nullptr) {
            return nullptr;
        }
        if (currentDepth == maxDepth) {
            ++seen;
            return node;
        };

        int lseen = 0;
        TreeNode* leftResult = maxDepthCount(node->left, maxDepth, currentDepth + 1, lseen);
        int rseen = 0;
        TreeNode* rightResult = maxDepthCount(node->right, maxDepth, currentDepth + 1, rseen);

        if (lseen > 0 && rseen > 0) {
            seen = lseen + rseen;
            return node;
        } else if (lseen > 0) {
            seen = lseen;
            return leftResult;
        } else if (rseen > 0) {
            seen = rseen;
            return rightResult;
        }
        
        return nullptr;
    } 
};