#include <vector>
#include <string>
#include <array>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> wordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2) {
        constexpr int EngAlphSize = 26;
        std::array<int, EngAlphSize> words2Hist{}, cache{};
        for (const auto &w : words2) {
            for (const auto &c: w) {
                ++cache[static_cast<std::array<int, EngAlphSize>::size_type>(c - 'a')];
            }

            for (std::size_t i = 0; i < cache.size(); ++i) {
                words2Hist[i] = std::max(words2Hist[i], cache[i]);
            }
            cache.fill(0);
        }

        const auto nonZeroCount = std::count_if(words2Hist.begin(), words2Hist.end(), 
                                     [](int value) { return value != 0; });


        std::vector<std::string> result;
        for (const auto &w: words1) {
            for (const auto &c: w) {
                ++cache[static_cast<std::array<int, EngAlphSize>::size_type>(c - 'a')];
            }

            int counter = 0;
            for (int c = 'a'; c <= 'z'; ++c) {
                const auto &val = cache[static_cast<std::array<int, EngAlphSize>::size_type>(c - 'a')];
                const auto &h = words2Hist[static_cast<std::array<int, EngAlphSize>::size_type>(c - 'a')];
                if (h == 0 || val == 0) {
                    continue;
                }

                if (val < h ) {
                    break;
                }

                ++counter;
            }

            if (counter == nonZeroCount) {
                result.emplace_back(w);
            }
            cache.fill(0);
        }

        return result;
    }
};