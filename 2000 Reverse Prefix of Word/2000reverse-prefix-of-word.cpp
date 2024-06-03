class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0;
        for (index; index < word.size(); ++index) {
            if (word[index] == ch) {
                break;
            }
        }

        if (index == word.size()) {
            return word;
        }

        for (int i = 0; i <= index / 2; ++i) {
            int mirrorPosition = index - i;
            char cache = word[mirrorPosition];
            word[mirrorPosition] = word[i];
            word[i] = cache;
        }

        return word;
    }
};