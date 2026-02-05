class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int N = nums.size();
        std::vector<int> result(N, 0);

        for (int i = 0; i < N; ++i) {
            if (nums[i] > 0) {
                result[i] = nums[(i+nums[i]) % N];
            } else if (nums[i] < 0) {
                int index = i + nums[i] % N;
                if (index < 0) index = N + index;
                result[i] = nums[index];
            } else {
                result[i] = nums[i];
            }
        }

        return result;
    }
};