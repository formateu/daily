class Solution {
public:
    int lengthOfLastWord(string s) {
        bool firstWordStart = false;
        short length = 0;
        for (auto rit = s.rbegin(); rit != s.rend(); ++rit) {
            if (*rit == ' ') {
                if (!firstWordStart) {
                    continue;
                }

                break;
            } else {
                firstWordStart = true;
                ++length;
            }
        }

        return length;
    }   
};