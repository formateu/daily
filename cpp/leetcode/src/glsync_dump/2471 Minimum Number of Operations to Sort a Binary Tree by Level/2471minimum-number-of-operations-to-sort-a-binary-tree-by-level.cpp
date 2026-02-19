
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
    int minimumOperations(TreeNode* root) {
        std::vector<TreeNode*> currentLevel;
        std::vector<TreeNode*> nextLevel;
        int result = 0;
        currentLevel.emplace_back(root);

        while (!currentLevel.empty()) {
            // nlogn for each floor -> nlog^2(n)
            result += calculateLevel(currentLevel);
            for (const auto &node: currentLevel) {
                if (node->left != nullptr) {
                    nextLevel.emplace_back(node->left);
                }
                if (node->right != nullptr) {
                    nextLevel.emplace_back(node->right);
                }
            }

            currentLevel = std::move(nextLevel);
            nextLevel.clear();
        }

        return result;
    }

    int calculateLevel(std::vector<TreeNode*> &currentLevel) {
        if (currentLevel.size() < 2) {
            return 0;
        }

        int numberOfOperations = 0;

        // l = level size (n/2 at max?) -> O(l) ~ O(n)
        // O(n)
        std::vector<int> sortedLevel(currentLevel.size());
        std::transform(
            currentLevel.begin(),
            currentLevel.end(),
            sortedLevel.begin(),
            [](TreeNode *curr) { return curr->val; }
        );
        std::vector<int> currentLevelVals(sortedLevel);

        //O(nlogn)
        std::sort(sortedLevel.begin(), sortedLevel.end());
        std::unordered_map<int, int> valToIndMap;
        valToIndMap.reserve(sortedLevel.size());
        for (int i = 0; i < sortedLevel.size(); ++i) {
            valToIndMap.emplace(sortedLevel[i], i);
        }
        // Memory consumption at this point:
        // currentLevel + sortedLevel + map = 3n

        // O(n)
        for (int i = 0; i < currentLevel.size(); ++i) {
            while (valToIndMap[currentLevelVals[i]] != i) {
                int j = valToIndMap[currentLevelVals[i]];
                std::swap(currentLevelVals[i], currentLevelVals[j]);
                ++numberOfOperations;
            }
        }

        return numberOfOperations;
    }
};