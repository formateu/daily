class Solution {
public:
    int maxDifference(string s) {
        std::array<int, 26> freq{};
        int minOdd = 101, maxOdd = 0, minEven = 101, maxEven = 0;
        for (const char c: s) {
            ++freq[c - 'a'];
        }

        for (const int f : freq) {
            if (f == 0) {
                continue;
            }
            if (f % 2 == 0) {
                if (f < minEven) {
                    minEven = f;
                } 
                if (f > maxEven) {
                    maxEven = f;
                }
            } else {
                if (f < minOdd) {
                    minOdd = f;
                }
                if (f > maxOdd) {
                    maxOdd = f;
                }
            }
        }

        return std::max(minOdd - maxEven, maxOdd - minEven);

    }
};