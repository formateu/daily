class Solution {
public:
    int maxScore(string s) {
        int tailScore = std::count_if(std::next(s.begin()), s.end(), [](const auto &c) {return c == '1';});
        int headScore = s[0] == '0';
        int max = headScore + tailScore;
        for (int i = 1; i < s.size() -1; ++i) {
            const auto &curr = s[i];
            if (curr == '1') {
                --tailScore;
                continue;
            } else {
                ++headScore;
                if (const int currMax = headScore + tailScore; max < currMax) {
                    max = currMax;
                }
            }
        }

        return max;
    }
private:
};