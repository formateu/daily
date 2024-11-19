class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        std::unordered_map<int, int> elems;
        elems.reserve(k);
        long long currentSum = accumulate(nums.begin(), std::next(nums.begin(), k), 0LL);
        int duplicationCounter = 0;
        for (int i = 0; i < k; ++i) {
            if (elems.contains(nums[i])) {
                ++duplicationCounter;
                ++elems[nums[i]];
                continue;
            }

            elems.emplace(nums[i], 1);
        }

        if (!duplicationCounter) {
            maxSum = currentSum;
        }

        for (int i = 1, j = i+k-1; j < nums.size(); ++i, ++j) {
            currentSum += nums[j] - nums[i-1];
            if (nums[i-1] != nums[j]) {
                if (elems[nums[i-1]] == 1) {
                    elems.erase(nums[i-1]);
                } else {
                    --elems[nums[i-1]];
                    --duplicationCounter;
                }
                if (!elems.contains(nums[j])) {
                    elems.emplace(nums[j], 1);
                } else {
                    ++elems[nums[j]];
                    ++duplicationCounter;
                }
            }

            if (!duplicationCounter) {
                maxSum = std::max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};