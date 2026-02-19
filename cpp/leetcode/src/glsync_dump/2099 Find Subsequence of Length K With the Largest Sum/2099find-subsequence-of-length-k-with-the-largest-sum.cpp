class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        std::vector<std::pair<int, int>> numPos(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            numPos[i] = {nums[i], i};
        }

        std::sort(numPos.begin(), numPos.end());
        std::sort(numPos.end() - k, numPos.end(), [](const auto &p1, const auto &p2) {
            return p1.second < p2.second;
        });

        std::vector<int> result(k);

        for (int i = 0; i < k; ++i) {
            result[i] = numPos[numPos.size() - k + i].first;
        }

        return result;
    }
};