class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
        int l = 0, r = letters.size();
        char result = letters[l];
        if (letters[r-1] < target) return result;
        
        while (l < r) {
            int pivot = (l + r) / 2;
            if (letters[pivot] > target) {
                if (result > letters[pivot] || result <= target) result = letters[pivot];
                r = pivot;
            } else {
                l = pivot + 1;
            }
        }

        return result;
    }
};