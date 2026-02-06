class Solution {
public:
    int minRemoval(std::vector<int>& nums, int k) {
        const int N = nums.size();
        if (N == 1) return 0;
        std::sort(nums.begin(), nums.end());
        if (nums[N-1] <= static_cast<long long>(nums[0]) * k) return 0;

        int result = std::numeric_limits<int>::max();
        for (int i = 0, j = i; i < N; ++i) {
            while (j < N && nums[j] <= static_cast<long long>(nums[i]) * k) ++j;
            result = std::min(result, i + N - j);
        }

        return result;
    }
};