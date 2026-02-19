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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        std::unordered_map<int, TreeNode*> nodeMap;
        for (const auto &d: descriptions) {
            const auto &parent = d[0];
            const auto &child = d[1];
            const auto &isLeft = d[2];
            if (!nodeMap.contains(parent)) {
                nodeMap.emplace(parent, new TreeNode(parent, nullptr, nullptr));
            }

            if (!nodeMap.contains(child)) {
                nodeMap.emplace(child, new TreeNode(child, nullptr, nullptr));
            }

            if (isLeft) {
                nodeMap[parent]->left = nodeMap[child];
            } else {
                nodeMap[parent]->right = nodeMap[child];
            }
        }
        unordered_set<int> children;
        transform(descriptions.begin(), descriptions.end(), std::inserter(children, children.begin()), [](const auto &d) {
            return d[1];
        });

        unordered_set<int> parents;
        transform(descriptions.begin(), descriptions.end(), std::inserter(parents, parents.begin()), [](const auto &d) {
            return d[0];
        });

        int rootIndex = 0;
        for (const auto &parent: parents) {
            if (!children.contains(parent)) {
                rootIndex = parent;
                break;
            }
        }

        return nodeMap[rootIndex];
    }
};