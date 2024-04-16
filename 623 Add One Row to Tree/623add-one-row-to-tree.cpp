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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }

        addOneRowImpl(root, val, depth, 1);

        return root;
    }

    void addOneRowImpl(TreeNode* currNode, int val, int depth, int currentDepth) {
        if (!currNode) {
            return;
        }

        if (depth == currentDepth + 1) {
            TreeNode* newLeftNode = new TreeNode(val);
            newLeftNode->left = currNode->left;
            currNode->left = newLeftNode;

            TreeNode* newRightNode = new TreeNode(val);
            newRightNode->right = currNode->right;
            currNode->right = newRightNode;
        } else {
            addOneRowImpl(currNode->left, val, depth, currentDepth+1);
            addOneRowImpl(currNode->right, val, depth, currentDepth+1);
        }
    }
};