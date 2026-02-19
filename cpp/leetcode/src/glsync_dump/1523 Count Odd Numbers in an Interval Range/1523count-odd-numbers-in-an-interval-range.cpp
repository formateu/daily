class Solution {
public:
    int countOdds(int low, int high) {
        int a1 = low % 2 == 0 ? low + 1: low;
        int an = high % 2 == 0 ? high - 1 : high;
        int result = (an - a1 + 2) / 2;

        return result;
    }
};