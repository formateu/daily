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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        const int treeDepth = calculateDepth(root, 1);
        std::vector<int> result;
        result.reserve(treeDepth);
        std::vector<TreeNode*> currentLevel;
        std::vector<TreeNode*> nextLevel;

        currentLevel.emplace_back(root);

        int max = std::numeric_limits<int>::min();
        while (!currentLevel.empty()) {
            for (const auto &n: currentLevel) {
                if (max < n->val) {
                    max = n->val;
                }
                
                if (n->left != nullptr) {
                    nextLevel.emplace_back(n->left);
                }

                if (n->right != nullptr) {
                    nextLevel.emplace_back(n->right);
                }
            }

            result.emplace_back(max);
            max = std::numeric_limits<int>::min();
            currentLevel = std::move(nextLevel);
            nextLevel.clear();
        }

        return result;
    }

    int calculateDepth(TreeNode *curr, int depth) {
        if (curr == nullptr) {
            return 0;
        }

        return std::max({depth, calculateDepth(curr->left, depth+1), calculateDepth(curr->right, depth+1)});
    }
};