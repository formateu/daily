class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        std::unordered_set<int> numsSet;
        int result = 0;
        for (int n: nums) {
            if (numsSet.contains(n)) {
                result = n;
                break;
            } else {
                numsSet.emplace(n);
            }
        }

        return result;
    }
};