class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int dir = 0, result = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] < nums[i]) {
                if (dir == -1) ++result;
                dir = 1;
            } else if (nums[i-1] > nums[i]) {
                if (dir == 1) ++result;
                dir = -1;
            }
        }

        return result;
    }
};