class Solution {
public:
    int countTriples(int n) {
        int result = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                if (int c = a*a + b*b, cq = sqrt(c); cq*cq == c && cq <= n) {
                    ++result;
                }
            }
        }

        return result;
    }
};