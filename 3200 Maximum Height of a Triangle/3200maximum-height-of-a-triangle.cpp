class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        // red on top  
        int redI = red;
        int blueI = blue;
        int cnt = 0;
        for (int i = 1; redI >= 0 && blueI >= 0; ++i) {
            if (i %2) {
                redI -= i;
            } else {
                blueI -= i;
            }
            ++cnt;
        }
        --cnt;
        
        int maxCnt = cnt;

        redI = red;
        blueI = blue;
        cnt = 0;
        for (int i = 1; redI >= 0 && blueI >= 0; ++i) {
            if (i %2) {
                blueI -= i;
            } else {
                redI -= i;
            }
            ++cnt;
        }
        --cnt;
        maxCnt = max(cnt, maxCnt);

        return maxCnt;
    }   
};