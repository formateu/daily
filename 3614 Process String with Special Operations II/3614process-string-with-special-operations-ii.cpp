class Solution {
public:
    char processStr(string s, long long k) {
        long long curLen = 0;
        for (char c : s) {
            if (c == '*') {
                curLen = max(0LL, curLen - 1);
            } else if (c == '#') {
                curLen = curLen * 2;
            } else if (c == '%') {
            } else {
                curLen++;
            }
        }
        if (k >= curLen) return '.';

        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == '*') {
                curLen++;
            } else if (c == '#') {
                long long half = curLen / 2;
                if (k >= half) k -= half;
                curLen = half;
            } else if (c == '%') {
                k = curLen - k - 1;
            } else {
                if (k == curLen -1)
                    return c;
                curLen--;
            }
        }
        return '.';
    }
};