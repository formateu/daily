class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int l = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (l != -1) {
                    int length = i - l - 1;
                    if (length < k) return false;
                }
                l = i;
            }
        }

        return true;
    }
};