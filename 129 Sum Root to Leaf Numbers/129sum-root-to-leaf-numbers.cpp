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
    int sumNumbers(TreeNode* root) {
        const auto reversedSumLiterals = this->reversedSumLiterals(root);
        std::vector<int> resultSums(reversedSumLiterals.size());
        std::transform(reversedSumLiterals.begin(), reversedSumLiterals.end(), resultSums.begin(), [](const auto &rs) {
            std::string s(rs.rbegin(), rs.rend());
            return stoi(s);
        });

        return accumulate(resultSums.begin(), resultSums.end(), 0);
    }

    std::vector<std::string> reversedSumLiterals(TreeNode* curr) {
        if (!curr) {
            return {};
        }

        auto left = this->reversedSumLiterals(curr->left);
        auto right = this->reversedSumLiterals(curr->right);

        if (!left.empty() && !right.empty()) {
            left.insert(left.end(), right.begin(), right.end());
            return this->append(left, curr->val);
        } else if (left.empty() && !right.empty()) {
            return this->append(right, curr->val);
        } else if (right.empty() && !left.empty()){
            return this->append(left, curr->val);
        } else {
            std::vector<string> result{std::to_string(curr->val)};
            return result;
        }
    }

private:
    std::vector<std::string> append(std::vector<std::string> &vec, int val) {
        for (auto& s: vec) {
            s += std::to_string(val);
        }

        return vec;
    }
};