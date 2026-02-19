class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k == s.length()) {
            return true;
        }

        if (k > s.length()) {
            return false;
        }

        constexpr int CharOffset = 97;
        constexpr int AlphabetSize = 26;
        std::array<int, AlphabetSize> freq{};
        for (const auto &c: s) {
            ++freq[static_cast<int>(c) - CharOffset];
        }

        const int oddCnt = std::count_if(begin(freq), end(freq), [](const auto& cnt) {return cnt %2 == 1;});

        if (oddCnt <= k) {
            return true;
        }

        return false;
    }
};