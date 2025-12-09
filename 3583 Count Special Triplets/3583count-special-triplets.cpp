class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        constexpr int MOD = 1'000'000'007;
        std::unordered_map<int, int> prev, next;
        prev.emplace(nums[0], 1);

        for (int i = 1; i < nums.size(); ++i) {
            auto [it, inserted] = next.try_emplace(nums[i], 1);
            if (!inserted) {
                ++it->second;
            }
        }
        
        int result = 0;
        for (int i = 1; i < nums.size(); ++i) {
            const auto curr = nums[i];
            const auto curr2 = 2*curr;

            if (auto it = next.find(curr); it != next.end()) {
                if (--it->second == 0) {
                    next.erase(it);
                }
            }
            
            if (prev.contains(curr2) && next.contains(curr2)) {
                long long p = prev[curr2];
                long long n = next[curr2];
                result = (result + (p*n) % MOD) % MOD;
            }

            auto [it, inserted] = prev.try_emplace(nums[i], 1);
            if (!inserted) {
                ++it->second;
            }
        }

        return result;
    }
};