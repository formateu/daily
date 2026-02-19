class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1'000'000'007;
        long long result = 0;
        long long len = 0;

        for (char c : s) {
            if (c == '1') {
                ++len;
            } else if (len > 0) {
                result = (result + len * (len + 1) / 2) % MOD;
                len = 0;
            }
        }

        if (len > 0) {
            result = (result + len * (len + 1) / 2) % MOD;
        }

        return static_cast<int>(result % MOD);
    }
};