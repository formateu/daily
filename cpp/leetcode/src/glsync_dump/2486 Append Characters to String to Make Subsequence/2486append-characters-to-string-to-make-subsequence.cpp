class Solution {
public:
    int appendCharacters(string s, string t) {
        int maxMatch = 0, posT = 0;
        for (int posS = 0; posS < s.size() && posT < t.size(); ++posS) {
            if (s[posS] == t[posT]) {
                ++posT;
            } else if (posT != 0 && s[posS] == t[0]) {
                maxMatch = max(maxMatch, posT);
            }
        }

        maxMatch = max(maxMatch, posT);

        return t.size() - maxMatch;
    }
};