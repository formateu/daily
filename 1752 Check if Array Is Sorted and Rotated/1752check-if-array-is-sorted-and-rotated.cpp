class Solution {
public:
    bool check(vector<int>& nums) {
        int drops = 0, N = nums.size();
        for (int i = 0; i < N; ++i) {
            int j = (i + 1) % N;
            if (nums[i] > nums[j]) {
                if (++drops > 1) return false;
            }
        }
        return true;
    }
};