class Solution {
public:
    std::string shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts) {
        constexpr int EngLettersSize = 26;
        std::vector<int> shiftArray(s.size(), 0);
        for (const auto &shift: shifts) {
            const auto &beg = shift[0];
            const auto &end = shift[1];
            const auto &direction = shift[2] == 1 ? 1 : -1;

            shiftArray[static_cast<std::vector<int>::size_type>(beg)] += direction;

            if (static_cast<std::vector<int>::size_type>(end + 1) < shiftArray.size()) {
                shiftArray[static_cast<std::vector<int>::size_type>(end + 1)] -= direction;
            }
        }

        for (int i = 0, cumulativeShift; static_cast<std::vector<int>::size_type>(i) < s.size(); ++i) {
            cumulativeShift = (cumulativeShift + shiftArray[static_cast<std::vector<int>::size_type>(i)]) % EngLettersSize;

            if (cumulativeShift < 0) {
                cumulativeShift += EngLettersSize;
            }

            s[static_cast<std::vector<int>::size_type>(i)] = 'a' + (s[static_cast<std::vector<int>::size_type>(i)] - 'a' + cumulativeShift) % EngLettersSize;
        }

        return s;
    }
};