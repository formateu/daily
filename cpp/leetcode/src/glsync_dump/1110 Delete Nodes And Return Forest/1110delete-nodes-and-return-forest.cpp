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
 #include <ranges>

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        std::unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        std::unordered_map<int, TreeNode*> roots;
        roots.reserve(to_delete.size());
        roots.emplace(root->val, root);
        recursiveDelete(root, toDeleteSet, roots);
        auto kv = std::views::values(roots);
        std::vector<TreeNode*> result(kv.begin(), kv.end());

        return result;
    }

    bool recursiveDelete(TreeNode *currNode, const std::unordered_set<int> &toDelete, std::unordered_map<int, TreeNode*> &roots) {
        bool result = false;
        if (!currNode) {
            return result;
        }

        if (toDelete.contains(currNode->val)) {
            result = true;
            
            if (currNode->left) {
                roots.emplace(currNode->left->val, currNode->left);
            }

            if (currNode->right) {
                roots.emplace(currNode->right->val, currNode->right);
            }

            if (roots.contains(currNode->val)) {
                roots.erase(currNode->val);
            }
        }

        const auto r1 = recursiveDelete(currNode->left, toDelete, roots);
        const auto r2 = recursiveDelete(currNode->right, toDelete, roots);

        if (r1) {
            currNode->left = nullptr;
        }

        if (r2) {
            currNode->right = nullptr;
        }

        return result;
    }
};