class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3) {
            return s;
        }
        const int N = s.size();
        std::string result;
        result.reserve(s.size());
        result.push_back(s[0]);
        result.push_back(s[1]);
        for (int i = 2; i < N; ++i) {
            if (s[i] == s[i-1] && s[i-1] == s[i-2]) {
                continue;
            }

            result.push_back(s[i]);
        }

        return result;
    }
};