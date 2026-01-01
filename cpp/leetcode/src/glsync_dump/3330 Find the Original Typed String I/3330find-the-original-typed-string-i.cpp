class Solution {
public:
    int possibleStringCount(string word) {
        int result = 0, reps = 0;
        for (int i = 0; i < word.size();) {
            int j = i + 1;
            while (j < word.size() && word[j] == word[i]) {
                ++j;
            }
            const int rep_len = j - i;
            if (rep_len > 1) {
                ++reps;
                result += rep_len;
            }
            i = j;
        }

        return result - reps + 1;
    }
};