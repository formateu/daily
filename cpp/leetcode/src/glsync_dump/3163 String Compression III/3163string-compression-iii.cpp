class Solution {
public:
    string compressedString(string word) {
        std::string result;
        result.reserve(word.length());

        char currentLetter = word[0];
        int counter = 1;
        constexpr int MAX_CNT = 9;
        for (int i = 1; i < word.length(); ++i) {
            if (word[i] == currentLetter && counter < MAX_CNT) {
                ++counter;
            } else {
                result += std::string{static_cast<char>(counter + 48), currentLetter};
                counter = 1;
                currentLetter = word[i];
            }
        }

        result += std::string{static_cast<char>(counter + 48), currentLetter};

        return result;
    }
};