class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence[0] == sentence.back()) {
            for (int i = 0; i < sentence.size(); ++i) {
                if (sentence[i] == ' ') {
                    char prev = sentence[i-1];
                    char next = sentence[i+1];

                    if (prev != next) {
                        return false;
                    }
                }
            }
            return true;
        }
        return false;
    }
};