#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const auto sm = this->stringToMap(s);
        const auto tm = this->stringToMap(t);
        std::unordered_map<char, char> charMap(sm.size());

        if (sm.size() != tm.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (!charMap.contains(s[i])) {
                if (sm.at(s[i]) != tm.at(t[i])) {
                    return false;
                }

                charMap.emplace(s[i], t[i]);
            } else {
                if (sm.at(s[i]) != tm.at(charMap.at(s[i])) || charMap.at(s[i]) != t[i]) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    std::unordered_map<char, int> stringToMap(const std::string &s) {
        std::unordered_map<char, int> sm;
        for (const auto &c: s) {
            if (sm.contains(c)) {
                ++sm[c];
            } else {
                sm[c] = 1;
            }
        }

        return sm;
    }
};