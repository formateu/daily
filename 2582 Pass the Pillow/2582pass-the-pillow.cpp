class Solution {
public:
    int passThePillow(int n, int time) {
        if (time < n) {
            return time + 1;
        }

        int result = (time % (n-1));
        if (time / (n-1) % 2) {
            return n - result;
        } else {
            return result + 1;
        }
    }
};