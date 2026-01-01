class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 0, sign = 0, currentLength = 0;
        for (int i = 0, j = 1; j < nums.size(); ++i, ++j) {
            if (nums[i] < nums[j]) {
                processStep(sign, currentLength, maxLength, 1);
            } else if (nums[i] > nums[j]) {
                processStep(sign, currentLength, maxLength, -1);
            } else {
                maxLength = std::max(maxLength, currentLength);
                currentLength = 0;
                sign = 0;
            }
        }

        return std::max({maxLength, currentLength, 1});
    }

private:
    void processStep(int &sign, int& currentLength, int &maxLength, const int SignValue) {
        if (sign == SignValue) {
            ++currentLength;
        } else if (sign == 0) {
            sign = SignValue;
            currentLength = 2;
        } else {
            maxLength = std::max(maxLength, currentLength);
            currentLength = 2;
            sign = SignValue;
        }
    }
};