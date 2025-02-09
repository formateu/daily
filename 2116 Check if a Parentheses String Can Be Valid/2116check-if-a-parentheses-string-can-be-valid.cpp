class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 == 1) {
            return false;
        }

        int l = 0, b = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' && locked[i] == '1') {
                ++l;
            } else if (s[i] == ')' && locked[i] == '1') {
                if (l != 0) {
                    --l;
                } else if (b != 0) {
                    --b;
                } else {
                    return false;
                }
            } else {
                ++b;
            }
        }

        int balance = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                balance--;
                b--;
            } else if (s[i] == '(') {
                balance++;
                l--;
            } else if (s[i] == ')') {
                balance--;
            }
            if (balance > 0) {
                return false;
            }
        }

        if (l > 0) {
            return false;
        }

        return true;
    }
};