class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        int mismatchPos1 = -1, mismatchPos2 = -1;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) {
                continue;
            } else if (mismatchPos1 == -1) {
                mismatchPos1 = i;
            } else if (mismatchPos2 == -1){
                mismatchPos2 = i;
            } else {
                return false;
            }
        }

        if (mismatchPos2 != -1 && mismatchPos2 != -1) {
            std::swap(s1[mismatchPos1], s1[mismatchPos2]);
            return s1 == s2;
        } else if (mismatchPos1 != -1 || mismatchPos2 != -1) {
            return false;
        }

        return true;
    }
};