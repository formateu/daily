class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCnt = 0, closeCnt = 0, counter = 0;
        for (const auto &c: s) {
            if (c == '(') {
                ++openCnt;
                ++counter;
            } else if (c == ')') {
                if (openCnt) {
                    --openCnt;
                    --counter;
                } else {
                    ++closeCnt;
                    ++counter;
                }
            }
        }

        return counter;
    }
};