class Solution {
public:
    int minimumLength(string s) {
        constexpr int aOffset = 97;
        std::array<int, 26> freqs{};

        for (int i = 0; i < s.size(); ++i) {
            ++freqs[s[i] - aOffset];
        }

        int result = 0;
        for (int i = 0; i < freqs.size(); ++i) {
            if (freqs[i] == 0) continue;
            if (freqs[i] % 2 == 1) {
                ++result;
            } else {
                result += 2;
            }
        }

        return result;
    }
};