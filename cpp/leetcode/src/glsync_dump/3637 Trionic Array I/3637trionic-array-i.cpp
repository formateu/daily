class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int score = 0, state = 1;
        if (nums[0] >= nums[1]) return false;

        for (int i = 2; i < nums.size(); ++i) {
            if (score > 2) return false;
            if (state == 1 && nums[i-1] > nums[i]) {
                ++score;
                state = -1;
            } else if (state == -1 && nums[i-1] < nums[i]) {
                ++score;
                state = 1;
            } else if (nums[i] == nums[i-1]) {
                return false;
            }
        }

        return score == 2;
    }
};