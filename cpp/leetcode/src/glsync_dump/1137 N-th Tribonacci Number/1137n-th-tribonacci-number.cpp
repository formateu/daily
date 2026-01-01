class Solution {
public:
    int tribonacci(int n) {

        switch (n) {
            case 0:
                return 0;
            case 1:
            case 2:
                return 1;
            default:
                break;
        }
        
        std::vector<std::int32_t> cache(n+1);
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 1;

        for (std::int8_t i = 3; i < cache.size(); ++i) {
            cache[i] = cache[i-1] + cache[i-2] + cache[i-3];
        }

        return cache[n];
    }
};