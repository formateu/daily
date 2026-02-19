#define stc(X) static_cast<long long>(X)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        std::unordered_map<int, int> diffFreq(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            const auto diff = nums[i] - i;
            if (diffFreq.contains(diff)) {
                ++diffFreq[diff];
            } else {
                diffFreq.emplace(diff, 1);
            }
        }

        long long result = 0;
        for (const auto &[k, v] : diffFreq) {
            result += stc(v)*stc(v-1);
        }

        return (nums.size() * (nums.size() - 1) - result)/2;
    }
};