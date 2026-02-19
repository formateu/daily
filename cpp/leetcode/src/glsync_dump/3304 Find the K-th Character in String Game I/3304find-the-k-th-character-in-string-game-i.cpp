class Solution {
public:
    char kthCharacter(int k) {
        int maxSize = 1;
        while (maxSize < k) {
            maxSize *= 2;
        }

        long long size = 1;
        std::string result(maxSize, 'a');
        for (int size = 1; size < k; size *= 2) {
            for (int j = size; j < result.size(); ++j) {
                result[j] = result[j-size] + 1;
            }
        }

        return result[k-1];
    }
};