class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        std::unordered_set<int> nums_s(nums.begin(), nums.end());
        while (nums_s.contains(original)) {
            original *= 2;
        }

        return original;
    }
};