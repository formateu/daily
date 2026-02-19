#include <vector>

class Solution {
public:
    string makeGood(string s) {
        vector<char> stack;
        stack.reserve(s.size());

        for (short i = 0; i < s.size(); ++i) {
            if (stack.empty() || !this->validate(s[i], stack.back())) {
                stack.push_back(s[i]);
            } else {
                stack.pop_back();
                continue;
            }
        }

        string result(stack.begin(), stack.end());

        return result;
    }

    bool validate(char a, char b) {
        if (a < 97 && b == (a + 32)) {
            return true;
        } else if (a >= 97 && b == (a - 32)) {
            return true;
        } else return false;
    }
};