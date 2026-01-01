#define ST_L(X) static_cast<long>(X)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::vector<long> numsLong(nums.begin(), nums.end());
        std::sort(numsLong.begin(), numsLong.end());

        int realSize = numsLong.size();
        int currentNumberOfOperations = 0;
        int numberOfOperations = 0;

        while (realSize > 0) {
            int currentIndex = 0, insertionIndex = 0;
            while (realSize >= 2 && numsLong[currentIndex] < k) {
                int first = numsLong[currentIndex];
                int second = numsLong[currentIndex + 1];
                numsLong[insertionIndex] = 2L*ST_L(first) + ST_L(second);

                currentIndex += 2;
                realSize -= 2;
                ++insertionIndex; 
                ++currentNumberOfOperations;
            }
            realSize = currentNumberOfOperations;
            numberOfOperations += currentNumberOfOperations;
        }

        return numberOfOperations;
    }
};