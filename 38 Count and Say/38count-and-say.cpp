class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return std::to_string(n);
        }

        auto result = init();
        for (int i = 1; i < n-1; ++i) {
            const auto seq = sequenceToFreqNumPairs(result);
            result = freqNumPairsToSequence(seq);
        }

        return result;
    }

    std::vector<std::pair<int, int>> sequenceToFreqNumPairs(const std::string &seq) {
        std::vector<std::pair<int, int>> result;

        int freq = 0;
        for (int i = 0; i < seq.size();) {
            char current = seq[i];
            while (seq[i] == current) {
                ++i;
                ++freq;
            }

            result.emplace_back(freq, static_cast<int>(current - '0'));
            freq = 0;
        }

        return result;
    }

    std::string freqNumPairsToSequence(const std::vector<std::pair<int, int>> &freqNumPairs) {
        std::string sequence;

        for (int i = 0; i < freqNumPairs.size(); ++i) {
            sequence.push_back(static_cast<char>(freqNumPairs[i].first + '0'));
            sequence.push_back(static_cast<char>(freqNumPairs[i].second + '0'));
        }

        return sequence;
    }

    std::string init() {
        return "11";
    }
};