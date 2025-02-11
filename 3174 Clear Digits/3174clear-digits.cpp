class Solution {
public:
    string clearDigits(string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                s[i] = '\0';
                while (i >= 0 && (isdigit(s[i]) || !isalpha(s[i]))) {
                    --i;
                }

                if (i >= 0 && isalpha(s[i])) {
                    s[i] = '\0';
                } else {
                    break;
                }
            }
        }

        s.erase(std::remove(s.begin(), s.end(), '\0'), s.end());

        return s;
    }
};