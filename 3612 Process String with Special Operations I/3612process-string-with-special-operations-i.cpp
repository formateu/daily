class Solution {
public:
    string processStr(string s) {
        std::string result;
        result.reserve(s.size());
        // int lcp = -1;
        for (char c: s) {
            if (c == '*') {
                if (!result.empty()) result.pop_back();
            } else if (c == '#') {
                result.append(result);
            } else if (c == '%') {
                std::reverse(result.begin(), result.end());
            } else {
                result.push_back(c);
            }
        }

        return result;
    }
};