class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }

        std::string result;
        for (int i = 0; i < word.size(); ++i) {
            result = std::max(result, word.substr(i, min(word.size() - numFriends + 1, word.size() -i)));
        }

        return result;
    }
};