class Solution {
public:
    string clearStars(string s) {
        std::priority_queue<
            std::pair<char, int>, std::vector<std::pair<char, int>>, std::greater<std::pair<char, int>> > pq;
        std::vector<bool> pos(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                pos[i] = true;
                const auto [_, toRemPos] = pq.top();
                pq.pop();
                pos[-toRemPos] = true;
            } else {
                pq.emplace(s[i], -i);
            }
        }

        int resultSize = 0;
        for (int i = 0; i < pos.size(); ++i) {
            if (pos[i] == false) {
                ++resultSize;
            }
        }
        std::string result(resultSize, '\0');

        for (int i = 0, j = 0; i < resultSize; ++i) {
            while (pos[j]) {
                ++j;
            }
            result[i] = s[j++];
        }

        return result; 
    }
};