class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.back() != 9) {
            ++digits.back();
            return digits;
        }

        int i = digits.size() - 1;
        for (; i >= 0 && digits[i] == 9; --i) {
            digits[i] = 0;
        }

        if (i == -1) {
            int carry = 1;
            for (i = 0; i < digits.size(); ++i) {
                std::swap(digits[i], carry);
            }

            digits.emplace_back(carry);
        } else {
            ++digits[i]; 
        }

        return digits;
    }
};