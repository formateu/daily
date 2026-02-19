class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::bitset<101> present;
    
        bool hasLessThanK = false;
        for (int i = 0; i < nums.size(); ++i) {

            if (nums[i] < k) {
                hasLessThanK = true;
            }

            if (!present[nums[i]]) {
                present.set(nums[i]);
            }
        }

        if (hasLessThanK) {
            return -1;
        }

        int counter = 0;
        for (int i = k+1; i < present.size(); ++i) {
            if (present[i]) {
                ++counter;
            }
        }

        return counter;        
    }
};