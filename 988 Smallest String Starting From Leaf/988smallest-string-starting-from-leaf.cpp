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
    string smallestFromLeaf(TreeNode* root) {
        const auto resultVector = smallestFromLeafImpl(root);
        const auto minValueIt = std::min_element(resultVector.begin(), resultVector.end());

        return minValueIt != resultVector.end()  ? *minValueIt : "";
    }

    std::vector<std::string> smallestFromLeafImpl(TreeNode* currLeaf) {
        if (!currLeaf) {
            return {};
        }

        auto vL = smallestFromLeafImpl(currLeaf->left);
        auto vR = smallestFromLeafImpl(currLeaf->right);

        std::vector<std::string> result;
        static constexpr std::int32_t LiteralOffset = 97;
        const char newLetter = static_cast<char>(currLeaf->val + LiteralOffset);

        if (vL.empty() && vR.empty()) {
            result.emplace_back(std::string(1, newLetter));
        } else {
            if (vL.size()) {
                std::move(vL.begin(), vL.end(), std::back_inserter(result));
            }

            if (vR.size()) {
                std::move(vR.begin(), vR.end(), std::back_inserter(result));
            }

            for (auto &s: result) {
                s.push_back(newLetter);
            }
        }

        return result;
    }
};