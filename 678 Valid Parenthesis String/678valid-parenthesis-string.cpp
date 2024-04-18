class Solution {
public:
  bool checkValidString(string s) {
    int cO = 0, cC = 0;
    for (const auto &l : s) {
        if (l == '(' || l == '*') {
            ++cO;
        } else if (l == ')') {
            if (!cO) {
                return false;
            } else {
                --cO;
            }
        }
    }

    for (int i = s.size()-1; i >= 0; --i) {
        if (s[i] == ')' || s[i] == '*') {
            ++cC;
        } else if (s[i] == '(') {
            if (!cC) {
                return false;
            } else {
                --cC;
            }
        }
    }

    return true;
  }
};