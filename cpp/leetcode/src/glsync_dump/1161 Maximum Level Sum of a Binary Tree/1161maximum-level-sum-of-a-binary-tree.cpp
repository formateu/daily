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
    int maxLevelSum(TreeNode* root) {
        std::vector<int> levelSum;
        std::queue<std::pair<int, TreeNode*>> q;
        q.emplace(1, root);

        while (!q.empty()) {
            const auto [l, node] = q.front();
            q.pop();
            if (levelSum.size() < l) {
                levelSum.emplace_back(node->val);
            } else {
                levelSum[l-1] += node->val;
            }

            if (node->left != nullptr) {
                q.emplace(l+1, node->left);
            }

            if (node->right != nullptr) {
                q.emplace(l+1, node->right);
            }
        }

        int cur = std::numeric_limits<int>::min();
        int result = 0;
        for (int i = 0; i < levelSum.size(); ++i) {
            if (levelSum[i] > cur) {
                result = i;
                cur = levelSum[i];
            }
        }

        return result + 1;
    }
};