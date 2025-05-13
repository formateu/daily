class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        constexpr int M = 1'000'000'007;
        std::array<int, 26> freq1{}, freq2{};
        for (auto c: s) {
            ++freq1[c - 97];
        }

        for (int i = 0; i < t; ++i) {
            freq2[0] = freq1[25];
            freq2[1] = (freq1[0] + freq1[25]) % M;
            for (int i = 2; i < freq1.size(); ++i) {
                freq2[i] = freq1[i-1];
            }

            std::memcpy(
                freq1.data(),
                freq2.data(),
                freq1.size() * sizeof(int)
            );           
            freq2.fill(0);
        }

        int sum = 0;
        for (int i = 0; i < 26; ++i) {
            sum = (sum + freq1[i]) % M;
        }

        return sum;
    }
};