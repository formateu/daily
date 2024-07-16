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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        std::string startPath; 
        std::string destPath;
        buildPathToNode(root, startValue, startPath);
        buildPathToNode(root, destValue, destPath);
        std::reverse(startPath.begin(), startPath.end());
        std::reverse(destPath.begin(), destPath.end());

        int index = 0;
        for (int i = 0; i < max(startPath.size(), destPath.size()); ++i) {
            if (i >= min(startPath.size(), destPath.size()) ||startPath[i] != destPath[i]) {
                index = i;
                break;
            } 
        }

        if (!startPath.empty()) {
            startPath = startPath.substr(index);
        }

        for (auto &p : startPath) {
            p = 'U';
        }

        if (!destPath.empty()) {
            destPath = destPath.substr(index);
        }

        return startPath + destPath;
    }
private:
    bool buildPathToNode(TreeNode *currentNode, int searchedValue, std::string &res) {
        if (currentNode == nullptr) {
            return false;
        }

        if (currentNode->val == searchedValue) {
            return true;
        } else {
            const bool left = buildPathToNode(currentNode->left, searchedValue, res);
            if (left) {
                res += 'L';
            }
            const bool right = buildPathToNode(currentNode->right, searchedValue, res);
            if (right) {
                res += 'R';
            }

            return left || right;
        }
    }
};