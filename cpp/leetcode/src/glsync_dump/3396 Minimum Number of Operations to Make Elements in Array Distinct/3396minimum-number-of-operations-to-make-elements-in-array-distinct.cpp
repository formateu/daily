class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        std::unordered_set<int> uniqueSet;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (uniqueSet.contains(nums[i])) {
                return std::ceil((i+1)/3.0);
            } else {
                uniqueSet.emplace(nums[i]);
            }
        }

        return 0;
    }
};