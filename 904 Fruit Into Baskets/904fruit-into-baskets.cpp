class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        const int n = fruits.size();
        if (n == 0) return 0;

        int l = 0, res = 0;
        int p1 = 0, p2 = -1;

        for (int r = 0; r < n; ++r) {
            if (fruits[r] == fruits[p1]) {
                p1 = r;
            } else if (p2 != -1 && fruits[r] == fruits[p2]) {
                p2 = r;
            } else if (p2 == -1) {
                p2 = r; 
            } else {
                if (p1 < p2) {
                    l = p1 + 1;
                    p1 = r;
                } else {
                    l = p2 + 1;
                    p2 = r;
                }
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};