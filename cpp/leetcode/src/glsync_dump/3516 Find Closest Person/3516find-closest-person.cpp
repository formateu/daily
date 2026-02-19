class Solution {
public:
    int findClosest(int x, int y, int z) {
        int mod1 = std::abs(x - z);
        int mod2 = std::abs(y - z);
        if (mod1 == mod2) return 0;

        return mod1 < mod2 ? 1 : 2;
    }
};