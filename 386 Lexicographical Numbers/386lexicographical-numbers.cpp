class Solution {
public:
    vector<int> lexicalOrder(int n) {
        std::vector<int> result(n, 1);

        for (int i = 1; i < result.size(); ++i) {
            if (result[i-1]*10 <= n) {
                result[i] = result[i-1]*10;
            } else if (result[i-1] % 10 != 9 && result[i-1] + 1 <= n) {
                result[i] = result[i-1] + 1;
            } else {
                int cur = result[i-1];
                while (cur % 10 == 9 || cur + 1 > n) {
                    cur /= 10;
                }
                ++cur;
                result[i] = cur;
            }
        }

        return result;
    }
};