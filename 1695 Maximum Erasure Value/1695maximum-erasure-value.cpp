class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int,int> freq;
        freq.reserve(n);

        int l = 0;
        int result = 0;
        int sum = 0;
        
        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            ++freq[nums[r]];
            
            while (freq[nums[r]] > 1) {
                sum -= nums[l];
                freq[nums[l]]--;
                ++l;
            }
            
            result = std::max(result, sum);
        }
        
        return result;
    }
};