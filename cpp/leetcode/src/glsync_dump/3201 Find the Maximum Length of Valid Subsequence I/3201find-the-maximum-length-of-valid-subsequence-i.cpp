class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int maxOdd = 0, maxEven = 0, pureOdd = 0, pureEven = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int oldOdd = maxOdd, oldEven = maxEven;
            if (nums[i] % 2) {
                maxOdd = oldEven + 1;
                ++pureOdd;
            } else {
                maxEven = oldOdd + 1;
                ++pureEven;
            }
        }

        return std::max({maxOdd, maxEven, pureOdd, pureEven});
    }
};