class Solution {
public:
    int maxDepth(string s) {
        short max = 0, curr = 0;

        for (const auto& c: s) {
            if (c == '(') {
                ++curr;
                if (curr > max) {
                    max = curr;
                }
            } else if (c == ')') {
                --curr;
            }
        }

        return max;
    }
};