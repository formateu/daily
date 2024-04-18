class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cO = 0, cC = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == '(') {
                ++cO;
            }

            if (s[i] == ')') {
                if (cC == cO) {
                    s.erase(i, 1);
                    continue;
                }
                ++cC;
            }

            ++i;
        }

        cO = 0; cC = 0;
        for (int i = s.size() - 1; i >= 0;) {
            if (s[i] == ')') {
                ++cO;
            }

            if (s[i] == '(') {
                if (cC == cO) {
                    s.erase(i, 1);
                    --i;
                    continue;
                }
                ++cC;
            }

            --i;
        }

        return s;
    }
};