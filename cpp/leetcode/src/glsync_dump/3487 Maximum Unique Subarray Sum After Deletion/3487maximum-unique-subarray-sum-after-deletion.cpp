class Solution {
public:
    int maxSum(vector<int>& nums) {
        int nc = 0;
        for (const auto &i : nums) {
            if (i < 0) ++nc;
        }
        
        if (nc == nums.size()) {
            return *std::max_element(nums.begin(), nums.end());
        }

        int sum = 0;
        std::unordered_set<int> s;
        for (const auto &i : nums) {
            if (!s.contains(i) && sum + i > sum) {
                sum += i;
                s.emplace(i);
            }
        }

        return sum;
    }
};