class Solution {
public:
    int minimumDeletions(string s) {
        const int N = s.size();
        std::vector<int> suf_a(N, 0), pref_b(N, 0);

        for (int i = N-2; i >= 0; --i) {
            suf_a[i] = suf_a[i+1];
            if (s[i+1] == 'a') ++suf_a[i];
        }

        for (int i = 1; i < N; ++i) {
            pref_b[i] = pref_b[i-1];
            if (s[i-1] == 'b') ++pref_b[i];
        }

        int result = std::numeric_limits<int>::max();

        for (int i = 0; i < N; ++i) {
            result = std::min(result, suf_a[i] + pref_b[i]);
        }

        return result;
    }
};