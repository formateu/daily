class Solution {
public:
    long long distributeCandies(int n, int limit) {
        return (C(n+2) - 3*C(n - limit + 1) + 3*C(n - 2*limit) - C(n - 3*limit - 1)) / 2;
    }

private:
    long long C(int x) {
        if (x < 2) {
            return 0;
        }
        
        return static_cast<long long>(x) * (x-1);
    }
};