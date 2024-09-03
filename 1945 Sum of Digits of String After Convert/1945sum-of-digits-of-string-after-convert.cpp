class Solution {
public:
    int getLucky(string s, int k) {
        while (k > 0) {
            s = getLuckyImpl(s);
            --k;
        }

        return stoi(s);
    }
protected:
    string getLuckyImpl(string s) {
        std::vector<int> nums(s.size());

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] > 96) {
                nums[i] = static_cast<int>(s[i]) - 96;
            } else {
                nums[i] = static_cast<int>(s[i]) - 48;
            }
        }

        int sum = 0;
        for (const auto &n : nums) {
            if (n > 9) {
                sum += n / 10;
                sum += n % 10;
            } else {
                sum += n;
            }
        }

        return std::to_string(sum);
    }
};