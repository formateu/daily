class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // a 1 1
        // *0 aa 2 2
        // 1 aa bb 4 2
        // 0 aabb aabb 8 2
        // *1 aabb aabb bbcc bbcc 16 10
        std::uint64_t currentK = static_cast<std::uint64_t>(k);

        int lastOperation = 0;
        std::uint64_t size = 1;
        for (int i = 0; i < operations.size() && size < currentK; ++i) {
            size *= 2;
            ++lastOperation;
        }

        --lastOperation;
        std::int64_t operationsToApply = 0;
        for (int i = lastOperation; i >= 0; --i) {
            if (currentK > (size / 2)) { 
                if (operations[i] == 1) {
                    ++operationsToApply;
                }
                currentK -= (size / 2);
            }
            size /= 2;       
        }

        char result = 'a';
        result += (operationsToApply % 26);

        return result;
        // a
        // ab
        // abab
    }
};