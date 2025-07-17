class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        int curr = 0;
        for (int i  = 0; i < N; ++i) {
            int new_curr = i + nums[i];
            if (curr >= i) {
                curr = std::max(curr, new_curr);
            }
        }

        return curr >= (N-1);
    }
};