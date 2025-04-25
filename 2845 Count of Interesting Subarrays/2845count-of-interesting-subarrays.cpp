class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        std::vector<int> prefixSum(nums.size(), 0);
        prefixSum[0] = static_cast<int>((nums[0] % modulo) == k);
        for (int i = 1; i < nums.size(); ++i) {
            prefixSum[i] = prefixSum[i-1];
            if ((nums[i] % modulo) == k) {
                ++prefixSum[i];
            }
        }

        long long result = 0;
        std::unordered_map<int, int> freq;
        freq[0] = 1;

        for (int j = 0; j < prefixSum.size(); ++j) {
            int rj = prefixSum[j] % modulo;
            int want = (rj -k + modulo) % modulo;
            result += freq[want];
            ++freq[rj];
        }

        return result;
    }
};