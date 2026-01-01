class Solution {
public:
    int minDeletionSize(const std::vector<std::string>& strs) {

        int result = 0;
        for (std::size_t i = 0; i < strs[0].size(); ++i) {
            for (std::size_t prev = 0, curr = 1; curr < strs.size(); ++curr, ++prev) {
                if (strs[prev][i] > strs[curr][i]) {
                    ++result;
                    break;
                }
            }
        }

        return result;
    }
};